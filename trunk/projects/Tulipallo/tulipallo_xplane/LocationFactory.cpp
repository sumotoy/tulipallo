/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "LocationFactory.h"

LocationFactory::LocationFactory() : SentenceFactory() {
}

XPlaneSentence* LocationFactory::newInstance() throw (MarshallingException) { 
    return new LocationSentence();
}

bool LocationFactory::isFactory(int command) {
    return (LOCATION_COMMAND == command);
}

LocationFactory::~LocationFactory() {
}

