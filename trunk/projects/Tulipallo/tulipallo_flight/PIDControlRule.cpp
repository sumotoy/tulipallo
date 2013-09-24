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

#include "PIDControlRule.h"

PIDControlRule::PIDControlRule() {
    this->pattitude     = new PIDAttitude();
    this->yawController = new PIDController();
}

PIDController* PIDControlRule::getHeadingController() {
    return this->pattitude->getHeadingController();
}

PIDController* PIDControlRule::getRollController() {
    return this->pattitude->getRollController();
}

PIDController* PIDControlRule::getPitchController() {
    return this->pattitude->getPitchController();
}

PIDController* PIDControlRule::getYawController() {
    return this->yawController;
}

/**
 * TODO: Set for fast control output on preemted situations.
 * 
 * @param situation
 */
void PIDControlRule::doCommand(ISituation* situation) {
    Attitude* iatt = situation->getInputAttitude();
    Yaw*      iyaw = situation->getInputYaw();
    Slip*     slip = situation->getSlip();
    
    this->pattitude->setControlPoint(iatt);
    this->yawController->setControlPoint(iyaw->getDegrees());
    this->pattitude->calculate(iatt, situation->getAttitude(), 1);
    iyaw->setDegrees(this->yawController->calculate(slip->getSlip(), 1));
}

PIDControlRule::~PIDControlRule() {
    delete this->pattitude;
    delete this->yawController;
}

