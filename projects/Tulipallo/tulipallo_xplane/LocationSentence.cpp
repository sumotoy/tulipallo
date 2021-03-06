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

#include "LocationSentence.h"

LocationSentence::LocationSentence()  : XPlaneSentence() {
    //
}

LocationSentence::LocationSentence(float latDeg, float lonDeg, float altFtmsl, 
                                   float altFtagl, bool  onRunway, float altInd, 
                                   float latSouth, float lonWest) {
    this->altFtagl = altFtagl;
    this->altFtmsl = altFtmsl;
    this->altInd   = altInd;
    this->latDeg   = latDeg;
    this->latSouth = latSouth;
    this->lonDeg   = lonDeg;
    this->lonWest  = lonWest;
    this->onRunway = onRunway;
}

LocationSentence::LocationSentence(const LocationSentence& orig) {
    this->altFtagl = orig.altFtagl;
    this->altFtmsl = orig.altFtmsl;
    this->altInd   = orig.altInd;
    this->latDeg   = orig.latDeg;
    this->latSouth = orig.latSouth;
    this->lonDeg   = orig.lonDeg;
    this->lonWest  = orig.lonWest;
    this->onRunway = orig.onRunway;
}

float LocationSentence::getLatDeg() {
    return this->latDeg;
}

float LocationSentence::getLonDeg() {
    return this->lonDeg;
}

float LocationSentence::getAltFtmsl() {
    return this->altFtmsl;
}

float LocationSentence::getAltFtagl() {
    return this->altFtagl;
}

bool  LocationSentence::isOnRunway() {
    return this->onRunway;
}

float LocationSentence::getAltInd() {
    return this->altInd;
}

float LocationSentence::getLatSouth() {
    return this->latSouth;
}

float LocationSentence::getLonWest() {
    return this->lonWest;
}

int LocationSentence::getCommand() {
    return LOCATION_COMMAND;
}

void LocationSentence::unmarshall(DataStream* stream) 
                throw (MarshallingException) {
    this->latDeg   = stream->getFloat();
    this->lonDeg   = stream->getFloat();
    this->altFtmsl = stream->getEpsilonFloat();
    this->altFtagl = stream->getEpsilonFloat();
    this->onRunway = (bool)stream->getEpsilonFloat();
    this->altInd   = stream->getEpsilonFloat();
    this->latSouth = stream->getFloat();
    this->lonWest  = stream->getFloat();
}

void LocationSentence::marshall(DataStream* stream) 
            throw (MarshallingException) {
    XPlaneSentence::marshall(stream);
    
    stream->setFloat(this->latDeg);
    stream->setFloat(this->lonDeg);
    stream->setFloat(this->altFtmsl);
    stream->setFloat(this->altFtagl);
    stream->setFloat((int)this->onRunway);
    stream->setFloat(this->altInd);
    stream->setFloat(this->latSouth);
    stream->setFloat(this->lonWest);
}

std::string LocationSentence::toString() {
    std::stringstream output;
    
    output << "LocationSentence: lat-deg=" << this->latDeg 
           << ", lon-deg="                 << this->lonDeg 
           << ", alt-ftmsl="               << this->altFtmsl 
           << ", alt-ftagl="               << this->altFtagl 
           << ", on runway="               << this->onRunway 
           << ", alt-ind="                 << this->altInd 
           << ", lat-south="               << this->latSouth 
           << ", lon-west="                << this->lonWest << "\r\n";
    
    return output.str();
}

LocationSentence::~LocationSentence() {
}

