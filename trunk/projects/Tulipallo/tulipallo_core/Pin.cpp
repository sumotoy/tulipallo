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

#include "Pin.h"

Pin::Pin(const Pin& orig) {
    this->number = orig.number;
    this->mode   = orig.mode;
    this->pull   = orig.pull;
}

Pin::Pin(unsigned int number, IO_MODE mode) {
    this->number = number;
    this->mode   = mode;
    this->pull   = IO_PULL_OFF;
}

Pin::Pin(unsigned int number, IO_MODE mode, IO_PULL pull) {
    this->number = number;
    this->mode   = mode;
    this->pull   = pull;
}

unsigned int Pin::getNumber() {
    return this->number;
}

IO_MODE Pin::getMode() {
    return this->mode;
}

IO_PULL Pin::getPull() {
    return this->pull;
}

/**
 * Compares this <tt>Pin</tt> to another using only the <tt>number</tt> 
 * attribute.
 *  
 * @param other <tt>true</tt> if this number is less than <tt>other.number</tt>, 
 *              <tt>false</tt> otherwise.
 * 
 * @return 
 */
bool Pin::operator < (const Pin& other) const {
    if(this->number < other.number) {
        return true;
    }
    return false;
}

Pin::~Pin() {
}

