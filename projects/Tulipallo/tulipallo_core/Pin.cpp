/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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

