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

#include <stdlib.h>

#include "MessageHandler.h"

MessageHandler* MessageHandler::instance = new MessageHandler();

MessageHandler::MessageHandler() {
    this->rx = new MessageReciever();
    this->tx = new MessageTransmitter();
    
    try {
        Properties properties = Properties();
        
        properties.load("xplane.handler.properties");
        
        std::string    rxIpLocalAddress  = properties.getProperty(PROPERTY_RX_LOCAL_HOST);
        std::string    txIpLocalAddress  = properties.getProperty(PROPERTY_TX_LOCAL_HOST);
        std::string    txIpRemoteAddress = properties.getProperty(PROPERTY_TX_REMOTE_HOST);
        unsigned short rxPort            = properties.getUnsignedShort(PROPERTY_RX_LOCAL_PORT);
        unsigned short txPort            = properties.getUnsignedShort(PROPERTY_TX_REMOTE_PORT);
        int            rxSentenceSize    = properties.getInteger(PROPERTY_RX_SENTENCE);
        
        this->tx->initialize(txIpLocalAddress, txIpRemoteAddress, txPort);        
        this->rx->initialize(rxIpLocalAddress, rxPort, rxSentenceSize);
    }
    catch(KeyNotFoundException& e) {
        // TODO Define how to error out gracefully and report to the controller
        //      that there was issues.
    }
    catch(PropertiesException& e) {
        // TODO Define how to error out gracefully and report to the controller
        //      that there was issues.
    }
}

MessageHandler* MessageHandler::getInstance() {
    return MessageHandler::instance;
}

MessageReciever* MessageHandler::getMessageReciever() {
    return this->rx;
}

MessageTransmitter* MessageHandler::getMessageTransmitter() {
    return this->tx;
}

MessageHandler::~MessageHandler() {
    this->rx->terminate();
    this->tx->terminate();
    
    delete this->tx;
    delete this->rx;
}

