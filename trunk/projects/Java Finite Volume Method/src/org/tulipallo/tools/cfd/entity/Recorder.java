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

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

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
public class Recorder {
    private int            maxRecords;
    private Queue<Memento> queue;

    public Recorder(final int maxRecords) {
        this.maxRecords = maxRecords;
        this.queue      = new LinkedList();
    }

    public synchronized void record(final Map<String, Attribute> supported,
                                    final Map<Attribute, Object> values) {
        if(supported == null)
            throw new IllegalArgumentException(
                    "Argument \"supported\" cannot be null.");
        if(values == null)
            throw new IllegalArgumentException(
                    "Argument \"values\" cannot be null.");
        
        if(this.queue.size() == this.maxRecords) {
            this.deleteHistory(this.queue.poll());
        }
        
        this.queue.add(new Memento(values));
    }
    
    final void deleteHistory(final Memento memento) {
        memento.clear();
    }

    public synchronized Iterator<Memento> iterator() {
        return this.queue.iterator();
    }
}
