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
import org.tulipallo.tools.cfd.geometry.Axis;
import org.tulipallo.tools.cfd.geometry.Triangle;
import org.tulipallo.tools.cfd.geometry.collision.Disjointed;
import org.tulipallo.tools.cfd.geometry.collision.IntersectionResult;
import java.util.ArrayList;
import java.util.List;
import javax.vecmath.Point3d;
import org.tulipallo.tools.cfd.geometry.collision.Coincident;
import org.tulipallo.tools.cfd.geometry.collision.SegmentIntersection;
import org.tulipallo.tools.cfd.geometry.collision.SubjectIntersection;

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
public class Target implements Identifiable {
    private List<Triangle> triangles;
    private String         name;
    private long           id;
    
    public Target() {
        this.triangles = new ArrayList();
    }

    public Target(final String name, final List<Triangle> triangles) {
        this();
        this.name = name;
        this.triangles.clear();
        this.triangles.addAll(triangles);
    }

    public String getName() {
        return this.name;
    }

    public void setName(final String name) {
        this.name = name;
    }

    @Override
    public long getId() {
        return this.id;
    }

    @Override
    public void setId(final long id) {
        this.id = id;
    }

    public List<Triangle> getTriangles() {
        return Collections.unmodifiableList(this.triangles);
    }

    public static List<Triangle> move(final List<Triangle> triangles,
                                      final Axis axis, final double d) {
        for(Triangle triangle : triangles) {
            for(Point3d point : triangle.getPoints()) {
                if(axis == Axis.X)
                    point.x += d;
                if(axis == Axis.Y)
                    point.y += d;
                if(axis == Axis.Z)
                    point.z += d;
            }
        }
        return triangles;
    }

    public IntersectionResult getIntersection(final Target subject) {
        if(subject == null)
            return new Disjointed(subject, this);
        List<IntersectionResult> results =
                new ArrayList<IntersectionResult>();
        for(Triangle st : subject.triangles) {
            for(Triangle tt : this.triangles) {
                IntersectionResult result = tt.getIntersection(st);
                if(result instanceof SegmentIntersection)
                    results.add(new SegmentIntersection(st, tt,
                            ((SegmentIntersection)result).segment));
                if(result instanceof Coincident)
                    results.add(result);
            }
        }
        if(results.isEmpty())
            return new Disjointed(subject, this);
        return new SubjectIntersection(subject, this, results);
    }
    
    public boolean intersects(final Target subject) { 
        return !(this.getIntersection(subject) instanceof Disjointed);
    }
}
