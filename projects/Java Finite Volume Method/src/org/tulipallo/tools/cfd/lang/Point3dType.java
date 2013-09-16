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

package org.tulipallo.tools.cfd.lang;

import javax.vecmath.Point3d;
import org.tulipallo.tools.cfd.entity.Type;

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
public class Point3dType extends Type {
    private static final String NAME  = "Point3d";
    private static final String DELIM = ",";

    public Point3dType() {
        super(NAME, Point3d.class);
    }

    @Override
    public Object clone(final Object value) {
        Point3d point = Point3d.class.cast(value);
        return new Point3d(point.x, point.y, point.z);
    }

    @Override
    public Object parse(final String value) {
        String[] values = value.split(DELIM);
        return new Point3d(Double.valueOf(values[0]),
                           Double.valueOf(values[1]),
                           Double.valueOf(values[2]));
    }

    @Override
    public String valueOf(final Object value) {
        Point3d point = Point3d.class.cast(value);
        return point.x + DELIM + point.y + DELIM + point.z;
    }
}
