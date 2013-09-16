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

import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import org.tulipallo.tools.cfd.geometry.Triangle;

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
public class Subject extends Target {
    private Set<Target> targets;

    public Subject() {
        this.targets = new HashSet();
    }
    
    public Subject(final Set<Target> targets) {
        this.setTargets(targets);
    }

    public Subject(final Set<Target> targets, final String name, 
                   final List<Triangle> triangles) {
        super(name, triangles);
        this.setTargets(targets);
    }

    public Subject(final String name, final List<Triangle> triangles) {
        super(name, triangles);
        this.targets = new HashSet();
    }

    public synchronized Set<Target> getTargets() {
        return Collections.unmodifiableSet(this.targets);
    }

    public final synchronized void setTargets(final Set<Target> targets) {
        if(targets == null)
            throw new IllegalArgumentException(
                    "Argument 'targets' cannot be null.");
        
        this.targets = new HashSet(targets.size());
        this.targets.addAll(targets);
    }
    
    public synchronized void addTarget(final Target target) {
        if(target == null)
            throw new IllegalArgumentException(
                    "Argument 'target' cannot be null.");
        this.targets.add(target);
    }
    
    public synchronized void removeTarget(final Target target) {
        this.targets.remove(target);
    }
}
