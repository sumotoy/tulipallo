/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "SpeedFactory.h"

SpeedFactory::SpeedFactory() : SentenceFactory() {
}

XPlaneSentence* SpeedFactory::newInstance()  throw (MarshallingException){ 
    return new SpeedSentence();
}

bool SpeedFactory::isFactory(int command) {
    return (SPEED_COMMAND == command);
}

SpeedFactory::~SpeedFactory() {
}

