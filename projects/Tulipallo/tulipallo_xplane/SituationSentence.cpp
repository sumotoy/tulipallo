/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2010 M2 Astronautics
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 *
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

