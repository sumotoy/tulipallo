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

import org.tulipallo.tools.cfd.geometry.collision.SegmentIntersection;
import org.tulipallo.tools.cfd.geometry.collision.PointIntersection;
import org.tulipallo.tools.cfd.geometry.collision.ClosestPointOfApproach;
import org.tulipallo.tools.cfd.geometry.collision.IntersectionResult;
import org.tulipallo.tools.cfd.geometry.collision.Coincident;
import org.tulipallo.tools.cfd.geometry.collision.Disjointed;
import java.util.Arrays;
import javax.vecmath.Vector3d;
import javax.vecmath.Point3d;
import org.tulipallo.tools.cfd.SimulationContext;
import org.tulipallo.tools.util.Epsilon;

/**
 * This class represents a line of finite size.
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
public class Segment {
    public Point3d a;
    public Point3d b;
    public Point3d center;
    public double  length;

    /**
     * Creates a new <tt>Segment</tt> from 2 points.
     * <p/>
     * If the points <tt>a</tt> and <tt>b</tt> are passed
     * {@link Orientation#COUNTER_CLOCKWISE} the <tt>a</tt> and <tt>b</tt> are
     * reversed.
     * <p/>
     * As a optimization measure the {@link #length} and {@link #center} are
     * immediately calculated.
     *
     * @param a The starting point of this <tt>Segment</tt>.
     * @param b The ending point of this <tt>Segment</tt>.
     *
     * @throws IllegalArgumentException if arguments <tt>a</tt> or <tt>b</tt>
     *         are <tt>null</tt>.
     * @throws DegenerateSegmentException if this line forms a point.
     *
     * @see #midPoint(javax.vecmath.Point3d, javax.vecmath.Point3d)
     */
    public Segment(final Point3d a, final Point3d b) {
        this.set(a, b);
    }
    
    public final synchronized void set(final Point3d a, final Point3d b) {
        if(a == null)
            throw new IllegalArgumentException(
                    "Argument \"a\" cannot be null.");
        if(b == null)
            throw new IllegalArgumentException(
                    "Argument \"b\" cannot be null.");
        this.a      = a;
        this.b      = b;
        this.center = Segment.midPoint(a, b);
        this.length = this.a.distance(this.b);
    }

    public Point3d getA() {
        return this.a;
    }

    public Point3d getB() {
        return this.b;
    }

    /**
     * Returns the length of this <tt>Segment</tt>.
     *
     * @return The length of this <tt>Segment</tt>.
     */
    public double getLength() {
        return this.length;
    }

    /**
     * Returns the center point of this <tt>Segment</tt>.
     *
     * @return The center point of this <tt>Segment</tt>.
     */
    public Point3d getCenter() {
        return this.center;
    }

    /**
     * Calculates the distance of point <tt>point</tt> to this <tt>Segment</tt>.
     * <p/>
     * Copyright &copy; 2001, softSurfer (www.softsurfer.com)
     * <p/>
     * Courtesy Dan Sunday from softsurfer.com.  Heavily modified by
     * Robert R Murrell to support the Java Platform.
     * <p/>
     * <a href="http://softsurfer.com/Archive/algorithm_0102/algorithm_0102.htm#dist_Point_to_Segment%28%29">http://softsurfer.com/Archive/algorithm_0102/algorithm_0102.htm#dist_Point_to_Segment%28%29</a>
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
     * @return The distance from point <tt>point</tt> to this <tt>Segment</tt>.
     *
     * @throws NullPointerException if argument <tt>point</tt> is <tt>null</tt>.
     */
    public double distance(final Point3d point) {
        if(point == null)
            throw new IllegalArgumentException(
                    "Argument \"point\" cannot be null.");
        Point3d v = VectorMath.subtract(this.b, this.a);
        Point3d w = VectorMath.subtract(point,  this.a);

        double c1 = VectorMath.dot(w, v);
        if(c1 <= 0 )
            return point.distance(this.a);

        double c2 = VectorMath.dot(v, v);
        if(c2 <= c1 )
            return point.distance(this.b);

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
     * <a href="http://softsurfer.com/Archive/algorithm_0106/algorithm_0106.htm#dist3D_Segment_to_Segment">http://softsurfer.com/Archive/algorithm_0106/algorithm_0106.htm#dist3D_Segment_to_Segment</a>
     * <p/>
     * <b>References</b>
     * <hr />
     * <ul>
     *     <li>David Eberly, 3D Game Engine Design, Section 2.6 "Distance Methods" (2001)</li>
     *     <li>Seth Teller, line_line_closest_points3d() (2000) cited in the Graphics Algorithms FAQ Subject 5.18 (2001)</li>
     * </ul>
     *
     * @param segment
     *
     * @return The closest point of approach (CPA).
     */
    public ClosestPointOfApproach closestPointOfApproach(
                                            final Segment segment) {
        if(segment == null)
            throw new IllegalArgumentException(
                    "Argument \"segment\" cannot be null.");
        Epsilon eps  = SimulationContext.getInstance().getEpsilon();
        Point3d   u  = VectorMath.subtract(this.b,    this.a);
        Point3d   v  = VectorMath.subtract(segment.b, segment.a);
        Point3d   w  = VectorMath.subtract(this.a,    segment.a);
        double    aa = VectorMath.dot(u, u);
        double    bb = VectorMath.dot(u, v);
        double    c  = VectorMath.dot(v, v);
        double    d  = VectorMath.dot(u, w);
        double    e  = VectorMath.dot(v, w);
        double    D  = aa * c - bb * bb;
        double    sc, sN, sD = D;
        double    tc, tN, tD = D;

        if(eps.isLessThan(D)) {
            sN = 0.0;
            sD = 1.0;
            tN = e;
            tD = c;
        }
        else {
            sN = (bb * e - c  * d);
            tN = (aa * e - bb * d);
            if(sN < 0.0) {
                sN = 0.0;
                tN = e;
                tD = c;
            }
            else if(sN > sD) {
                sN = sD;
                tN = e + bb;
                tD = c;
            }
        }

        if(tN < 0.0) {
            tN = 0.0;
            if(-d < 0.0)
                sN = 0.0;
            else if(-d > aa)
                sN = sD;
            else {
                sN = -d;
                sD = aa;
            }
        }
        else if(tN > tD) {
            tN = tD;
            if((-d + bb) < 0.0)
                sN = 0;
            else if((-d + bb) > aa)
                sN = sD;
            else {
                sN = (-d + bb);
                sD = aa;
            }
        }
        
        sc = (eps.isLessThan(Math.abs(sN)) ? 0.0 : sN / sD);
        tc = (eps.isLessThan(Math.abs(tN)) ? 0.0 : tN / tD);

        return new ClosestPointOfApproach(
                VectorMath.add(this.a, VectorMath.multiply(sc, u)),
                VectorMath.add(segment.a, VectorMath.multiply(tc, v)));
    }
    
    public boolean isOnSegment(final Point3d point) {
        if(point == null)
            throw new IllegalArgumentException(
                    "Argument \"point\" cannot be null.");
        double mp = VectorMath.magnitude(point);
        return mp >= VectorMath.magnitude(this.a) && mp <=
                     VectorMath.magnitude(this.b);
    }

    public boolean isInSegment(final Segment segment) {
        if(segment == null)
            throw new IllegalArgumentException(
                    "Argument \"segment\" cannot be null.");
        return this.isOnSegment(segment.a) && this.isOnSegment(segment.b);
    }

    public boolean isParallelWith(final Segment segment) {
        if(segment == null)
            throw new IllegalArgumentException(
                    "Argument \"segment\" cannot be null.");
        Epsilon eps  = SimulationContext.getInstance().getEpsilon();
        Point3d   u  = VectorMath.subtract(this.b,    this.a);
        Point3d   v  = VectorMath.subtract(segment.b, segment.a);
        Point3d   w  = VectorMath.subtract(this.a,    segment.a);
        double    aa = VectorMath.dot(u, u);
        double    bb = VectorMath.dot(u, v);
        double    c  = VectorMath.dot(v, v);
        double    d  = VectorMath.dot(u, w);
        double    D  = aa * c - bb * bb;
        return eps.isLessThan(D);
    }

    /**
     * Tests that <tt>segment</tt> getIntersection this <tt>Segment</tt>.
     * <p/>
     * This class is dependant on
     * {@link #closestPointOfApproach(org.jfvm.j3d.Segment)} and assumes
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
    public IntersectionResult getIntersection(final Segment segment) {
        if(segment == null)
            throw new IllegalArgumentException(
                    "Argument \"segment\" cannot be null.");
        ClosestPointOfApproach cpa = this.closestPointOfApproach(segment);
        if(SimulationContext.getInstance().getEpsilon().isLessThan(
                cpa.getWc().length)) {
            if(this.isParallelWith(segment))
                return new Coincident(segment, this);
            return new PointIntersection(segment, this, cpa.getWc().center);
        }
        return new Disjointed(segment, this);
    }

    public IntersectionResult getCollinearIntersection(final Segment segment) {
        Point3d[] pts = new Point3d[4];
        pts[0] = this.a;
        pts[1] = this.b;
        pts[2] = segment.a;
        pts[3] = segment.b;
        Arrays.sort(pts, new LargestAxisComparator(pts));
        return new SegmentIntersection(segment, this, 
                new Segment(pts[1], pts[2]));
    }

    public Segment flip() {
        return new Segment(this.b, this.a);
    }

    public Ray createRay() {
        return new Ray(this.a, new Vector3d(this.b));
    }

    /**
     * Calculates the mid-point of a <tt>Segment</tt> formed by <tt>a</tt> and
     * <tt>b</tt>.
     * <p/>
     * <b>Formula:</b> <tt>(a.x + b.x) / 2, (a.y + b.y) / 2, (a.z + b.z) /
     * 2</tt>
     *
     * @param a
     * @param b
     * 
     * @return
     */
    public static Point3d midPoint(final Point3d a, final Point3d b) {
        return new Point3d((a.x + b.x) / 2, (a.y + b.y) / 2, (a.z + b.z) / 2);
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        
        final Segment other = (Segment) obj;
        return (this.a.equals(other.a) || this.a.equals(other.b)) &&
               (this.b.equals(other.b) || this.b.equals(other.a));
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 29 * hash + (this.a != null ? this.a.hashCode() : 0);
        hash = 29 * hash + (this.b != null ? this.b.hashCode() : 0);
        return hash;
    }

    @Override
    public String toString() {
        StringBuilder buffer = new StringBuilder();
       buffer.append('{').append(Segment.class.getCanonicalName()).append('{');
        buffer.append("a:").append(this.a);
        buffer.append(",b:").append(this.b);
        buffer.append(",center:").append(this.center);
        buffer.append(",length:").append(this.length).append("}}");
        return buffer.toString();
    }
}
