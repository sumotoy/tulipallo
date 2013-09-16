/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2013 Tulipallo.org
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

 /**
  * <p>TypeMock</p>
  * 
  * <p><tt>Tulipallo - The Java Finite Area Method Simulation<br />
  * Copyright &copy; 2013, Tulipallo.org.</tt></p>
  * 
  * <p>For more information on jFVM and other Tulipallo projects please visit
  * <a href="http://www.tulipallo.org">http://www.tulipallo.org</a></p>
  * <p><tt>This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.</tt></p>
  * 
  * <p><tt>You should have received a copy of the GNU General Public License
  * along with this program.  If not, see 
  * <a href="http://www.gnu.org/licenses/">http://www.gnu.org/licenses</a>.</tt></p>
  *
  * @author murrellrr
  * @since Java 6
  * @version 1.0 beta
  */
public class TypeMock extends Type{
    private static final String NAME    = "String";
    private static final String ELEMENT = "string";

    private boolean cloneInvoked      = false;
    private boolean parseInvoked      = false;
    private boolean valueOfInvoked    = false;
    private boolean marshallInvoked   = false;
    private boolean unMarshallInvoked = false;
    
    public TypeMock(final String name, final Class definition) {
        super(name, definition);
    }

    public TypeMock() {
        super(NAME, String.class);
    }

    @Override
    public Object clone(final Object value) {
        this.cloneInvoked = true;
        return new String((String)value);
    }

    @Override
    public Object parse(final String value) {
        this.parseInvoked = true;
        return value;
    }

    @Override
    public String valueOf(final Object value) {
        this.valueOfInvoked = true;
        return (String)value;
    }
    
    public void reset() {
        this.cloneInvoked      = true;
        this.parseInvoked      = true;
        this.valueOfInvoked    = true;
        this.marshallInvoked   = true;
        this.unMarshallInvoked = true;
    }

    public boolean isCloneInvoked() {
        return this.cloneInvoked;
    }

    public boolean isMarshallInvoked() {
        return this.marshallInvoked;
    }

    public boolean isParseInvoked() {
        return this.parseInvoked;
    }

    public boolean isUnMarshallInvoked() {
        return this.unMarshallInvoked;
    }

    public boolean isValueOfInvoked() {
        return this.valueOfInvoked;
    }
}
