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
#include "ControlSurfacePosition.h"

ControlSurfacePosition::ControlSurfacePosition() {
    this->limit = DEFAULT_LIMIT;
}

ControlSurfacePosition::ControlSurfacePosition(float elevator, float aileron, 
                                               float rudder) {
    this->elevator = elevator;
    this->aileron  = aileron;
    this->rudder   = rudder;
}

ControlSurfacePosition::ControlSurfacePosition(float elevator, float aileron, 
                                               float rudder, float limit) {
    this->elevator = elevator;
    this->aileron  = aileron;
    this->rudder   = rudder;
    this->limit    = limit;
}

ControlSurfacePosition::ControlSurfacePosition(const ControlSurfacePosition& orig) {
    this->copy(orig);
}

void ControlSurfacePosition::copy(const ControlSurfacePosition& orig) {
    this->elevator = orig.elevator;
    this->aileron  = orig.aileron;
    this->rudder   = orig.rudder;
    this->limit    = orig.limit;
}

float ControlSurfacePosition::getElevator() {
    return this->elevator;
}

float ControlSurfacePosition::getAileron() {
    return this->aileron;
}

float ControlSurfacePosition::getRudder() {
    return this->rudder;
}

float ControlSurfacePosition::getLimit() {
    return this->limit;
}

void ControlSurfacePosition::setLimit(float limit) {
    this->limit = limit;
}

double ControlSurfacePosition::limitValue(float value) {
    if(value > this->limit)
        return this->limit;
    else {
        if(value < -this->limit) {
            return -this->limit;
        }
        else {
            return value;
        }
    }
}

void ControlSurfacePosition::setElevator(float elevator) {
    this->elevator = this->limitValue(elevator);
}

void ControlSurfacePosition::setAileron(float aileron) {
    this->aileron = this->limitValue(aileron);
}

void ControlSurfacePosition::setRudder(float rudder) {
    this->rudder = this->limitValue(rudder);
}

ControlSurfacePosition::~ControlSurfacePosition() {
}

