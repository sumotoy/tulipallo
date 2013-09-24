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