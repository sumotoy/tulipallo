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

import javax.xml.bind.annotation.XmlRootElement;

/**
 * The base class for all data types.
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
@XmlRootElement
public abstract class Type {
    private String name;
    private Class  definition;

    /**
     * Creates a new <tt>Type</tt> with the <tt>name</tt> and
     * <tt>definition</tt> specified.
     * 
     * @param name       the name for this data type.
     * @param definition the Java class type for this data type.
     *
     * @throws IllegalArgumentException if <tt>name</tt> or <tt>definition</tt>
     *                                  are <tt>null</tt> or <tt>name</tt> is
     *                                  zero length.
     */
    public Type(final String name, final Class definition) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"name\" cannot be null or 0 length.");
        if(definition == null)
            throw new IllegalArgumentException(
                    "Argument \"definition\" cannot be null.");
        this.name       = name;
        this.definition = definition;
    }

    /**
     * Checks if argument <tt>object</tt> is an instance of this <tt>TypeToDelete</tt>.
     *
     * @param object The object to check type safety on.
     *
     * @return <tt>true</tt> if argument <tt>object</tt> is an instance of this
     *         type, <tt>false</tt> if not or argument </tt>object</tt> is
     *         <tt>null</tt>.
     */
    public boolean isInstance(final Object object) {
        if(object == null)
            return false;
        else
            return this.definition.isInstance(object);
    }

    /**
     * Returns the Java class type for this data type.
     *
     * @return The Java class type for this data type.
     */
    public Class getDefinition() {
        return this.definition;
    }

    /**
     * Returns the name for this data type.
     *
     * @return the name for this data type.
     */
    public String getName() {
        return this.name;
    }
    
    /**
     * Converts argument <tt>valueOf</tt> from a <tt>String</tt> to an instance
     * of this <tt>TypeToDelete</tt>.
     *
     * @param valueOf The <tt>String</tt> to convert to an instance of this
     *              <tt>TypeToDelete</tt>.
     *
     * @return A new instance of this <tt>TypeToDelete</tt> initialized with the
     *         information specified by <tt>valueOf</tt>.
     */
    public abstract Object parse(String value);

    /**
     * Converts argument <tt>value</tt> from a an instance of this <tt>TypeToDelete</tt>
     * to a <tt>String</tt>.
     *
     * @param valueOf The instance of this <tt>TypeToDelete</tt> to convert to an
     *              <tt>String</tt>.
     *
     * @return A new instance of <tt>String</tt> representing the state of
     *         argument <tt>valueOf</tt>.
     */
    public abstract String valueOf(Object value);
    
    public abstract Object clone(Object value);

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Type other = (Type) obj;
        if ((this.name == null) ? (other.name != null) :
            !this.name.equals(other.name)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 5;
        hash = 41 * hash + (this.name != null ? this.name.hashCode() : 0);
        return hash;
    }
}
