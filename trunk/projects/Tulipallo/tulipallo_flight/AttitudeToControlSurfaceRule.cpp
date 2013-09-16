/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "AttitudeToControlSurfaceRule.h"

AttitudeToControlSurfaceRule::AttitudeToControlSurfaceRule() {
}

void AttitudeToControlSurfaceRule::doCommand(ISituation* situation) {
    Attitude*               iatt = situation->getInputAttitude();
    Yaw*                    iyaw = situation->getInputYaw();
    ControlSurfacePosition* cpos = situation->getInputControlSurfacePosition();
    
    double dp = iatt->getPitch() / 10;
    double dr = iatt->getRoll() / 10;
    double dy = iyaw->getDegrees() / 10;
    
    cpos->setElevator(dp);
    cpos->setAileron(dr);
    cpos->setRudder(dy);
}

AttitudeToControlSurfaceRule::~AttitudeToControlSurfaceRule() {
}

