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
 * Utility class used to compare two double precision numbers for equality
 * within IEEE 754-2008 Machine Epsilon.
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
public class Epsilon {
    private final double machineEpsilon;

    /**
     * Creates an instance of <tt>Epsilon</tt> using the IEEE 754-2008 Single
     * precision BINARY32 machine epsilon with a value of 5.96E-08.
     */
    public Epsilon() {
        this(Precision.SINGLE_PRECISION_BINARY32);
    }

    /**
     * Creates an instance of <tt>Epsilon</tt>.
     *
     * @param macheps The IEEE 754-2008 standard machine machineEpsilon to use for
     *                this instance of <tt>Epsilon</tt>.
     *
     * @throws IllegalArgumentException if argument <tt>macheps</tt> is
     *                                  <tt>null</tt>.
     */
    public Epsilon(final Precision macheps) {
        if(macheps == null)
            throw new IllegalArgumentException(
                    "Argument \"macheps\" cannot be null.");
        this.machineEpsilon = macheps.machineEpsilon;
    }

    /**
     * Creates an instance of <tt>Epsilon</tt>.
     * 
     * @param macheps the custom machine machineEpsilon for this instance.
     */
    public Epsilon(final double macheps) {
        this.machineEpsilon = macheps;
    }

    /**
     * Compares <tt>d1</tt> and <tt>d2</tt> for equality within machine epsilon.
     * <p/>
     * <b>Formula:</b> <tt>Math.IEEEremainder(d1, d2) &lt;= machine epsilon</tt>
     *
     * @param d1 A double to check for equality.
     * @param d2 A double to check for equality.
     *
     * @return <tt>true</tt> if the difference in <tt>d1</tt> and <tt>d2</tt> is
     *         within (less than or equal too) machine machineEpsilon, <tt>false</tt>
     *         if not.
     */
    public boolean isEqual(final double d1, final double d2) {
        return this.isLessThan(Math.abs(d1 - d2));
    }

    /**
     * Checks that argument <tt>d</tt> is less than (&lt;=)
     * <tt>machineEpsilon</tt>.
     *
     * @param d The double to check against <tt>machineEpsilon</tt>.
     *
     * @return <tt>true</tt> if <tt>d</tt> is less than or equal to
     *         <tt>machineEpsilon</tt>, <tt>false</tt> if not.
     */
    public boolean isLessThan(final double d) {
        return d <= this.machineEpsilon;
    }

    /**
     * Checks that argument <tt>d</tt> is greater than (&gt;)
     * <tt>machineEpsilon</tt>.
     *
     * @param d The double to check agains <tt>machineEpsilon</tt>.
     *
     * @return <tt>true</tt> if <tt>d</tt> is grater than 
     *         <tt>machineEpsilon</tt>, <tt>false</tt> if not.
     */
    public boolean isGreaterThan(final double d) {
        return d > this.machineEpsilon;
    }

    /**
     * Returns the Maximum Reciprocal Length for this instance if
     * <tt>Epsilon</tt>.
     * <p/>
     * <code>1.0d / [machine_epsilon]</code>
     *
     * @return the Maximum Reciprocal Length for this instance if
     *         <tt>Epsilon</tt>.
     */
    public double getMaxReciprocalLength() {
        return 1.0d / this.machineEpsilon;
    }
}
