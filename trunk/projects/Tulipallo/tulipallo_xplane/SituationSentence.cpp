/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "SituationSentence.h"

SituationSentence::SituationSentence()  : XPlaneSentence() {
    //
}

SituationSentence::SituationSentence(float pitchDeg, float rollDeg, 
                                     float headingTrue, float headingMag) {
    this->pitchDeg    = pitchDeg;
    this->rollDeg     = rollDeg;
    this->headingTrue = headingTrue;
    this->headingMag  = headingMag;
}

SituationSentence::SituationSentence(const SituationSentence& orig) {
    this->pitchDeg    = orig.pitchDeg;
    this->rollDeg     = orig.rollDeg;
    this->headingTrue = orig.headingTrue;
    this->headingMag  = orig.headingMag;
}

float SituationSentence::getPitchDeg() {
    return this->pitchDeg;
}

float SituationSentence::getRollDeg() {
    return this->rollDeg;
}

float SituationSentence::getHeadingTrue() {
    return this->headingTrue;
}

float SituationSentence::getHeadingMag() {
    return this->headingMag;
}

int SituationSentence::getCommand() {
    return SITUATION_COMMAND;
}

void SituationSentence::unmarshall(DataStream* stream) 
                throw (MarshallingException) {
    this->pitchDeg    = stream->getFloat();
    this->rollDeg     = stream->getFloat();
    this->headingTrue = stream->getFloat();
    this->headingMag  = stream->getFloat();
    stream->skip(16);
}

void SituationSentence::marshall(DataStream* stream) 
            throw (MarshallingException) {
    XPlaneSentence::marshall(stream);
    
    stream->setFloat(this->pitchDeg);
    stream->setFloat(this->rollDeg);
    stream->setFloat(this->headingTrue);
    stream->setFloat(this->headingMag);
    stream->setFloat(0.0f);
    stream->setFloat(0.0f);
    stream->setFloat(0.0f);
    stream->setFloat(0.0f);
}

std::string SituationSentence::toString() {
    std::stringstream output;
    
    output << "SituationSentence: pitch=" << this->pitchDeg 
           << ", roll="                   << this->rollDeg 
           << ", heading-true="           << this->headingTrue 
           << ", heading-mag="            << this->headingMag << "\r\n";
    
    return output.str();
}

SituationSentence::~SituationSentence() {
}

