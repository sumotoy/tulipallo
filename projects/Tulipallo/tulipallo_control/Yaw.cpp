/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "Yaw.h"

Yaw::Yaw() {
}

Yaw::Yaw(double degrees) {
    this->degrees = degrees;
}

void Yaw::copy(const Yaw& orig) {
    this->degrees = orig.degrees;
}

double Yaw::getDegrees() {
    return this->degrees;
}

void Yaw::setDegrees(double degrees) {
    this->degrees = degrees;
}

Yaw::~Yaw() {
}

