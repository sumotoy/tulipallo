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

#include "XPlaneGPS.h"

XPlaneGPS::XPlaneGPS() {
    this->mutex = new pthread_mutex_t;
    Thread::initialize(this->mutex);
    this->position = new Position();
}

Position XPlaneGPS::getPosition() {
    Thread::lock(this->mutex);
    Position local = Position(this->position->getLatitude(), 
            this->position->getLongitude(), this->position->getAltitude());
    Thread::unlock(this->mutex);
    
    return local;
}

void XPlaneGPS::handleSentenceReceived(SentenceReceivedEvent event) {
    if(event.getSentence()->getCommand() == LOCATION_COMMAND) {
        LocationSentence* lsentence = (LocationSentence*)event.getSentence();
        
        Thread::lock(this->mutex);
        this->position->setAltitude(lsentence->getAltFtmsl());
        this->position->setLatitude(lsentence->getLatDeg());
        this->position->setLongitude(lsentence->getLonDeg());
        Thread::unlock(this->mutex);
    }
}

XPlaneGPS::~XPlaneGPS() {
    Thread::destroy(this->mutex);
    delete this->position;
    delete this->mutex;
}

extern "C" {
    IGPS* create(Context* context) {
        XPlaneGPS* xgps = new XPlaneGPS();
        
        // TODO: Add to the exception listener as soon as Master Caution and Master Warning are added.
        MessageHandler::getInstance()->getMessageReciever()->addSentenceListener(xgps);
        
        return xgps;
    }
}