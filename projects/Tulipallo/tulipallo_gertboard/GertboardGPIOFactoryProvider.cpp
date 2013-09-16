/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "GertboardGPIOFactoryProvider.h"

GertboardGPIOFactoryProvider::GertboardGPIOFactoryProvider() {
}

void GertboardGPIOFactoryProvider::initialize() 
                throw (GPIOException) {
    ::wiringPiSetup();
}

GPIO* GertboardGPIOFactoryProvider::create(Pin* pin) 
                throw (GPIOException) {
    ::pinMode(pin->getNumber(), pin->getMode());
    ::pullUpDnControl(pin->getNumber(), pin->getPull());
    return new GertboardGPIO(pin);
}

GertboardGPIOFactoryProvider::~GertboardGPIOFactoryProvider() {
}

extern "C" {
    IGPIOFactoryProvider* create(Context* context) {
        IGPIOFactoryProvider* iofactory = new GertboardGPIOFactoryProvider();
        
        return iofactory;
    }
}