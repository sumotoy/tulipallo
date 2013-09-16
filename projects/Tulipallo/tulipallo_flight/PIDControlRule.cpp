/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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

