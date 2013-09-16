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

package org.tulipallo.tools.cfd.geometry;

import javax.vecmath.Point3d;

/**
 * Enumeration that describes the clockwise or counter clockwise orientation of
 * a 3D system.  This enumeration can calculate the orientation from 2 points
 * assuming the were loaded in the same direction.
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
public enum Orientation {
    CLOCKWISE, COUNTER_CLOCKWISE, DEGENERATE;

    public static Orientation getOrientation(final double value) {
        if(value > 0d)
            return COUNTER_CLOCKWISE;
        if(value == 0d)
            return DEGENERATE;
        return CLOCKWISE;
    }
    
    public static Orientation getOrientation(final Point3d[] points) {
        Point3d v = VectorMath.subtract(points[0], points[1]);
        Point3d w = VectorMath.subtract(points[0], points[2]);
        return Orientation.getOrientation(VectorMath.magnitude(
                VectorMath.cross(v, w)));
    }
}
