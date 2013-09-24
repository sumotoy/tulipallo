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

#include "MessageReciever.h"

MessageReciever::MessageReciever() : Thread() {
    this->sentenceListeners      = new std::list<ISentenceListener*>();
    this->exceptionListeners     = new std::list<IExceptionListener*>();
    this->sentenceListenerMutex  = new pthread_mutex_t();
    this->exceptionListenerMutex = new pthread_mutex_t();
    Thread::initialize(this->sentenceListenerMutex);
    Thread::initialize(this->exceptionListenerMutex);
}

MessageReciever::MessageReciever(std::string address, unsigned short port, 
                                 unsigned int dataPointsPerMessage) : Thread() {
    this->address              = address;
    this->port                 = port;
    this->dataPointsPerMessage = dataPointsPerMessage;
    
    this->sentenceListeners      = new std::list<ISentenceListener*>();
    this->exceptionListeners     = new std::list<IExceptionListener*>();
    this->sentenceListenerMutex  = new pthread_mutex_t();
    this->exceptionListenerMutex = new pthread_mutex_t();
    Thread::initialize(this->sentenceListenerMutex);
    Thread::initialize(this->exceptionListenerMutex);
}

void MessageReciever::initialize(std::string address, unsigned short port, 
                                 unsigned int dataPointsPerMessage) 
                throw (ThreadException) {
    this->address              = address;
    this->port                 = port;
    this->dataPointsPerMessage = dataPointsPerMessage;
    
    this->initialize();
}

void MessageReciever::initialize() throw (ThreadException) {
    this->factory              = new SpeedFactory();
    this->controlFactoryLink   = new ControlSurfaceFactory();
    this->locationFactoryLink  = new LocationFactory();
    this->situationFactoryLink = new SituationFactory();
    this->slipFactoryLink      = new SlipFactory();
    
    this->factory->addLink(this->controlFactoryLink);
    this->factory->addLink(this->situationFactoryLink);
    this->factory->addLink(this->locationFactoryLink);
    this->factory->addLink(this->slipFactoryLink);
    
    this->server = new DatagramSocketServer(this->address, this->port);
    this->server->bind();
    this->packet = new DatagramPacket((this->dataPointsPerMessage * 36) + 5);
    
    Thread::initialize();
}

void MessageReciever::run() throw (ThreadException) {    
    while(this->isRunning()) {
        this->server->receive(this->packet);
        
        if(!this->isValidMessage()) {
            this->fireExceptionEvent(InvalidMessageException());
        }
        else {
            this->packet->skip();
            
            // Loop through each of the data points
            for(int index = 0; index < this->dataPointsPerMessage; ++index) {
                int command = (int)this->packet->getByte();
                this->packet->skip(3);
                
                try {
                    XPlaneSentence* sentence = this->factory->create(command);
                    if(sentence != NULL) {
                        sentence->unmarshall(this->packet);
                        this->fireSentenceReceivedEvent(sentence);
                    }
                    else {
                        this->packet->skip(32);
                    }
                    delete sentence;
                }
                catch(MarshallingException e) {
                    this->fireExceptionEvent(e);
                }
            }
        }
    }
}

void MessageReciever::addExceptionListener(IExceptionListener* listener) {
    lock(this->exceptionListenerMutex);
    this->exceptionListeners->push_back(listener);
    unlock(this->exceptionListenerMutex);
}

void MessageReciever::removeExceptionListener(IExceptionListener* listener) {
    lock(this->exceptionListenerMutex);
    this->exceptionListeners->remove(listener);
    unlock(this->exceptionListenerMutex);
}

void MessageReciever::addSentenceListener(ISentenceListener* listener) {
    lock(this->sentenceListenerMutex);
    this->sentenceListeners->push_back(listener);
    unlock(this->sentenceListenerMutex);
}

void MessageReciever::removeSentenceListener(ISentenceListener* listener) {
    lock(this->sentenceListenerMutex);
    this->sentenceListeners->remove(listener);
    unlock(this->sentenceListenerMutex);
}

bool MessageReciever::isValidMessage() {
    return (PREAMBLE.compare(this->packet->getString(4)) != 0);
}

void MessageReciever::fireExceptionEvent(Exception exception) {
    ExceptionEvent event = ExceptionEvent(this, exception);
    
    lock(this->exceptionListenerMutex);
    for (std::list<IExceptionListener*>::iterator it = 
            this->exceptionListeners->begin(); it != this->exceptionListeners->end(); ++it) {
        (*it)->handleException(event);
    }
    unlock(this->exceptionListenerMutex);
}

void MessageReciever::fireSentenceReceivedEvent(XPlaneSentence* sentence) {
    SentenceReceivedEvent event = SentenceReceivedEvent(this, sentence);
    
    lock(this->sentenceListenerMutex);
    for (std::list<ISentenceListener*>::iterator it = 
            this->sentenceListeners->begin(); it != this->sentenceListeners->end(); ++it) {
        (*it)->handleSentenceReceived(event);
    }
    unlock(this->sentenceListenerMutex);
}

void MessageReciever::cleanup() {
    //this->server->close();
    
    destroy(this->sentenceListenerMutex);
    destroy(this->exceptionListenerMutex);
    
    delete this->exceptionListenerMutex;
    delete this->exceptionListeners;
    delete this->controlFactoryLink;
    delete this->sentenceListeners;
    delete this->sentenceListenerMutex;
    delete this->server;
    delete this->packet;
    delete this->factory;
    delete this->locationFactoryLink;
    delete this->situationFactoryLink;
}

MessageReciever::~MessageReciever() {
    this->cleanup();
}

