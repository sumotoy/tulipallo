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
import javax.vecmath.Vector3d;

/**
 * <p/>
 * Copyright &copy; 2001, softSurfer (www.softsurfer.com)
 * <p/>
 * <tt>Tulipallo - The Java Finite Volume Method Simulation<br />
 * Copyright &copy; 2010 M2 Astronautics<br />
 * Copyright &copy; 2001, softSurfer (www.softsurfer.com)</tt>
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
public class Ray {
    public Point3d  a;
    public Vector3d b;

    public Ray(final Segment segment) {
        this.set(segment);
    }

    public Ray(final Line line) {
        this.set(line);
    }

    public Ray(final Point3d a, final Vector3d b) {
        this.set(a, b);
    }

    public final synchronized void set(final Segment segment) {
        if(segment == null)
            throw new IllegalArgumentException(
                    "Argument \"segment\" cannot be null.");
        this.set(new Point3d(segment.a), new Vector3d(segment.b));
    }

    public final synchronized void set(final Line line) {
        if(line == null)
            throw new IllegalArgumentException(
                    "Argument \"line\" cannot be null.");
        this.set(new Point3d(line.a), new Vector3d(line.b));
    }

    public final synchronized void set(final Point3d a, final Vector3d b) {
        if(a == null)
            throw new IllegalArgumentException(
                    "Argument \"a\" cannot be null.");
        if(b == null)
            throw new IllegalArgumentException(
                    "Argument \"b\" cannot be null.");
        this.a = a;
        this.b = b;
    }

    public Point3d getA() {
        return a;
    }

    public Vector3d getB() {
        return b;
    }

    public boolean isPointingToward(final Point3d point) {
        if(point == null)
            throw new IllegalArgumentException(
                    "Argument \"point\" cannot be null.");
        double  start = this.a.distance(point);
        Point3d d     = VectorMath.multiply(this.a, start);
        double  end   = point.distance(d);
        return end <= start;
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Ray other = (Ray) obj;
        if (this.a != other.a && (this.a == null || !this.a.equals(other.a))) {
            return false;
        }
        if (this.b != other.b && (this.b == null || !this.b.equals(other.b))) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 31 * hash + (this.a != null ? this.a.hashCode() : 0);
        hash = 31 * hash + (this.b != null ? this.b.hashCode() : 0);
        return hash;
    }

    @Override
    public String toString() {
        StringBuilder buffer = new StringBuilder();
        buffer.append('{').append(Ray.class.getCanonicalName()).append('{');
        buffer.append("a:").append(this.a);
        buffer.append(",b:").append(this.b).append("}}");;
        return buffer.toString();
    }
}
