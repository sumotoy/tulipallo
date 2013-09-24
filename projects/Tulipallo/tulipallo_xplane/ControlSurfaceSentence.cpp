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

#include "ControlSurfaceSentence.h"

ControlSurfaceSentence::ControlSurfaceSentence() : XPlaneSentence() {
    //
}

ControlSurfaceSentence::ControlSurfaceSentence(float elevator, float aileron, 
                                               float rudder)  : XPlaneSentence() {
    this->elevator = elevator;
    this->aileron  = aileron;
    this->rudder   = rudder;
}

ControlSurfaceSentence::ControlSurfaceSentence(const ControlSurfaceSentence& orig)  : XPlaneSentence(orig) {
    this->elevator = orig.elevator;
    this->aileron  = orig.aileron;
    this->rudder   = orig.rudder;
}

float ControlSurfaceSentence::getElevator() {
    return this->elevator;
}

float ControlSurfaceSentence::getAileron() {
    return this->aileron;
}

float ControlSurfaceSentence::getRudder() {
    return this->rudder;
}

int ControlSurfaceSentence::getCommand() {
    return SURFACE_COMMAND;
}

void ControlSurfaceSentence::unmarshall(DataStream* stream) throw (MarshallingException) {
    this->elevator = stream->getFloat();
    this->aileron  = stream->getFloat();
    this->rudder   = stream->getFloat();
    stream->skip(20);
}

void ControlSurfaceSentence::marshall(DataStream* stream) throw (MarshallingException) {
    XPlaneSentence::marshall(stream);
    
    stream->setFloat(this->elevator);
    stream->setFloat(this->aileron);
    stream->setFloat(this->rudder);
    stream->setFloat(-999.0f);
    stream->setFloat(0);
    stream->setFloat(0);
    stream->setFloat(0);
    stream->setFloat(0);
}

std::string ControlSurfaceSentence::toString() {
    std::stringstream output;
    
    output << "ControlSurfaceSentence: elevator=" << this->elevator 
           << ", aileron="                        << this->aileron 
           << ", rudder="                         << this->rudder << "\r\n";
    
    return output.str();
}

ControlSurfaceSentence::~ControlSurfaceSentence() {
}

