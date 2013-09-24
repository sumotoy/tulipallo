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

#include "GPIO.h"

GPIO::GPIO(Pin* pin) {
    this->pin       = pin;
    this->event     = new StateChangedEvent(this);
    this->listeners = new std::list<IStateChangedListener*>();
    this->mutex     = new pthread_mutex_t();
    Thread::initialize(this->mutex);
}

Pin* GPIO::getPin() {
    return this->pin;
}

bool GPIO::isInterruptable() {
    return this->interruptable;
}

void GPIO::setInterruptable() {
    this->registerInterrupt(interrupted, IO_EDGE_FALLING);
    this->interruptable = true;
}

void GPIO::addStateChangedListener(IStateChangedListener* listener) {
    Thread::lock(this->mutex);
    this->listeners->push_back(listener);
    Thread::unlock(this->mutex);
}

void GPIO::removeStateChangedListener(IStateChangedListener* listener) {
    Thread::lock(this->mutex);
    this->listeners->remove(listener);
    Thread::unlock(this->mutex);
}

void GPIO::handleInterrupted() {
    Thread::lock(this->mutex);
    for (std::list<IStateChangedListener*>::iterator it = 
            this->listeners->begin(); it != this->listeners->end(); ++it) {
        (*it)->handleStateChanged(this->event);
    }
    Thread::unlock(this->mutex);
}

GPIO::~GPIO() {
    Thread::destroy(this->mutex);
    
    delete this->mutex;
    delete this->listeners;
    delete this->event;
}

