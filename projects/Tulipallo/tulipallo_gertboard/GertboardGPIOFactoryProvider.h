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

#ifndef GERTBOARDGPIOFACTORYPROVIDER_H
#define	GERTBOARDGPIOFACTORYPROVIDER_H

#include <wiringPi.h>
#include "GertboardGPIO.h"
#include "../tulipallo_core/GPIO.h"
#include "../tulipallo_core/IGPIOFactoryProvider.h"
#include "../tulipallo_core/Pin.h"
#include "../tulipallo_core/Context.h"

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
class GertboardGPIOFactoryProvider : public IGPIOFactoryProvider {
public:
    GertboardGPIOFactoryProvider();
    
    virtual void  initialize() throw (GPIOException);
    virtual GPIO* create(Pin* pin) throw (GPIOException);
    
    virtual ~GertboardGPIOFactoryProvider();
private:

};

#endif	/* GERTBOARDGPIOFACTORYPROVIDER_H */

