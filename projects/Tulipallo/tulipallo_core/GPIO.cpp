/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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

