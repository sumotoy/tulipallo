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

#include "PIDAttitude.h"

PIDAttitude::PIDAttitude() {
    this->headingController = new PIDController();
    this->pitchController   = new PIDController();
    this->rollController    = new PIDController();
}

void PIDAttitude::setControlPoint(Attitude* iatt) {
    this->headingController->setControlPoint(iatt->getHeading());
    this->pitchController->setControlPoint(iatt->getPitch());
    this->rollController->setControlPoint(iatt->getRoll());
}

void PIDAttitude::calculate(Attitude* iatt, Attitude* oatt, 
                            unsigned long long dt) {
    iatt->setHeading(this->headingController->calculate(
            oatt->getHeading(), dt));
    iatt->setPitch(this->pitchController->calculate(
            oatt->getPitch(), dt));
    iatt->setRoll(this->rollController->calculate(
            oatt->getRoll(), dt));
}

PIDController* PIDAttitude::getHeadingController() {
    return this->headingController;
}

PIDController* PIDAttitude::getPitchController() {
    return this->pitchController;
}

PIDController* PIDAttitude::getRollController() {
    return this->rollController;
}

PIDAttitude::~PIDAttitude() {
    delete this->headingController;
    delete this->pitchController;
    delete this->rollController;
}

