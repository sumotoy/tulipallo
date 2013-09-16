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

import org.tulipallo.tools.cfd.Event;

/**
 * Event fired when a {@link Entity} {@link Attribute} value changes.
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
 */
public class AttributeChangedEvent extends Event {
    private final Attribute attribute;
    private final Object    oldValue;
    private final Object    newValue;

    public AttributeChangedEvent(final Object source,
                                 final Attribute attribute,
                                 final Object oldValue,
                                 final Object newValue) {
        super(source);
        if(attribute == null)
            throw new IllegalArgumentException(
                    "Argument \"attribute\" cannot be null.");
        this.attribute = attribute;
        this.oldValue = oldValue;
        this.newValue = newValue;
    }

    public Attribute getAttribute() {
        return this.attribute;
    }

    public Object getNewValue() {
        return this.newValue;
    }

    public Object getOldValue() {
        return this.oldValue;
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final AttributeChangedEvent other = (AttributeChangedEvent) obj;
        if (this.attribute != other.attribute && (this.attribute == null ||
                !this.attribute.equals(other.attribute))) {
            return false;
        }
        if (this.oldValue != other.oldValue && (this.oldValue == null ||
                !this.oldValue.equals(other.oldValue))) {
            return false;
        }
        if (this.newValue != other.newValue && (this.newValue == null ||
                !this.newValue.equals(other.newValue))) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 89 * hash + (this.attribute != null ?
            this.attribute.hashCode() : 0);
        hash = 89 * hash + (this.oldValue != null ?
            this.oldValue.hashCode() : 0);
        hash = 89 * hash + (this.newValue != null ?
            this.newValue.hashCode() : 0);
        return hash;
    }
}
