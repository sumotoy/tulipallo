/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "ControlSurfaceFactory.h"

ControlSurfaceFactory::ControlSurfaceFactory() : SentenceFactory() {
}

XPlaneSentence* ControlSurfaceFactory::newInstance() throw (MarshallingException) { 
    return new ControlSurfaceSentence();
}

bool ControlSurfaceFactory::isFactory(int command) {
    return (SURFACE_COMMAND == command);
}

ControlSurfaceFactory::~ControlSurfaceFactory() {
}

