/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "XPlaneSlipIndicator.h"

XPlaneSlipIndicator::XPlaneSlipIndicator() {
    this->slip  = new Slip();
    this->mutex = new pthread_mutex_t();
    Thread::initialize(this->mutex);
}

Slip XPlaneSlipIndicator::getSlip() {
    Thread::lock(this->mutex);
    Slip local = Slip(this->slip->getSlip());
    Thread::unlock(this->mutex);
    
    return local;
}

void XPlaneSlipIndicator::handleSentenceReceived(SentenceReceivedEvent event) {
    if(event.getSentence()->getCommand() == SLIP_COMMAND) {
        SlipSentence* ssentence = (SlipSentence*)event.getSentence();
        
        Thread::lock(this->mutex);
        this->slip->setSlip(ssentence->getSlip());
        Thread::unlock(this->mutex);
    }
}

XPlaneSlipIndicator::~XPlaneSlipIndicator() {
    Thread::destroy(this->mutex);
    
    delete this->mutex;
    delete this->slip;
}

extern "C" {
    ISlipIndicator* create(Context* context) {
        XPlaneSlipIndicator* xslip = new XPlaneSlipIndicator();
        
        // TODO: Add to the exception listener as soon as Master Caution and Master Warning are added.
        MessageHandler::getInstance()->getMessageReciever()->addSentenceListener(xslip);
        
        return xslip;
    }
}