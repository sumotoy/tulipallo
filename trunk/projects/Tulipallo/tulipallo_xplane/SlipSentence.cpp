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

