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

#include "XPlaneGyro.h"

XPlaneGyro::XPlaneGyro() {
    this->mutex = new pthread_mutex_t;
    Thread::initialize(this->mutex);
    this->attitude = new Attitude();
}

Attitude XPlaneGyro::getAttitude() {
    Thread::lock(this->mutex);
    Attitude local = Attitude(this->attitude->getHeading(), 
            this->attitude->getPitch(), this->attitude->getRoll());
    Thread::unlock(this->mutex);
    
    return local;
}

void XPlaneGyro::handleSentenceReceived(SentenceReceivedEvent event) {
    if(event.getSentence()->getCommand() == SITUATION_COMMAND) {
        SituationSentence* ssentence = (SituationSentence*)event.getSentence();
        
        Thread::lock(this->mutex);
        this->attitude->setHeading(ssentence->getHeadingTrue());
        this->attitude->setPitch(ssentence->getPitchDeg());
        this->attitude->setRoll(ssentence->getRollDeg());
        Thread::unlock(this->mutex);
    }
}

XPlaneGyro::~XPlaneGyro() {
    Thread::destroy(this->mutex);
    delete this->attitude;
    delete this->mutex;
}

extern "C" {
    IGyro* create(Context* context) {
        XPlaneGyro* xgyro = new XPlaneGyro();
        
        // TODO: Add to the exception listener as soon as Master Caution and Master Warning are added.
        MessageHandler::getInstance()->getMessageReciever()->addSentenceListener(xgyro);
        
        return xgyro;
    }
}