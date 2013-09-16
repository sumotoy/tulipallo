/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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

