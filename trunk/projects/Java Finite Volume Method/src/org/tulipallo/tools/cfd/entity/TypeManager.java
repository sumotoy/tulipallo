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
import java.util.Map;

/**
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
public class TypeManager {
    private Map<String, Type> types;

    public TypeManager() {
        this.types = new HashMap();
    }

    public synchronized void add(final Type type) {
        if(type == null)
            throw new IllegalArgumentException(
                    "Argument \"type\" cannot be null.");
        String name = type.getName();
        if(this.types.containsKey(name))
            throw new TypeDefinedException(name);
        this.types.put(name, type);
    }

    public synchronized void remove(final Type type) {
        if(type != null)
            this.remove(type.getName());
    }

    public synchronized void remove(final String name) {
        if(name != null && name.length() > 0)
            this.types.remove(name);
    }

    public synchronized Type get(final String name) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"name\" cannot be null or 0 length.");
        return this.types.get(name);
    }

    public synchronized Collection<Type> getTypes() {
        return Collections.unmodifiableCollection(this.types.values());
    }
}
