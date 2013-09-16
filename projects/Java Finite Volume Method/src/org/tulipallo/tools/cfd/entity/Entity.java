/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2010 M2 Astronautics
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 *
 */

package org.tulipallo.tools.cfd.entity;

import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlTransient;
import org.tulipallo.tools.cfd.Identifiable;

/**
 * A <tt>Entity</tt> is an object in the Finite Volume Method Solver Simulation.
 * A <tt>Entity</tt> has user defined attributes and manages history for values 
 * of those attributes.  It also emits events when attributes change values.
 * <p/>
 * In most cases, an <tt>Entity</tt> represents a cell, volume, or unit of work 
 * in a finite method simulation.
 * <p/>
 * <tt>Entity</tt> is thread safe.
 * <p/>
 * <tt>Tulipallo - The Java Finite Volume Method Simulation<br />
 * Copyright &copy; 2010 M2 Astronautics</tt>
 * <p/>
 * <tt>This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.</tt>
 * <p/>
 * <tt>You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.</tt>
 *
 * @author Robert R Murrell
 * @since Java 6
 * @version 1.0 beta
 *
 * @see Recorder
 * @see Memento
 * @see Attribute
 */
@XmlRootElement
public abstract class Entity implements Identifiable {
    public  static final int DEFAULT_RECORDED_HISTORIES = 5;
    private static final long serialVersionUID          = 1L;

    private Set<AttributeChangedListener> attributeChangedListeners;
    private Map<String, Attribute>        supported;
    private Map<Attribute, Object>        values;
    private Recorder                      recorder;
    private long                          id;

    private final Object attributeListenerMutex = new Object();
    private final Object attributeMutex         = new Object();
    private final Object recordMutex            = new Object();

    public Entity(final Long id, final int maxRecordedHistories) {
        this(maxRecordedHistories);
        this.setId(id);
    }

    public Entity(final int maxRecordedHistories) {
        this();
        this.recorder = new Recorder(maxRecordedHistories);
    }
    
    public Entity(final Long id) {
        this(id, DEFAULT_RECORDED_HISTORIES);
    }

    public Entity() {
        this.attributeChangedListeners = new HashSet(0);
        this.supported                 = new HashMap();
        this.values                    = new HashMap();
    }

    @Override
    public long getId() {
        return this.id;
    }

    @Override
    public final void setId(final long id) {
        this.id = id;
    }

    /**
     * Allows this <tt>Entity</tt> to support the attribute specified by
     * <tt>attribute</tt>.
     * <p/>
     * Without explicitly supporting an attribute this <tt>Entity</tt> will 
     * throw an {@link AttributeNotSupportedException} if 
     * {@link #getAttribute(org.bouledefeu.jfvm.entity.Attribute) }, 
     * {@link #getAttribute(java.lang.String) },
     * {@link #setAttribute(org.bouledefeu.jfvm.entity.Attribute, java.lang.Object) },
     * {@link #setAttribute(java.lang.String, java.lang.Object) }, or 
     * {@link #setAttribute(org.bouledefeu.jfvm.entity.Attribute, java.lang.Object, java.lang.Object) } 
     * are invoked.
     *
     * @param attribute the attribute for this <tt>Entity</tt> to support.
     *
     * @throws AttributeSupportedException if the <tt>attribute</tt> is already
     *                                     supported.
     */
    @XmlTransient
    public void support(final Attribute attribute) {
        if(attribute == null)
            throw new IllegalArgumentException(
                    "Argument \"attriute\" cannot be null.");
        String name = attribute.getName();
        synchronized(this.attributeMutex) {
            if(!this.supported.containsValue(attribute)) {
                this.supported.put(name, attribute);
                this.values.put(attribute, attribute.getDefaultValue());
            }
            else
                throw new AttributeSupportedException(name);
        }
    }

    @XmlTransient
    public boolean isSupported(final Attribute attribute) {
        synchronized(this.attributeMutex) {
            return this.supported.containsValue(attribute);
        }
    }

    public Collection<Attribute> getAttributes() {
        synchronized(this.attributeMutex) {
            return Collections.unmodifiableCollection(this.supported.values());
        }
    }
    
    public Map<Attribute, Object> getValues() {
        synchronized(this.attributeMutex) {
            return Collections.unmodifiableMap(this.values);
        }
    }

    @XmlTransient
    public boolean setAttribute(final Attribute attribute,
                                final Object newValue) {
        if(attribute == null)
            throw new IllegalArgumentException(
                    "Argument \"attribute\" cannot be null.");
        return this.setAttribute(attribute.getName(), newValue);
    }

    /**
     * 
     * @param name
     * @param newValue
     * 
     * @return <tt>true</tt> if the attribute was set, <tt>false</tt> if not.
     *
     * @throws IllegalArgumentException if argument <tt>name</tt> is
     *                                  <tt>null</tt> or zero length.
     */
    @XmlTransient
    public boolean setAttribute(final String name, final Object newValue) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"name\" cannot be null or 0 length.");
        synchronized(this.attributeMutex) {
            Attribute attribute = this.supported.get(name);
            if(attribute == null)
                throw new AttributeNotSupportedException(name);
            attribute.validate(newValue);
            Object  oldValue = this.values.get(name);
            boolean vetoed = false;
            if(attribute.isVetoable())
                vetoed = this.setVetoableAttribute(attribute, oldValue,
                                                   newValue);
            else
                this.setAttribute(attribute, oldValue, newValue);
            return !vetoed;
        }
    }

    @XmlTransient
    final boolean setVetoableAttribute(final Attribute attribute,
                                       final Object oldValue,
                                       final Object newValue) {
        boolean vetoed = this.fireVetoableAttributeChangedEvent(
                                        attribute, oldValue, newValue);
        if(vetoed)
            this.fireAttributeChangedEvent(attribute, newValue, oldValue);
        else
            this.values.put(attribute, newValue);
        return vetoed;
    }

    @XmlTransient
    final void setAttribute(final Attribute attribute, final Object oldValue,
                            final Object newValue) {
        this.fireAttributeChangedEvent(attribute, oldValue, newValue);
        this.values.put(attribute, newValue);
    }

    @XmlTransient
    public Object getAttribute(final Attribute attribute) {
        if(attribute == null)
            throw new IllegalArgumentException(
                    "Argument \"attribute\" cannot be null.");
        return this.getAttribute(attribute.getName());
    }

    @XmlTransient
    public Object getAttribute(final String name) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"name\" cannot be null or 0 length.");
        synchronized(this.attributeMutex) {
            return this.values.get(name);
        }
    }

    /**
     * Resets all the attributes for this <tt>Entity</tt> to their respective
     * default values.
     */
    @XmlTransient
    public void reset() {
        synchronized(this.recordMutex) {
            synchronized(this.attributeMutex) {
                this.record();
                this.values.clear();
                for(Attribute attribute : this.supported.values())
                    this.values.put(attribute,
                                    attribute.getDefaultValue());
            }
        }
    }

    /**
     * Records a new {@link Memento} of the attributes for this <tt>Entity</tt>
     * and stores them in the <tt>Recorder</tt>s history.
     */
    @XmlTransient
    public void record() {
        synchronized(this.recordMutex) {
            synchronized(this.attributeMutex) {
                this.recorder.record(this.supported, this.values);
            }
        }
    }
    
    /**
     * Restores this entity from a previous history.
     * 
     * @param memento the <tt>Memento</tt> to restore this <tt>Entity</tt>s 
     *                state to.
     * 
     * @throws IllegalArgumentException if <tt>memento</tt> is <tt>null</tt>.
     */
    @XmlTransient
    public void restore(final Memento memento) {
        if(memento == null)
            throw new IllegalArgumentException(
                    "Argument \"memento\" cannot be null.");
        synchronized(this.recordMutex) {
            synchronized(this.attributeMutex) {
                this.values.clear();
                for(Entry<Attribute, Object> entry : 
                        memento.getValues().entrySet()) {
                    this.values.put(entry.getKey(), entry.getValue());
                }
            }
        }
    }

    /**
     * Returns an <tt>Iterator</tt> for the recorded histories of this
     * <tt>Entity</tt>.
     *
     * @return an <tt>Iterator</tt> for the recorded histories of this
     *         <tt>Entity</tt>.
     */
    @XmlTransient
    public Iterator<Memento> iterateRecordedHistories() {
        synchronized(this.recordMutex) {
            return this.recorder.iterator();
        }
    }

    @XmlTransient
    public void addAttributeChangedListener(
                            final AttributeChangedListener listener) {
        if(listener == null)
            throw new IllegalArgumentException(
                    "Argument \"listener\" cannot be null.");
        synchronized(this.attributeListenerMutex) {
            this.attributeChangedListeners.add(listener);
        }
    }

    @XmlTransient
    public void removeAttributeChangedListener(
                            final AttributeChangedListener listener) {
        if(listener != null)
            synchronized(this.attributeListenerMutex) {
                this.attributeChangedListeners.remove(listener);
            }
    }

    protected final void fireAttributeChangedEvent(final Attribute attribute,
                                                   final Object oldValue,
                                                   final Object newValue) {
        AttributeChangedEvent event = new AttributeChangedEvent(this, attribute,
                oldValue, newValue);
        synchronized(this.attributeMutex) {
            synchronized(this.attributeListenerMutex) {
                for(AttributeChangedListener listener :
                        this.attributeChangedListeners)
                    listener.handleAttributeChanged(event);
            }
        }
    }

    protected final boolean fireVetoableAttributeChangedEvent(
                                    final Attribute attribute,
                                    final Object oldValue,
                                    final Object newValue) {
        VetoableAttributeChangedEvent event =
               new VetoableAttributeChangedEvent(this, attribute, oldValue,
                                                 newValue);
        synchronized(this.attributeMutex) {
            synchronized(this.attributeListenerMutex) {
                for(AttributeChangedListener listener :
                        this.attributeChangedListeners) {
                    listener.handleAttributeChanged(event);
                    if(event.isVetoed())
                        break;
                }
            }
        }
        return event.isVetoed();
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 67 * hash + (int) (this.id ^ (this.id >>> 32));
        return hash;
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Entity other = (Entity) obj;
        if (this.id != other.id) {
            return false;
        }
        return true;
    }
}
