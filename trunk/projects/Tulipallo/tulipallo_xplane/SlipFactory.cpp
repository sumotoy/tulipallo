/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "SlipFactory.h"

SlipFactory::SlipFactory() : SentenceFactory() {
}

XPlaneSentence* SlipFactory::newInstance() throw (MarshallingException) {
    return new SlipSentence();
}

bool SlipFactory::isFactory(int command) {
    return (SLIP_COMMAND == command);
}

SlipFactory::~SlipFactory() {
}

