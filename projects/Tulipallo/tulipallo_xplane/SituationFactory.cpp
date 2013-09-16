/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "SituationFactory.h"

SituationFactory::SituationFactory() : SentenceFactory() {
}

XPlaneSentence* SituationFactory::newInstance() throw (MarshallingException) {
    return new SituationSentence();
}

bool SituationFactory::isFactory(int command) {
    return (SITUATION_COMMAND == command);
}

SituationFactory::~SituationFactory() {
}

