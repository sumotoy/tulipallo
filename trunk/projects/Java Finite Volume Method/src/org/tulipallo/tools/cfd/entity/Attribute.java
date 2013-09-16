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

import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import javax.xml.bind.annotation.XmlRootElement;

/**
 * An <tt>Attribute</tt> is a valueOf of a <tt>Entity</tt>.  Attributes are
 * strongly typed as defined by {@link #type} for this <tt>Attribute</tt>.
 * <p/>
 * Attributes can be nullable, read-only, fire vetoable events when changed and
 * can have default values.  An attribute may also have a custom
 * <tt>Validator</tt> to ensure correctness of values at run-time.
 * <p/>
 * The {@link Entity} object uses <tt>Attribute</tt> to define values a
 * <tt>Entity</tt> can have.
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
 * @see Entity
 */
@XmlRootElement
public class Attribute {
    private String         name;
    private String         description;
    private Type           type;
    private boolean        readOnly;
    private boolean        nullable;
    private boolean        vetoable;
    private Object         defaultValue;
    private Set<Validator> validators = new HashSet();

    private final Object validatorMutex = new Object();

    /**
     * Creates a new <tt>Attribute</tt> named <tt>name</tt> of type
     * <tt>type</tt>.
     *
     * @param name The name of this <tt>Attribute</tt>.  This valueOf should be
     *             &quot;human-friendly&quot; as it is visible during run-time
     *             and often required the end user to manipulate or consume.
     * @param type The data types for this <tt>Attribute</tt>.
     *
     * @throws IllegalArgumentException if <tt>name</tt> or </tt>type</tt> are
     *                                  <tt>null</tt> or <tt>name</tt> is zero
     *                                  length.
     */
    public Attribute(final String name, final Type type) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"name\" cannot be null or 0 length.");
        if(type == null)
            throw new IllegalArgumentException(
                    "Argument \"type\" cannot be null.");
        this.name = name;
        this.type = type;
    }

    /**
     * Creates a new <tt>Attribute</tt> named <tt>name</tt> of type
     * <tt>type</tt>.
     *
     * @param name        The name of this <tt>Attribute</tt>.  This valueOf
     *                    should be &quot;human-friendly&quot; as it is visible
     *                    during run-time and often required the end user to
     *                    manipulate or consume.
     * @param type        The data types for this <tt>Attribute</tt>.
     * @param description The description for this <tt>Attribute</tt>.
     *
     * @throws IllegalArgumentException if <tt>name</tt> or </tt>type</tt> are
     *                                  <tt>null</tt> or <tt>name</tt> is zero
     *                                  length.
     */
    public Attribute(final String name, final Type type,
                     final String description) {
        this(name, type);
        this.description = description;
    }

    /**
     * Creates a new <tt>Attribute</tt> named <tt>name</tt> of type
     * <tt>type</tt>.
     *
     * @param name         The name of this <tt>Attribute</tt>.  This valueOf
     *                     should be &quot;human-friendly&quot; as it is visible
     *                     during run-time and often required the end user to
     *                     manipulate or consume.
     * @param type         The data types for this <tt>Attribute</tt>.
     * @param description  The description for this <tt>Attribute</tt>.
     * @param readOnly     <tt>true</tt> if this <tt>Attribute</tt> is
     *                     read-only.
     * @param nullable     <tt>true</tt> if this <tt>Attribute</tt> can accept
     *                     <tt>null</tt> values.
     * @param vetoable     <tt>true</tt> if this attributes changes are
     *                     vetoable. A {@link Entity} will invoke
     *                     {@link Entity#fireVetoableAttributeChangedEvent(org.jfvm.beans.Attribute, java.lang.Object, java.lang.Object)}
     *                     when this <tt>Attribute</tt>s valueOf changes.
     * @param defaultValue The defualt valueOf for this <tt>Attribute</tt>.<br/>
     *                     <b>Note:</b> This constructor DOES NOT validate that
     *                     <tt>defaultValue</tt> is the defined <tt>Type</tt>
     *                     for this <tt>Attribute</tt> nor that it meets the
     *                     above criteria.
     */
    public Attribute(final String name, final Type type,
                     final String description, final boolean readOnly,
                     final boolean nullable, final boolean vetoable,
                     final Object defaultValue) {
        this(name, type, description);
        this.readOnly     = readOnly;  
        this.defaultValue = defaultValue;
        this.nullable     = nullable;
        this.vetoable     = vetoable;
    }

    /**
     *
     * @param name         The name of this <tt>Attribute</tt>.  This valueOf
     *                     should be &quot;human-friendly&quot; as it is visible
     *                     during run-time and often required the end user to
     *                     manipulate or consume.
     * @param type         The data types for this <tt>Attribute</tt>.
     * @param description  The description for this <tt>Attribute</tt>.
     * @param readOnly     <tt>true</tt> if this <tt>Attribute</tt> is
     *                     read-only.
     * @param nullable     <tt>true</tt> if this <tt>Attribute</tt> can accept
     *                     <tt>null</tt> values.
     * @param vetoable     <tt>true</tt> if this attributes changes are
     *                     vetoable. A {@link Entity} will invoke
     *                     {@link Entity#fireVetoableAttributeChangedEvent(org.jfvm.entity.Attribute, java.lang.Object, java.lang.Object)}
     *                     when this <tt>Attribute</tt>s valueOf changes.
     * @param defaultValue The default valueOf for this <tt>Attribute</tt>.<br/>
     *                     <b>Note:</b> This constructor DOES NOT validate that
     *                     <tt>defaultValue</tt> is the defined <tt>Type</tt>
     *                     for this <tt>Attribute</tt> nor that it meets the
     *                     above criteria.
     * @param validator    The custom validators for this attribute.
     */
    public Attribute(final String name, final Type type,
                     final String description, final boolean readOnly,
                     final boolean nullable, final boolean vetoable,
                     final Object defaultValue, 
                     final Set<Validator> validators) {
        this(name, type, description, readOnly, nullable, vetoable,
             defaultValue);
        if(validators == null)
            throw new IllegalArgumentException(
                    "Argument \"validators\" cannot be null.");
        this.validators.addAll(validators);
    }

    public String getName() {
        return this.name;
    }

    public String getDescription() {
        return this.description;
    }

    public Type getType() {
        return this.type;
    }

    public boolean isReadOnly() {
        return this.readOnly;
    }

    public boolean isNullable() {
        return this.nullable;
    }

    public boolean isVetoable() {
        return this.vetoable;
    }

    public Object getDefaultValue() {
        return this.defaultValue;
    }

    public Set<Validator> getValidators() {
        synchronized(this.validatorMutex) {
            return Collections.unmodifiableSet(this.validators);
        }
    }

    /**
     * Adds a custom <tt>Validator</tt> to this <tt>Attribute</tt>.
     *
     * @param validator The customer <tt>Validator</tt> for this
     *                  <tt>Attribute</tt>.
     */
    public void addValidator(final Validator validator) {
        if(validator == null)
            throw new IllegalArgumentException(
                    "Argument \"validator\" cannot be null.");
        synchronized(this.validatorMutex) {
            this.validators.add(validator);
        }
    }
    
    /**
     * Removes a custom <tt>Validator</tt> from this <tt>Attribute</tt>.
     *
     * @param validator The customer <tt>Validator</tt> for this
     *                  <tt>Attribute</tt>.
     */
    public void removeValidator(final Validator validator) {
        synchronized(this.validatorMutex) {
            this.validators.remove(validator);
        }
    }

    /**
     * Validates a valueOf for this <tt>Attribute</tt>.  The following steps are
     * taken to ensure argument <tt>valueOf</tt> meets the requirements of this
     * <tt>Attribute</tt>:
     *
     * <ul>
     *     <li>Validates this attribute is not read-only</li>
     *     <li>Validates <tt>valueOf</tt> is not <tt>null</tt> if this
     *     <tt>Attribute</tt> is not nullable</li>
     *     <li>Validates <tt>valueOf</tt> is an instance of the <tt>TypeToDelete</tt>
     *     defined for this <tt>Attribute</tt></li>
     *     <li>If a <tt>Validator</tt> is defined for this <tt>Attribute</tt>,
     *     the {@link Validator#validate(java.lang.Object, java.util.Set)}
     *     method is invoked for argument <tt>value</tt></li>
     * </ul>
     *
     * @param value The value to validate against this <tt>Attribute</tt>.
     *
     * @throws UnmodifiableAttributeException if this attribute is read-only.
     * @throws NullAttributeException if this <tt>Attribute</tt> is not nullable
     *                                and argument <tt>value</tt> was null.
     * @throws InvalidAttributeTypeException if argument <tt>value</tt> is not
     *                                       an instance of the <tt>TypeToDelete</tt>
     *                                       defined for this
     *                                       <tt>Attribute</tt>.
     * @throws ValidationException if there is a custom <tt>Validator</tt>
     *                             specified for this attribute and it returns
     *                             <tt>false</tt>.
     */
    public final void validate(final Object value){
        if(this.readOnly)
                throw new UnmodifiableAttributeException(this.name);
        if(!this.nullable && value == null)
                throw new NullAttributeException(this.name);
        if(value != null) {
            if(!this.type.isInstance(value))
                throw new InvalidAttributeTypeException(
                        this.name, this.type.getDefinition());
            else
                this.executeValidators(value);
        } 
    }
    
    final void executeValidators(final Object value) {
        synchronized(this.validatorMutex) {
            if(!this.validators.isEmpty()) {
                Set<String> messages = new HashSet<String>();
                for(Validator validator : this.validators)
                    if(!validator.validate(value, messages))
                        throw new ValidationException(this.name, messages);
            }
        }
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Attribute other = (Attribute) obj;
        if ((this.name == null) ? (other.name != null) :
            !this.name.equals(other.name)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 97 * hash + (this.name != null ? this.name.hashCode() : 0);
        return hash;
    }
}
