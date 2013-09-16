/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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