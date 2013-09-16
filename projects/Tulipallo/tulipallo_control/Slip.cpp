/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "Slip.h"

Slip::Slip() {
}

Slip::Slip(double slip) {
    this->slip = slip;
}

void Slip::copy(const Slip& orig) {
    this->slip = orig.slip;
}

double Slip::getSlip() {
    return this->slip;
}

void Slip::setSlip(double slip) {
    this->slip = slip;
}

Slip::~Slip() {
}

