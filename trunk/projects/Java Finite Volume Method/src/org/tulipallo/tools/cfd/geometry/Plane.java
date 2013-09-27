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

import javax.vecmath.Vector4d;
import org.tulipallo.tools.cfd.geometry.collision.CoincidentSegment;
import org.tulipallo.tools.cfd.geometry.collision.SegmentIntersection;
import org.tulipallo.tools.cfd.geometry.collision.PointIntersection;
import org.tulipallo.tools.cfd.geometry.collision.IntersectionResult;
import org.tulipallo.tools.cfd.geometry.collision.LineIntersection;
import org.tulipallo.tools.cfd.geometry.collision.Coincident;
import org.tulipallo.tools.cfd.geometry.collision.Disjointed;
import javax.vecmath.Point3d;
import javax.vecmath.Vector3d;
import org.tulipallo.tools.cfd.SimulationContext;
import org.tulipallo.tools.util.Epsilon;

/**
 * Implementation of a plane inspired by Dan Sunday.
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
public class Plane {
    public double   d;
    public Point3d  point;
    public Vector3d normal;
    
    public Plane(final Triangle triangle) {
        if(triangle == null)
            throw new IllegalArgumentException(
                    "Argument \"triangle\" cannot be null.");
        Point3d a   = triangle.getPoint(Triangle.POINT_A);
        Point3d b   = triangle.getPoint(Triangle.POINT_B);
        Point3d c   = triangle.getPoint(Triangle.POINT_C);
        Point3d e3  = VectorMath.subtract(b, a);
        Point3d e1  = VectorMath.subtract(c, b);
        Point3d ec  = VectorMath.cross(e3, e1);
        this.normal = new Vector3d(VectorMath.divide(ec, VectorMath.normal(ec)));
        this.point  = a;
        this.d      = VectorMath.dot(this.point, this.normal);
    }

    public Vector3d getNormal() {
        return this.normal;
    }

    public Point3d getPoint() {
        return this.point;
    }

    public double getD() {
        return this.d;
    }
    
    public Vector4d toVector() {
        return new Vector4d(this.point.x, this.point.x, this.point.z, this.d);
    }

    /**
     * Returns the distance between point <tt>p</tt> and this <tt>Plane</tt>.
     * <p/>
     * <b>References</b>
     * <hr />
     * <ul>
     *     <li><u>3D Math Primer for Graphics and Game Development</u> by Fletcher Dunn and Ian Parberry. (12.5.4 Distance from Point to Plane)</li>
     * </ul>
     *
     * @param p
     *
     * @return The distance between point <tt>p</tt> and this <tt>Plane</tt>.
     *         Negative (-) if in back of this <tt>Plane</tt>, positive (+)
     *         otherwise.
     */
    public double distance(final Point3d point) {
        if(point == null)
            throw new IllegalArgumentException(
                    "Argument \"point\" cannot be null.");
        return VectorMath.dot(point, VectorMath.subtract(this.normal, this.d));
    }

    /**
     * Returns the intersecting point of argument <tt>segment</tt> and this
     * <tt>Plane</tt>.
     * <p/>
     * Copyright &copy; 2001, softSurfer (www.softsurfer.com)
     * <p/>
     * Courtesy Dan Sunday from softsurfer.com.  Heavily modified by
     * Robert R Murrell to support the Java Platform.
     * <p/>
     * <a href="http://softsurfer.com/Archive/algorithm_0104/algorithm_0104B.htm#intersect3D_2Planes%28%29">http://softsurfer.com/Archive/algorithm_0104/algorithm_0104B.htm#intersect3D_2Planes%28%29</a>
     * <p/>
     * <b>References</b>
     * <hr />
     * <ul>
     *     <li>Foley, van Dam, Feiner & Hughes, Computer Graphics (2nd Edition in C), Section 3.12 "Clipping Lines" (1996)</li>
     *     <li>Francis Hill, "The Pleasures of 'Perp Dot' Products" in Graphics Gems IV (1994)<br />
     *         [Note: the first critical definition has a typo, and should be: a^ = (-ay, ax).]</li>
     *     <li>Michael Mortenson, Computer Graphics Handbook : Geometry and Mathematics (1990)</li>
     *     <li>Joseph O'Rourke, Computational Geometry in C (2nd Edition), Chapter 7 "Search and Intersection" (1998)</li>
     * </ul>
     *
     * @param segment
     *
     * @return {@link Coincident} if <tt>segment</tt> lies on the same
     *         plane.  {@link Disjointed} if <tt>segment</tt> does not intersect
     *         this <tt>Plane</tt>.  {@link PointIntersection} if
     *         <tt>segment</tt> getIntersection this <tt>Plane</tt>.
     */
    public IntersectionResult getIntersection(final Segment segment) {
        if(segment == null)
            throw new IllegalArgumentException(
                    "Argument \"segment\" cannot be null.");
        Epsilon eps = SimulationContext.getInstance().getEpsilon();
        Point3d u = VectorMath.subtract(segment.b, segment.a);
        Point3d w = VectorMath.subtract(segment.a, this.point);
        double D =  VectorMath.dot(this.normal, u);
        double N = -VectorMath.dot(this.normal, w);
        if(eps.isLessThan(Math.abs(D)))
            if(N == 0)
              return new Coincident(this, segment);
            else
                return new Disjointed(this, segment);
        double sI = N / D;
        if(sI < 0 || sI > 1)
            return new Disjointed(this, segment);
        return new PointIntersection(this, segment, 
                VectorMath.add(segment.a, VectorMath.multiply(sI, u)));
    }

    /**
     * Returns the intersecting <tt>Segment</tt> between argument
     * <tt>triangle</tt> and this <tt>Plane</tt>.
     *
     * @param triangle The triangle to determine the intersection with this
     *                 plane.
     *
     * @return {@link Disjointed} if argument <tt>triangle</tt> does not
     *         intersect this <tt>Plane</tt>.  {@link SegmentIntersection} if
     *         if argument <tt>triangle</tt> intersect this <tt>Plane</tt>.
     */
    public IntersectionResult getIntersection(final Triangle triangle) {
        if(triangle == null)
            throw new IllegalArgumentException(
                    "Argument \"triangle\" cannot be null.");
        Point3d[] points      = new Point3d[2];
        int       pindex      = 0;
        for(Segment segment : triangle.getSegments()) {
            IntersectionResult result = this.getIntersection(segment);
            if(result instanceof Coincident)
                return new CoincidentSegment(triangle, this, segment);
            if(result instanceof PointIntersection) {
                points[pindex] = ((PointIntersection)result).getPoint();
                ++pindex;
            }
            if(pindex == 2)
                break;
        }
        if(pindex != 2)
            return new Disjointed(triangle, this);
        return new SegmentIntersection(triangle, this,
                new Segment(points[0], points[1]));
    }

    public boolean isAllPointsCoPlaner(final Triangle triangle) {
        Epsilon eps = SimulationContext.getInstance().getEpsilon();
        int counter = 0;
        for(Point3d p : triangle.getPoints()) {
            if(eps.isLessThan(this.distance(p)))
                ++counter;
        }
        return counter == 3;
    }

    /**
     * Returns the intersecting line of argument <tt>plane</tt> and this
     * <tt>Plane</tt>.
     * <p/>
     * Copyright &copy; 2001, softSurfer (www.softsurfer.com)
     * <p/>
     * Courtesy Dan Sunday from softsurfer.com.  Heavily modified by
     * Robert R Murrell to support the Java Platform.
     * <p/>
     * <a href="http://softsurfer.com/Archive/algorithm_0104/algorithm_0104B.htm#intersect3D_2Planes%28%29">http://softsurfer.com/Archive/algorithm_0104/algorithm_0104B.htm#intersect3D_2Planes%28%29</a>
     * <p/>
     * <b>References</b>
     * <hr />
     * <ul>
     *     <li>Foley, van Dam, Feiner & Hughes, Computer Graphics (2nd Edition in C), Section 3.12 "Clipping Lines" (1996)</li>
     *     <li>Francis Hill, "The Pleasures of 'Perp Dot' Products" in Graphics Gems IV (1994)<br />
     *         [Note: the first critical definition has a typo, and should be: a^ = (-ay, ax).]</li>
     *     <li>Michael Mortenson, Computer Graphics Handbook : Geometry and Mathematics (1990)</li>
     *     <li>Joseph O'Rourke, Computational Geometry in C (2nd Edition), Chapter 7 "Search and Intersection" (1998)</li>
     * </ul>
     *
     * @param plane
     *
     * @return 
     */
    public IntersectionResult getIntersection(final Plane plane) {
        if(plane == null)
            throw new IllegalArgumentException(
                    "Argument \"plane\" cannot be null.");
        Epsilon eps = SimulationContext.getInstance().getEpsilon();

        Point3d  u  = VectorMath.cross(this.normal, plane.normal);
        double   ax = (u.x >= 0 ? u.x : -u.x);
        double   ay = (u.y >= 0 ? u.y : -u.y);
        double   az = (u.z >= 0 ? u.z : -u.z);

        if(eps.isLessThan(ax + ay + az)) {
            Point3d v = VectorMath.subtract(plane.point, this.point);
            if(VectorMath.dot(this.normal, v) == 0)
                return new Coincident(plane, this);
            else
                return new Disjointed(plane, this);
        }

        int maxc;
        if(ax > ay)
            if (ax > az)
                maxc = 1;
            else maxc = 3;
        else 
            if(ay > az)
                maxc = 2;
            else maxc = 3;

        Vector3d ip = new Vector3d();
        switch(maxc) {
            case 1:
                ip.x = 0;
                ip.y = (plane.d * this.normal.z  - this.d  * plane.normal.z) /
                        u.x;
                ip.z = (this.d  * plane.normal.y - plane.d * this.normal.y)  /
                        u.x;
                break;
            case 2:
                ip.x = (this.d * plane.normal.z - plane.d * this.normal.z) /
                        u.y;
                ip.y = 0;
                ip.z = (plane.d * this.normal.x - this.d * plane.normal.x) /
                        u.y;
                break;
            case 3:
                ip.x = (plane.d * this.normal.y  - this.d  * plane.normal.y) /
                        u.z;
                ip.y = (this.d  * plane.normal.x - plane.d * this.normal.x)  /
                        u.z;
                ip.z = 0;
        }
        return new LineIntersection(plane, this,
                new Line(ip, new Vector3d(VectorMath.add(ip, u))));
    }

    /**
     * Returns the base of perpendicular from point <tt>p</tt> to this
     * <tt>Plane</tt>.
     * <p/>
     * Copyright &copy; 2001, softSurfer (www.softsurfer.com)
     * <p/>
     * Courtesy Dan Sunday from softsurfer.com.  Heavily modified by
     * Robert R Murrell to support the Java Platform.
     * <p/>
     * <a href="http://softsurfer.com/Archive/algorithm_0104/algorithm_0104.htm">http://softsurfer.com/Archive/algorithm_0104/algorithm_0104.htm</a>
     * <p/>
     * <b>References</b>
     * <hr />
     * <ul>
     *     <li>Donald Coxeter, Introduction to Geometry (2nd Edition), Sect 12.4 "Planes and Hyperplanes", John Wiley & Sons (1989a)</li>
     *     <li>Donald Coxeter, Introduction to Geometry (2nd Edition), Sect 13.7 "Barycentric Coordinates", John Wiley & Sons (1989b)</li>
     *     <li>Euclid, The Elements, Alexandria (300 BC)</li>
     *     <li>Andrew Hanson, "Geometry for N-Dimensional Graphics"  in Graphics Gems IV (1994)</li>
     *     <li>Thomas Heath, The Thirteen Books of Euclid's Elements, Vol 1 (Books I and II) (1956)</li>
     *     <li>Thomas Heath, The Thirteen Books of Euclid's Elements, Vol 3 (Books X-XIII) (1956)</li>
     *     <li>Francis Hill, "The Pleasures of 'Perp Dot' Products" in Graphics Gems IV (1994) <br/>
     *         [Note: the first critical definition has a typo, and should be: a^ = (-ay, ax).]</li>
     * </ul>
     *
     * @param point
     *
     * @return The distance of point <tt>p</tt> to this <tt>Plane</tt>.
     */
    public Point3d getBaseOfPerpendicularFromPoint(final Point3d point) {
        if(point == null)
            throw new IllegalArgumentException(
                    "Argument \"point\" cannot be null.");
        double sb, sn, sd;
        sn = -VectorMath.dot(this.normal,
                             VectorMath.subtract(point, this.point));
        sd = VectorMath.dot(this.normal, this.normal);
        sb = sn / sd;
        return VectorMath.add(point, VectorMath.multiply(sb, this.normal));
    }

    public Segment getSegmentFromPerpendicularToPoint(final Point3d point) {
        return new Segment(this.getBaseOfPerpendicularFromPoint(point), point);
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Plane other = (Plane) obj;
        if (this.point != other.point && (this.point == null ||
                !this.point.equals(other.point))) {
            return false;
        }
        if (this.normal != other.normal && (this.normal == null ||
                !this.normal.equals(other.normal))) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 41 * hash + (this.point != null ? this.point.hashCode() : 0);
        hash = 41 * hash + (this.normal != null ? this.normal.hashCode() : 0);
        return hash;
    }

    @Override
    public String toString() {
        StringBuilder buffer = new StringBuilder();
        buffer.append('{').append(Plane.class.getCanonicalName()).append('{');
        buffer.append("point:").append(this.point);
        buffer.append(",normal:").append(this.normal);
        buffer.append(",d:").append(this.d).append("}}");
        return buffer.toString();
    }
}
