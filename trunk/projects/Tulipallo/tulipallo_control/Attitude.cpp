/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "Attitude.h"

Attitude::Attitude() {
    //
}

Attitude::Attitude(double heading, double pitch, double roll) {
    this->heading = heading;
    this->pitch   = pitch;
    this->roll    = roll;
}

Attitude::Attitude(const Attitude& orig) {
    this->copy(orig);
}

void Attitude::copy(const Attitude& orig) {
    this->heading = orig.heading;
    this->pitch   = orig.pitch;
    this->roll    = orig.roll;
}

void Attitude::setHeading(double heading) {
    this->heading = heading;
}

double Attitude::getHeading() {
    return this->heading;
}

void Attitude::setPitch(double pitch) {
    this->pitch = pitch;
}

double Attitude::getPitch() {
    return this->pitch;
}

void Attitude::setRoll(double roll) {
    this->roll = roll;
}

double Attitude::getRoll() {
    return this->roll;
}

Attitude::~Attitude() {
}

