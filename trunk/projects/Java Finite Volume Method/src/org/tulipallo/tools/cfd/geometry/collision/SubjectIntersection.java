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

package org.tulipallo.tools.cfd.geometry.collision;

import java.util.List;

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
public class SubjectIntersection extends IntersectionResult {
    private List<IntersectionResult> intersections;

    public SubjectIntersection(final Object source, final Object target,
                               final List<IntersectionResult> intersections) {
        super(source, target);
        if(intersections == null)
            throw new IllegalArgumentException(
                    "Argument \"intersections\" cannot be null.");
        if(intersections.isEmpty())
            throw new IllegalArgumentException(
                    "Argument \"intersections\" cannot be empty, use "
                    + "Disjointed instead..");
        this.intersections = intersections;
    }

    public List<IntersectionResult> getIntersections() {
        return this.intersections;
    }
}
