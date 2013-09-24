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

