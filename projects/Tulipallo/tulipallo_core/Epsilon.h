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

#ifndef EPSILON_H
#define	EPSILON_H

#include <math.h>

const double BINARY16_PRECISION  = pow(2, -11);
const double BINARY32_PRECISION  = pow(2, -24);
const double BINARY64_PRECISION  = pow(2, -53);
const double BINARY128_PRECISION = pow(2, -113);

/**
 * <p/>
 * <tt>Tulipallo - The Java Finite Volume Method Simulation<br />
 * Copyright &copy; 2010 M2 Astronautics<br />
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
 * @version 1.0 beta
 */
class Epsilon {
public:
    Epsilon();
    Epsilon(double precision);
    Epsilon(const Epsilon& source);
    
    virtual double getPrecision();
    virtual bool isLessThan(float value);
    
    virtual ~Epsilon();
private:
    double precision;
};

#endif	/* EPSILON_H */

