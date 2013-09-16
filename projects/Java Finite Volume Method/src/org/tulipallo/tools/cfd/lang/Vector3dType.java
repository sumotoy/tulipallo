/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2013 Tulipallo.org
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

import javax.vecmath.Vector3d;
import org.tulipallo.tools.cfd.entity.Type;

 /**
  * <p>Vector3dType</p>
  * 
  * <p><tt>Tulipallo - The Java Finite Area Method Simulation<br />
  * Copyright &copy; 2013, Tulipallo.org.</tt></p>
  * 
  * <p>For more information on jFVM and other Tulipallo projects please visit
  * <a href="http://www.tulipallo.org">http://www.tulipallo.org</a></p>
  * <p><tt>This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.</tt></p>
  * 
  * <p><tt>You should have received a copy of the GNU General Public License
  * along with this program.  If not, see 
  * <a href="http://www.gnu.org/licenses/">http://www.gnu.org/licenses</a>.</tt></p>
  *
  * @author murrellrr
  * @since Java 6
  * @version 1.0 beta
  */
public class Vector3dType extends Type {
    private static final String NAME  = "Vector3d";
    private static final String DELIM = ",";

    public Vector3dType() {
        super(NAME, Vector3d.class);
    }

    @Override
    public Object clone(final Object value) {
        Vector3d point = Vector3d.class.cast(value);
        return new Vector3d(point.x, point.y, point.z);
    }

    @Override
    public Object parse(final String value) {
        String[] values = value.split(DELIM);
        return new Vector3d(Double.valueOf(values[0]),
                           Double.valueOf(values[1]),
                           Double.valueOf(values[2]));
    }

    @Override
    public String valueOf(final Object value) {
        Vector3d point = Vector3d.class.cast(value);
        return point.x + DELIM + point.y + DELIM + point.z;
    }
}
