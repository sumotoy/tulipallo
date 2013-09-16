/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "FlightControllerActivator.h"

FlightControllerActivator::FlightControllerActivator(
                                FlightController* controller, GPIO* gpio, 
                                MessageTransmitter* tx) : 
                IStateChangedListener() {
    this->controller  = controller;
    this->gpio        = gpio;
    this->cp          = new ControlSurfaceSentence(-999.0, -999.0, -999.0);
    this->tx          = tx;
    this->state       = false;
}

void FlightControllerActivator::handleStateChanged(StateChangedEvent event) {
    
    if(this->state == false) {
        this->gpio->setState(IO_HIGH);
        this->controller->setEnabled(true);
        this->state = true;
    }
    else {
        this->gpio->setState(IO_LOW);
        this->controller->setEnabled(false);
        this->state = false;
        this->tx->queue(this->cp);
        this->tx->send();
    }
}

FlightControllerActivator::~FlightControllerActivator() {
    delete this->cp;
}

