/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "Epsilon.h"

Epsilon::Epsilon() {
    this->precision = BINARY16_PRECISION;
}

Epsilon::Epsilon(double precision) {
    this->precision = precision;
}

Epsilon::Epsilon(const Epsilon& source) {
    this->precision = source.precision;
}

bool Epsilon::isLessThan(float value) {
    return (value <= this->precision);
}

double Epsilon::getPrecision() {
    return this->precision;
}

Epsilon::~Epsilon() {
}

