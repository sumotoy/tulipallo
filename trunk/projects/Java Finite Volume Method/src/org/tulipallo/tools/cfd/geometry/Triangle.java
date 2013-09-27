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
import org.tulipallo.tools.cfd.geometry.collision.LineIntersection;
import org.tulipallo.tools.cfd.geometry.collision.Disjointed;
import org.tulipallo.tools.cfd.geometry.collision.Coincident;
import org.tulipallo.tools.cfd.SimulationContext;
import java.util.Arrays;
import javax.vecmath.Point3d;
import org.tulipallo.tools.util.Epsilon;

/**
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
public class Triangle {
    public static final int POINT_A = 0;
    public static final int POINT_B = 1;
    public static final int POINT_C = 2;
    
    public Point3d[] points;
    public Segment[] segments;
    public Plane     plane;
    public double    area;

    public Triangle(final Point3d a, final Point3d b, final Point3d c) {
        this.set(new Point3d[]{a, b, c});
    }

    public Triangle(final Point3d[] points) {
        this.set(points);
    }

    public Triangle(final Triangle triangle) {
        this.set(triangle);
    }
    
    public final synchronized void set(final Triangle triangle) {
        if(triangle == null)
            throw new IllegalArgumentException(
                    "Argument \"triangle\" cannot be null.");
        this.set(triangle.points);
    }

    public final synchronized void set(final Point3d[] points) {
        if(points == null)
            throw new IllegalArgumentException(
                    "Argument \"points\" cannot be null.");
        if(points.length != 3)
            throw new IllegalArgumentException(
                    "Argument \"points\" must contain 3 points.");
        if(points[0] == null || points[1] == null || points[2] == null)
            throw new IllegalArgumentException(
                    "Argument \"points\" cannot contain null points.");
        this.area = Triangle.getArea(points[0], points[1], points[2]);
        
        if(this.area == 0d)
            throw new DegenerateTriangleException(points);
            
        this.points = new Point3d[3];
        this.segments = new Segment[]{
            new Segment(this.points[0], this.points[1]),
            new Segment(this.points[1], this.points[2]),
            new Segment(this.points[2], this.points[0])
        };
        this.plane = new Plane(this);
        this.area  = Math.abs(this.area);
    }

    public Segment[] getSegments() {
        return this.segments;
    }

    public Segment getSegment(final int index) {
        if(index < 0 || index > 2)
            throw new IllegalArgumentException(
                    "Argument \"index\" must be 0 through 2.");
        return this.segments[index];
    }

    public Point3d[] getPoints() {
        return this.points;
    }
    
    public Point3d getPoint(final int index) {
        if(index < 0 || index > 2)
            throw new IllegalArgumentException(
                    "Argument \"index\" must be 0 through 2.");
        return this.points[index];
    }

    /**
     * Returns the <tt>Plane</tt> from this <tt>Triangle</tt>.
     *
     * @return The <tt>Plane</tt> from this <tt>Triangle</tt>.
     */
    public Plane getPlane() {
        return this.plane;
    }

    public double getArea() {
        return this.area;
    }

    public IntersectionResult getIntersection(final Triangle triangle) {
        if(triangle == null)
            throw new IllegalArgumentException(
                    "Argument \"triangle\" cannot be null.");
        IntersectionResult planeResult = this.plane.getIntersection(
                triangle.plane);
        if(planeResult instanceof LineIntersection) {
            IntersectionResult tp1 = this.plane.getIntersection(triangle);
            IntersectionResult tp2 = triangle.plane.getIntersection(this);
            if(tp1 instanceof SegmentIntersection &&
                            tp2 instanceof SegmentIntersection) {
                Epsilon eps = SimulationContext.getInstance().getEpsilon();
                SegmentIntersection si1 = (SegmentIntersection)tp1;
                SegmentIntersection si2 = (SegmentIntersection)tp2;
                ClosestPointOfApproach cpa =
                        si1.segment.closestPointOfApproach(si2.segment);
                if(eps.isLessThan(cpa.wc.length))
                    return si1.segment.getCollinearIntersection(si2.segment);
            }
            return new Disjointed(triangle, this);
        }
        else if(planeResult instanceof Coincident)
            return new Coincident(triangle, this);
        return planeResult;
    }
    
    public boolean isInTriangle(final Point3d point) {
        double areat = Triangle.getAbsoluteArea(point, this.points[0],
                                                this.points[1]);
        areat += Triangle.getAbsoluteArea(point, this.points[1],
                                          this.points[2]);
        areat += Triangle.getAbsoluteArea(point, this.points[0],
                                          this.points[2]);
        return SimulationContext.getInstance().getEpsilon().isEqual(
                    this.area, areat);
    }

    public static double getArea(final Point3d a, final Point3d b,
                                 final Point3d c) {
        Point3d v = VectorMath.subtract(a, b);
        Point3d w = VectorMath.subtract(a, c);
        return VectorMath.magnitude(VectorMath.cross(v, w));
    }

    public static double getAbsoluteArea(final Point3d a, final Point3d b,
                                         final Point3d c) {
        return Math.abs(Triangle.getArea(a, b, c));
    }

    /**
     * Copyright &copy; 2001, softSurfer (www.softsurfer.com)
     * <p/>
     * Courtesy Dan Sunday from softsurfer.com.  Heavily modified by
     * Robert R Murrell to support the Java Platform.
     * <p/>
     * <a href="http://softsurfer.com/Archive/algorithm_0105/algorithm_0105.htm">http://softsurfer.com/Archive/algorithm_0105/algorithm_0105.htm</a>
     * <p/>
     * <b>References</b>
     * <hr />
     * <ul>
     *     <li>Didier Badouel, "An Efficient Ray-Polygon Intersection" in Graphics Gems (1990)</li>
     *     <li>Francis Hill, "The Pleasures of 'Perp Dot' Products" in Graphics Gems IV (1994)<br />
     *         [Note: the first critical definition has a typo, and should be: a^ = (-ay, ax).]</li>
     *     <li>Tomas Moller & Eric Haines, Real-Time Rendering, Chapter 10 "Intersection Test Methods" (1999)</li>
     *     <li>Tomas Moller & Ben Trumbore, "Fast, Minimum Storage Ray-Triangle Intersection",  J. Graphics Tools 2(1), 21-28 (1997)</li>
     *     <li>Joseph O'Rourke, Computational Geometry in C (2nd Edition), Section 7.3 "Segment-Triangle Intersection" (1998)</li>
     *     <li>J.P. Snyder and A.H. Barr, "Ray Tracing Complex Models Containing Surface Tessellations", ACM Comp Graphics 21, (1987)</li>
     * </ul>
     *
     * @param segment
     *
     * @return
     */
    public IntersectionResult getIntersection(final Segment segment) {
        if(segment == null)
            throw new IllegalArgumentException(
                    "Argument \"segment\" cannot be null.");
        Point3d u = VectorMath.subtract(this.points[1], this.points[0]);
        Point3d v = VectorMath.subtract(this.points[2], this.points[0]);
        Point3d n = VectorMath.cross(u, v);
        Point3d direction =  VectorMath.subtract(segment.b, segment.a);
        Point3d w0        =  VectorMath.subtract(segment.a, this.points[0]);
        double  a         = -VectorMath.dot(n, w0);
        double  b         =  VectorMath.dot(n, direction);

        if(SimulationContext.getInstance().getEpsilon().isLessThan(
                Math.abs(b)))
            if(a == 0)
                return new Coincident(segment, this);
            else
                return new Disjointed(segment, this);

        double r = a / b;
        if(r < 0.0)
            return new Disjointed(segment, this);
        else if(r > 1.0)
            return new Disjointed(segment, this);

        Point3d p = VectorMath.add(segment.a,
                                   VectorMath.multiply(direction, r));

        double uu = VectorMath.dot(u, u);
        double uv = VectorMath.dot(u, v);
        double vv = VectorMath.dot(v, v);
        Point3d w = VectorMath.subtract(p, this.points[0]);
        double wu = VectorMath.dot(w, u);
        double wv = VectorMath.dot(w, v);
        double D  = uv * uv - uu * vv;

        double s = (uv * wv - vv * wu) / D;
        if(s < 0.0 || s > 1.0)
            return new Disjointed(segment, this);
        double t = (uv * wu - uu * wv) / D;
        if(t < 0.0 || (s + t) > 1.0)
            return new Disjointed(segment, this);
        return new PointIntersection(segment, this, p);
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Triangle other = (Triangle) obj;
        if (!Arrays.deepEquals(this.points, other.points)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 23 * hash + Arrays.deepHashCode(this.points);
        return hash;
    }

    @Override
    public String toString() {
        StringBuilder buffer = new StringBuilder();
        buffer.append(this.getClass().getName()).append('{');
        for(int index = 0; index < this.segments.length; ++index) {
            buffer.append("segment[").append(index).append("]=");
            buffer.append(this.segments[index]);
            if(index < 2)
                buffer.append(", ");
        }
        buffer.append(",area:").append(this.area);
        buffer.append(",plane:").append(this.plane).append('}');
        return buffer.toString();
    }
}
