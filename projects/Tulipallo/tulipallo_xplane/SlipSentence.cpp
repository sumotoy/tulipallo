/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "SlipSentence.h"

SlipSentence::SlipSentence() : XPlaneSentence() {
}

SlipSentence::SlipSentence(float slip) : XPlaneSentence() {
    this->slip = slip;
}

SlipSentence::SlipSentence(const SlipSentence& orig) : XPlaneSentence() {
    this->slip = orig.slip;
}

int SlipSentence::getCommand() {
    return SLIP_COMMAND;
}

float SlipSentence::getSlip() {
    return this->slip;
}

void SlipSentence::setSlip(float slip) {
    this->slip = slip;
}

void SlipSentence::unmarshall(DataStream* stream) throw (MarshallingException) {
    stream->skip(28);
    this->slip = stream->getFloat();
}

void SlipSentence::marshall(DataStream* stream) throw (MarshallingException) {
    XPlaneSentence::marshall(stream);
    stream->setFloat(0);
    stream->setFloat(0);
    stream->setFloat(0);
    stream->setFloat(0);
    stream->setFloat(0);
    stream->setFloat(0);
    stream->setFloat(0);
    stream->setFloat(this->slip);
}

std::string SlipSentence::toString() {
    std::stringstream output;
    
    output << "SlipSentence: slip=" << this->slip << "\r\n";
    
    return output.str();
}

SlipSentence::~SlipSentence() {
}

