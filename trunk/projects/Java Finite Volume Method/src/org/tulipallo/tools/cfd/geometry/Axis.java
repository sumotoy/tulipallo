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
public enum Axis {
    X(0, new XAxisValueAccessor()),
    Y(1, new YAxisValueAccessor()),
    Z(2, new ZAxisValueAccessor());

    public  final int                index;
    private final AxialValueAccessor accessor;

    private Axis(final int index, final AxialValueAccessor accessor) {
        this.index    = index;
        this.accessor = accessor;
    }

    public int getIndex() {
        return this.index;
    }

    public double get(final Point3d point) {
        return this.accessor.get(point);
    }
    
    public Point3d set(final Point3d point, final double value) {
        return this.accessor.set(point, value);
    }

    public static Axis getLargestAxis(final Segment segment) {
        if(segment == null)
            throw new IllegalArgumentException(
                    "Argument \"segment\" cannot be null.");
        return Axis.getLargestAxis(new Tuple3d[]{segment.a, segment.b});
    }

    public static Axis getLargestAxis(final Tuple3d[] points) {
        if(points == null)
            throw new IllegalArgumentException(
                    "Argument \"points\" cannot be null.");
        double dx, ax = 0;
        double dy, ay = 0;
        double dz, az = 0;
        
        // Deliberately starting at one
        for(int index = 1; index < points.length; ++index) {
            int last = index -1;
            dx = Math.abs(points[index].x - points[last].x);
            dy = Math.abs(points[index].y - points[last].y);
            dz = Math.abs(points[index].z - points[last].z);
            
            if(dx > ax) 
                ax = dx;
            if(dy > ay) 
                ay = dy;
            if(dz > az) 
                az = dz;
        }
        
        if(ax > ay)
            if(ax > az)
                return Axis.X;
            else
                return Axis.Z;
        if(ay > az)
            return Axis.Y;
        return Axis.Z;
    }
}
