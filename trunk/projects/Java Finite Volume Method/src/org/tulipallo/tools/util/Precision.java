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

package org.tulipallo.tools.util;

/**
 * Enumeration that represents the IEEE 754-2008 Machine Epsilon industry
 * accepted values.
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
public enum Precision {
    /**
     * Half precision BINARY16 machine epsilon with a value of 4.88E-04.
     * <p/>
     * Calculated from <tt>Math.pow(2, -11)</tt>.
     */
    HALF_PRECISION_BINARY16      (Math.pow(2, -11)),
    /**
     * Single precision BINARY32 machine epsilon with a value of 5.96E-08.
     * <p/>
     * Calculated from <tt>Math.pow(2, -24)</tt>.
     */
    SINGLE_PRECISION_BINARY32    (Math.pow(2, -24)),
    /**
     * Double precision BINARY64 machine epsilon with a value of 1.11E-16.
     * <p/>
     * Calculated from <tt>Math.pow(2, -53)</tt>.
     */
    DOUBLE_PRECISION_BINARY64    (Math.pow(2, -53)),
    /**
     * Quadrupal precision BINARY128 machine epsilon with a value of 9.63E-35.
     * <p/>
     * Calculated from <tt>Math.pow(2, -113)</tt>.
     */
    QUADRUPAL_PRECISION_BINARY128(Math.pow(2, -113));

    public final double  machineEpsilon;
    public final Epsilon epsilon;

    private Precision(final double machineEpsilon) {
        this.machineEpsilon = machineEpsilon;
        this.epsilon        = new Epsilon(machineEpsilon);
    }

    public double getMachineEpsilon() {
        return this.machineEpsilon;
    }

    public Epsilon getEpsilon() {
        return this.epsilon;
    }
}
