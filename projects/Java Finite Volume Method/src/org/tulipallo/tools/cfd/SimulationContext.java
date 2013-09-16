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

import org.tulipallo.tools.util.Epsilon;
import org.tulipallo.tools.util.Precision;

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
public class SimulationContext extends Context {
    private static final SimulationContext singleton = new SimulationContext();

    private Epsilon epsilon;

    private final Object epsilonMutex = new Object();

    private SimulationContext() {
        this.epsilon = Precision.SINGLE_PRECISION_BINARY32.epsilon;
    }

    public static SimulationContext getInstance() {
        return singleton;
    }

    public Epsilon getEpsilon() {
        synchronized(this.epsilonMutex) {
            return this.epsilon;
        }
    }

    public void setEpsilonPrecision(final Precision precision) {
        if(precision == null)
            throw new IllegalArgumentException(
                    "Argument \"precision\" cannot be null.");
        synchronized(this.epsilonMutex) {
            this.epsilon = precision.epsilon;
        }
    }
}
