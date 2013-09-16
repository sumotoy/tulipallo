/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "PIDControllerZero.h"

PIDControllerZero::PIDControllerZero(FlightController* controller) : 
                IStateChangedListener() {
    this->controller  = controller;
}

void PIDControllerZero::handleStateChanged(StateChangedEvent event) {
    this->controller->getHeadingController()->reset();
    this->controller->getPitchController()->reset();
    this->controller->getRollController()->reset();
    this->controller->getYawController()->reset();
}

PIDControllerZero::~PIDControllerZero() {
}

