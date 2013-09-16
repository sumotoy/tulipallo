/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "XPlaneControlSurface.h"

XPlaneControlSurface::XPlaneControlSurface(MessageTransmitter* tx) {
    this->mutex = new pthread_mutex_t();
    Thread::initialize(this->mutex);
    this->position = new ControlSurfacePosition();
    
    this->tx = tx;
}

ControlSurfacePosition XPlaneControlSurface::getPosition() {
    Thread::lock(this->mutex);
    ControlSurfacePosition local = ControlSurfacePosition(
            this->position->getElevator(), this->position->getAileron(), 
            this->position->getRudder());
    Thread::unlock(this->mutex);
    
    return local;
}

void XPlaneControlSurface::setPosition(ControlSurfacePosition* position) {
    ControlSurfaceSentence* s = new ControlSurfaceSentence(
            position->getElevator(), position->getAileron(), 
            position->getRudder());
    
    this->tx->queue(s);
    this->tx->send();
    
    delete s;
}

void XPlaneControlSurface::handleSentenceReceived(SentenceReceivedEvent event) {
    if(event.getSentence()->getCommand() == SURFACE_COMMAND) {
        ControlSurfaceSentence* csentence = (ControlSurfaceSentence*)event.getSentence();
        
        Thread::lock(this->mutex);
        this->position->setAileron(csentence->getAileron());
        this->position->setElevator(csentence->getElevator());
        this->position->setRudder(csentence->getRudder());
        Thread::unlock(this->mutex);
    }
}

XPlaneControlSurface::~XPlaneControlSurface() {
    Thread::destroy(this->mutex);
    
    delete this->mutex;
    delete this->position;
}

extern "C" {
    IControlSurface* create(Context* context) {
        XPlaneControlSurface* xctls = new XPlaneControlSurface(MessageHandler::getInstance()->getMessageTransmitter());
        
        // TODO: Add to the exception listener as soon as Master Caution and Master Warning are added.
        MessageHandler::getInstance()->getMessageReciever()->addSentenceListener(xctls);
        
        return xctls;
    }
}