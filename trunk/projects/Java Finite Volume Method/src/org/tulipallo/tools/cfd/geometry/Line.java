/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2010 M2 Astronautics
 * Copyright (C) 2001, softSurfer (www.softsurfer.com)
 *
 * This class contains code under copyright of softSurfer (www.softsurfer.com).
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

import org.tulipallo.tools.cfd.geometry.collision.PointIntersection;
import org.tulipallo.tools.cfd.geometry.collision.ClosestPointOfApproach;
import org.tulipallo.tools.cfd.geometry.collision.IntersectionResult;
import org.tulipallo.tools.cfd.geometry.collision.Disjointed;
import javax.vecmath.Point3d;
import javax.vecmath.Vector3d;
import org.tulipallo.tools.cfd.SimulationContext;
import org.tulipallo.tools.util.Epsilon;

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
public class Line {
    public Vector3d a;
    public Vector3d b;

    public Line(final Vector3d a, final Vector3d b) {
        this.set(a, b);
    }

    public Line(final Line line) {
        this.set(line);
    }
    
    public Line(final Ray ray) {
        this.set(ray);
    }
    
    public Line(final Segment segment) {
        this.set(segment);
    }

    public final synchronized void set(final Ray ray) {
        if(ray == null)
            throw new IllegalArgumentException(
                    "Argument \"ray\" cannot be null.");
        this.set(new Vector3d(ray.a), new Vector3d(ray.b));
    }

    public final synchronized void set(final Segment segment) {
        if(segment == null)
            throw new IllegalArgumentException(
                    "Argument \"segment\" cannot be null.");
        this.set(new Vector3d(segment.a), new Vector3d(segment.b));
    }
    
    public final synchronized void set(final Line line) {
        if(line == null)
            throw new IllegalArgumentException(
                    "Argument \"line\" cannot be null.");
        this.set(new Vector3d(line.a), new Vector3d(line.b));
    }

    public final synchronized void set(final Vector3d a, final Vector3d b) {
        if(a == null)
            throw new IllegalArgumentException(
                    "Argument \"a\" cannot be null.");
        if(b == null)
            throw new IllegalArgumentException(
                    "Argument \"b\" cannot be null.");
        this.a = a;
        this.b = b;
    }

    public Vector3d getA() {
        return this.a;
    }

    public Vector3d getB() {
        return this.b;
    }

    /**
     * Returns the distance this <tt>Line</tt> and argument <tt>point</tt>.
     * <p/>
     * Copyright &copy; 2001, softSurfer (www.softsurfer.com)
     * <p/>
     * Courtesy Dan Sunday from softsurfer.com.  Heavily modified by
     * Robert R Murrell to support the Java Platform.  Also modified to return
     * the Wc(0) and Wc(1).
     * <p/>
     * <a href="http://softsurfer.com/Archive/algorithm_0102/algorithm_0102.htm#dist_Point_to_Line%28%29">http://softsurfer.com/Archive/algorithm_0102/algorithm_0102.htm#dist_Point_to_Line%28%29</a>
     * <p/>
     * <b>References</b>
     * <hr />
     * <ul>
     *     <li>David Eberly, "Distance Between Point and Line, Ray, or Line Segment", Magic Software</li>
     *     <li>David Eberly, "Distance Between Point and Line, Ray, or Line Segment", Magic Software</li>
     *     <li>Andrew Hanson, "Geometry for N-Dimensional Graphics"  in Graphics Gems IV (1994)</li>
     *     <li>Thomas Heath, The Thirteen Books of Euclid's Elements, Vol 1 (Books I and II) (1956)</li>
     *     <li>Jack Morrison, "The Distance from a Point to a Line", in Graphics Gems II (1994)</li>
     * </ul>
     *
     * @param point
     *
     * @return The distance this <tt>Line</tt> and argument <tt>point</tt>.
     */
    public double distance(final Point3d point) {
        if(point == null)
            throw new IllegalArgumentException(
                    "Argument \"point\" cannot be null.");
        Point3d v = VectorMath.subtract(this.b, this.a);
        Point3d w = VectorMath.subtract(point,  this.a);

        double c1 = VectorMath.dot(w, v);
        double c2 = VectorMath.dot(v, v);
        double bb = c1 / c2;

        return point.distance(VectorMath.add(this.a,
                              VectorMath.multiply(bb, v)));
    }

    /**
     * Returns the closest point of approach (CPA) between this <tt>Segment</tt>
     * and argument <tt>segment</tt>.
     * <p/>
     * Copyright &copy; 2001, softSurfer (www.softsurfer.com)
     * <p/>
     * Courtesy Dan Sunday from softsurfer.com.  Heavily modified by
     * Robert R Murrell to support the Java Platform.  Also modified to return
     * the Wc(0) and Wc(1).
     * <p/>
     * <a href="http://softsurfer.com/Archive/algorithm_0106/algorithm_0106.htm#dist3D_Line_to_Line%28%29">http://softsurfer.com/Archive/algorithm_0106/algorithm_0106.htm#dist3D_Line_to_Line%28%29</a>
     * <p/>
     * <b>References</b>
     * <hr />
     * <ul>
     *     <li>David Eberly, 3D Game Engine Design, Section 2.6 "Distance Methods" (2001)</li>
     *     <li>Seth Teller, line_line_closest_points3d() (2000) cited in the Graphics Algorithms FAQ Subject 5.18 (2001)</li>
     * </ul>
     *
     * @param line
     *
     * @return The closest point of approach (CPA).
     */
    public ClosestPointOfApproach closestPointOfApproach(final Line line) {
        if(line == null)
            throw new IllegalArgumentException(
                    "Argument \"line\" cannot be null.");
        Epsilon eps = SimulationContext.getInstance().getEpsilon();
        Point3d u  = VectorMath.subtract(this.b, this.a);
        Point3d v  = VectorMath.subtract(line.b, line.a);
        Point3d w  = VectorMath.subtract(this.a, line.a);
        double  aa = VectorMath.dot(u, u);   // always >= 0
        double  bb = VectorMath.dot(u, v);
        double  c  = VectorMath.dot(v, v);   // always >= 0
        double  d  = VectorMath.dot(u, w);
        double  e  = VectorMath.dot(v, w);
        double  D  = aa * c - bb * bb;      // always >= 0
        double  sc, tc;

        // compute the line parameters of the two closest points
        if(eps.isLessThan(D)) {             // the lines are almost parallel
            sc = 0.0;
            tc = (bb > c ? d / bb : e/c);   // use the largest denominator
        }
        else {
            sc = (bb * e - c  * d) / D;
            tc = (aa * e - bb * d) / D;
        }

        return new ClosestPointOfApproach(
                VectorMath.add(this.a, VectorMath.multiply(sc, u)),
                VectorMath.add(line.a, VectorMath.multiply(tc, v)));
    }

    /**
     * Tests that <tt>segment</tt> getIntersection this <tt>Segment</tt>.
     * <p/>
     * This class is dependant on
     * {@link #closestPointOfApproach(org.tulipallo.tools.cfd.geometry.Line) } and assumes
     * segments are intersecting if the distance between them is within the
     * machine epsilon defined in the {@link SimulationContext}.
     * <p/>
     * This method determines if intersecting lines are co-planer by
     * the normal (||) of the crossProduct product of {@link #a} and <tt>segment.b</tt>
     * (P0 X S1.P1) == 0.
     *
     * @param segment
     *
     * @return {@link Disjointed} if <tt>segment</tt> is <tt>null</tt> or does
     *         not intersect this <tt>Segment</tt>.  {@link SegmentIntersection}
     *         if <tt>segment</tt> and this <tt>Segment</tt> are co-planer or
     *         {@link PointIntersection} if the segments intersect.
     *
     * @see #closestPointOfApproach(org.jfvm.j3d.Segment)
     * @see SimulationContext
     * @see Epsilon
     */
    public IntersectionResult getIntersection(final Line line) {
        if(line == null)
            throw new IllegalArgumentException(
                    "Argument \"line\" cannot be null.");
        ClosestPointOfApproach cpa = this.closestPointOfApproach(line);
        if(SimulationContext.getInstance().getEpsilon().isLessThan(
                cpa.getWc().length))
            return new PointIntersection(line, this, cpa.getWc().center);
        return new Disjointed(line, this);
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Line other = (Line) obj;
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
        hash = 97 * hash + (this.a != null ? this.a.hashCode() : 0);
        hash = 97 * hash + (this.b != null ? this.b.hashCode() : 0);
        return hash;
    }

    @Override
    public String toString() {
        StringBuilder buffer = new StringBuilder();
        buffer.append('{').append(Line.class.getCanonicalName()).append('{');
        buffer.append("a:").append(this.a).append(",b:").append(this.b);
        buffer.append("}}");
        return buffer.toString();
    }
}
