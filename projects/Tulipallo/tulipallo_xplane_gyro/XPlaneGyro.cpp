/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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