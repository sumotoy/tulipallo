/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "GPIOFactorySingleton.h"

GPIOFactorySingleton* GPIOFactorySingleton::factory = NULL;

GPIOFactorySingleton::GPIOFactorySingleton(IGPIOFactoryProvider* provider) {
    this->gpiopins  = new std::map<Pin*, GPIO*>();
    this->gpioMutex = new pthread_mutex_t();
    Thread::initialize(this->gpioMutex);
    
    this->provider = provider;
    this->provider->initialize();
}

void GPIOFactorySingleton::create(IGPIOFactoryProvider* provider) {
   factory = new GPIOFactorySingleton(provider);
}

void GPIOFactorySingleton::destroy() {
   delete factory;
}

IGPIOFactory* GPIOFactorySingleton::getInstance() {
   return factory;
}

GPIO* GPIOFactorySingleton::registerGPIO(Pin* pin) throw (GPIOException) {
    Thread::lock(this->gpioMutex);
    
    GPIO* gpio;
    
    try {
        gpio = this->gpiopins->at(pin);
        // Checking to see if the modes do not interfere...
        if(gpio->getPin()->getMode() != pin->getMode()) {
            throw IllegalStateException("Invalid or conflicting GPIO Mode.");
        }
    }
    catch(std::out_of_range a) {
        Pin* kpin = new Pin(pin->getNumber(), pin->getMode());
        gpio = this->provider->create(pin);
        this->gpiopins->insert(std::pair<Pin*, GPIO*>(kpin, gpio));
    }
    
    Thread::unlock(this->gpioMutex);
    
    return gpio;
}

GPIOFactorySingleton::~GPIOFactorySingleton() {
    Thread::destroy(this->gpioMutex);
    
    // Loop through and destroy the GPIO and Pins...
    
    delete this->gpioMutex;
}

