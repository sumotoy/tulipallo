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

import java.util.Comparator;
import javax.vecmath.Point3d;
import org.tulipallo.tools.cfd.SimulationContext;

/**
 * Exception thrown if a plane is degenerate, meaning is a line.
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
public class LargestAxisComparator implements Comparator{
    private final Axis axis;

    public LargestAxisComparator(final Point3d[] points) {
        this.axis = Axis.getLargestAxis(points);
    }

    public Axis getAxis() {
        return this.axis;
    }

    @Override
    public int compare(final Object o1, final Object o2) {
        double d1 = this.axis.get((Point3d)o1);
        double d2 = this.axis.get((Point3d)o2);
        if(SimulationContext.getInstance().getEpsilon().isEqual(d1, d2))
            return 0;
        if(d1 < d2)
            return -1;
        return 1;
    }
}
