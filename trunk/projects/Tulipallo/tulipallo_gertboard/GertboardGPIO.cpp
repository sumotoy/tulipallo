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

#include "GertboardGPIO.h"

GertboardGPIO::GertboardGPIO(Pin* pin) : GPIO(pin) {
}

void GertboardGPIO::registerInterrupt(void (*callback)(void*), IO_INTERRUPT_EDGE edge) 
                throw (GPIOException) {
    int result = ::wiringPiISR(this->pin->getNumber(), edge, callback, this);
    if(result < 0) {
        throw GPIOException(
                "Exception registering for async IRQ with callback.");
    }
}

IO_STATE GertboardGPIO::getState() throw (GPIOException) {
    IO_STATE value = IO_LOW;
    
    int result = digitalRead(this->pin->getNumber());
    
    if(result != 0) {
        value = IO_HIGH;
    }
    
    return value;
}

void GertboardGPIO::setState(IO_STATE state) throw (GPIOException) {
    digitalWrite(this->pin->getNumber(), state);
}

void GertboardGPIO::waitForInterrupt() throw (GPIOException) {
    int result = ::waitForInterrupt(this->pin->getNumber(), -1);
    if(result < 0) {
        throw GPIOException(errno, "Exception registering for IRQ.");
    }
}

IO_INTERRUPT_STATE GertboardGPIO::waitForInterrupt(int timeOutMillis) 
                throw (GPIOException) {
    int result = ::waitForInterrupt(this->pin->getNumber(), timeOutMillis);
    if(result < 0) {
        throw GPIOException(errno, "Exception registering for IRQ.");
    }
    else if(result == 0) {
        return IO_TIMED_OUT;
    }
    else {
        return IO_INTERRUPTED;
    }
}

GertboardGPIO::~GertboardGPIO() {
}

