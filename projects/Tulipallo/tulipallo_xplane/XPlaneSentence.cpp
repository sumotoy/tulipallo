/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "XPlaneSentence.h"

XPlaneSentence::XPlaneSentence() {
    //
}

XPlaneSentence::XPlaneSentence(const XPlaneSentence& orig) {
    //
}

std::string XPlaneSentence::toString() {
    return "XPlaneSentence::toString()\r";
}

void XPlaneSentence::marshall(DataStream* stream) 
                throw (MarshallingException) {
    stream->setByte(this->getCommand());
    stream->setByte(0);
    stream->setByte(0);
    stream->setByte(0);
}

XPlaneSentence::~XPlaneSentence() {
}

