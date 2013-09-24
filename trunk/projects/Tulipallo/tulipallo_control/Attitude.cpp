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

