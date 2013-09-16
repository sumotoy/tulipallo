/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "LevelFlightGuidanceRule.h"

LevelFlightGuidanceRule::LevelFlightGuidanceRule() : Rule() {
}

void LevelFlightGuidanceRule::doCommand(ISituation* situation) {
    Attitude* iatt = situation->getInputAttitude();
    Yaw*      iyaw = situation->getInputYaw();
    
    situation->setPreempted(true);
    iatt->setPitch(0);
    iatt->setRoll(0);
    iatt->setHeading(situation->getAttitude()->getHeading());
    
    iyaw->setDegrees(0);
}

LevelFlightGuidanceRule::~LevelFlightGuidanceRule() {
}

