/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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

