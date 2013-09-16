/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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

