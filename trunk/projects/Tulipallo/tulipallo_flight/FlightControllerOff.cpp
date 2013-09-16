/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "FlightControllerOff.h"

FlightControllerOff::FlightControllerOff(FlightController* controller) {
    this->controller = controller;
}

void FlightControllerOff::handleStateChanged(StateChangedEvent event) {
    this->controller->off();
}

FlightControllerOff::~FlightControllerOff() {
}

