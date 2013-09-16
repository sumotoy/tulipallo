/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "MessageTransmitter.h"

MessageTransmitter::MessageTransmitter() {
    this->packet = new DatagramPacket();
    this->setPreamble();
    this->mutex = new pthread_mutex_t();
    Thread::initialize(this->mutex);
}

MessageTransmitter::MessageTransmitter(std::string address, std::string remote, 
                                       unsigned short port) {
    this->packet = new DatagramPacket();
    this->setPreamble();
    this->mutex = new pthread_mutex_t();
    Thread::initialize(this->mutex);
    
    this->address = address;
    this->remote  = remote;
    this->port    = port;
}

void MessageTransmitter::queue(XPlaneSentence* sentence) {
    Thread::lock(this->mutex);
    sentence->marshall(this->packet);
    this->packet->setPacketSize(this->packet->getPacketSize() + 36);
    Thread::unlock(this->mutex);
}

void MessageTransmitter::send() {
    Thread::lock(this->mutex);
    this->client->send(this->packet);
    this->setPreamble();
    Thread::unlock(this->mutex);
}

void MessageTransmitter::initialize(std::string address, std::string remote, 
                                    unsigned short port) {
    Thread::lock(this->mutex);
    this->address = address;
    this->remote  = remote;
    this->port    = port;
    Thread::unlock(this->mutex);
    
    this->initialize();
}

void MessageTransmitter::initialize() {
    Thread::lock(this->mutex);
    this->client = new DatagramSocketClient(this->address, this->remote, 
                                            this->port);
    this->client->bind();
    Thread::unlock(this->mutex);
}

void MessageTransmitter::terminate() {
    Thread::lock(this->mutex);
    this->client->close();
    delete this->client;
    Thread::unlock(this->mutex);
}

void MessageTransmitter::setPreamble() {
    this->packet->clear();
    this->packet->setString("DATA");
    this->packet->setByte(0);
}

MessageTransmitter::~MessageTransmitter() {
    Thread::destroy(this->mutex);
    
    delete this->mutex;
    delete this->client;
    delete this->packet;
}

