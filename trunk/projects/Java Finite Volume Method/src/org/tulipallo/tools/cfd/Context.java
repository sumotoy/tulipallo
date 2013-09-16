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

package org.tulipallo.tools.cfd;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

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
public class Context {
    private Map<String, Object> properties;

    private final Object propertiesMutex;

    public Context() {
        this.propertiesMutex = new Object();
        this.properties      = new HashMap();
    }

    public String getProperty(final String name) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"name\" cannot be null or 0 length.");
        Object value;
        synchronized(this.propertiesMutex) {
            value = this.properties.get(name);
        }
        return String.class.cast(value);
    }
    
    public <T> T getProperty(final String name, final Class<T> aClass) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"name\" cannot be null or 0 length.");
        Object value;
        synchronized(this.propertiesMutex) {
            value = this.properties.get(name);
        }
        return aClass.cast(value);
    }
    
    public <T> T getProperty(final String name, final T defaultValue, 
                             final Class<T> aClass) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"name\" cannot be null or 0 length.");
        Object value;
        synchronized(this.propertiesMutex) {
            value = this.properties.get(name);
        }
        if(value == null)
            return defaultValue;
        else
            return aClass.cast(value);
    }

    public void setProperty(final String name,
                            final Object object) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"name\" cannot be null or 0 length.");
        synchronized(this.propertiesMutex) {
            this.properties.put(name, object);
        }
    }

    public Object removeProperty(final String name) {
        synchronized(this.propertiesMutex) {
            return this.properties.remove(name);
        }
    }

    public int getPropertyCount() {
        synchronized(this.propertiesMutex) {
            return this.properties.size();
        }
    }

    public Set<String> getPropertyKeys() {
        synchronized(this.propertiesMutex) {
            return this.properties.keySet();
        }
    }
}
