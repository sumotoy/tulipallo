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

import java.util.ArrayList;
import java.util.Collection;
import java.util.Set;
import javax.vecmath.Point3d;

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
public class TriangleList <T extends Triangle> extends ArrayList<T> {
    private Set<Point3d> points;

    @Override
    public boolean add(final T e) {
        return super.add(e);
    }

    @Override
    public void add(final int index, final T element) {
        super.add(index, element);
    }

    @Override
    public boolean addAll(final Collection<? extends T> c) {
        return super.addAll(c);
    }

    @Override
    public boolean addAll(final int index, final Collection<? extends T> c) {
        return super.addAll(index, c);
    }

    @Override
    public T remove(final int index) {
        return super.remove(index);
    }

    @Override
    public boolean remove(final Object o) {
        return super.remove(o);
    }

    @Override
    public boolean removeAll(final Collection<?> c) {
        return super.removeAll(c);
    }

    @Override
    protected void removeRange(final int fromIndex, final int toIndex) {
        super.removeRange(fromIndex, toIndex);
    }

    @Override
    public boolean retainAll(final Collection<?> c) {
        return super.retainAll(c);
    }

    @Override
    public T set(final int index, final T element) {
        return super.set(index, element);
    }
}
