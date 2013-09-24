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

