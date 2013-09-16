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
import javax.vecmath.Tuple3d;

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
public class VectorMath {
    public static final Point3d ZERO      = new Point3d();
    public static final Point3d MAX_UPPER = new Point3d(Double.MAX_VALUE, Double.MAX_VALUE, Double.MAX_VALUE);
    public static final Point3d MAX_LOWER = new Point3d(Double.MIN_VALUE, Double.MIN_VALUE, Double.MIN_VALUE);
    public static final Point3d MAX_X     = new Point3d(Double.MAX_VALUE, 0, 0);
    public static final Point3d MAX_Y     = new Point3d(0, Double.MAX_VALUE, 0);
    public static final Point3d MAX_Z     = new Point3d(0, 0, Double.MAX_VALUE);
    public static final Point3d MIN_X     = new Point3d(Double.MIN_VALUE, 0, 0);
    public static final Point3d MIN_Y     = new Point3d(0, Double.MIN_VALUE, 0);
    public static final Point3d MIN_Z     = new Point3d(0, 0, Double.MIN_VALUE);
    
    public static Point3d createPoint(final double scalar) {
        return new Point3d(scalar, scalar, scalar);
    }
    
    public static Point3d subtract(final Tuple3d a, final Tuple3d b) {
        return new Point3d(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    public static Point3d subtract(final Tuple3d a, final double scalar) {
        return new Point3d(a.x - scalar, a.y - scalar, a.z - scalar);
    }

    public static Point3d subtract(final double scalar, final Tuple3d a) {
        return new Point3d(scalar - a.x, scalar - a.y, scalar - a.z);
    }

    public static Point3d add(final Tuple3d a, final Tuple3d b) {
        return new Point3d(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    public static Point3d add(final Tuple3d a, final double scalar) {
        return new Point3d(a.x + scalar, a.y + scalar, a.z + scalar);
    }
    
    /**
     * Convenience method for consistent method signatures.
     * 
     * @param scalar
     * @param a
     * 
     * @return 
     */
    public static Point3d add(final double scalar, final Tuple3d a) {
        return VectorMath.add(a, scalar);
    }

    public static Point3d cross(final Tuple3d a, final Tuple3d b) {
        return new Point3d(a.y * b.z - a.z * b.y,
                           a.z * b.x - a.x * b.z,
		           a.x * b.y - a.y * b.x);
    }

    public static double dot(final Tuple3d a, final Tuple3d b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    public static Point3d multiply(final Tuple3d a, final double scalar) {
        return new Point3d(a.x * scalar, a.y * scalar, a.z * scalar);
    }

    /**
     * Convenience method for consistent method signatures.
     * 
     * @param scalar
     * @param a
     * 
     * @return 
     */
    public static Point3d multiply(final double scalar, final Tuple3d a) {
        return VectorMath.multiply(a, scalar);
    }

    public static Point3d multiply(final Tuple3d a, final Tuple3d b) {
        return new Point3d(a.x * b.x, a.y * b.y, a.z * b.z);
    }

    public static Point3d divide(final Tuple3d a, final Tuple3d b) {
        return new Point3d(a.x / b.x, a.y / b.y, a.z / b.z);
    }

    public static Point3d divide(final Tuple3d a, final double scalar) {
        return new Point3d(a.x / scalar, a.y / scalar, a.z / scalar);
    }
    
    public static Point3d divide(final double scalar, final Tuple3d a) {
        return new Point3d(scalar / a.x, scalar / a.y, scalar / a.z);
    }

    public static double magnitude(final Tuple3d a) {
        return Math.sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    }

    public static double normal(final Tuple3d a) {
        return Math.sqrt(VectorMath.dot(a, a));
    }
}
