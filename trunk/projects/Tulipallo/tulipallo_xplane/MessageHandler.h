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

#ifndef MESSAGEHANDLER_H
#define	MESSAGEHANDLER_H

#include "MessageTransmitter.h"
#include "MessageReciever.h"
#include "../tulipallo_core/Properties.h"
#include "../tulipallo_core/PropertiesException.h"
#include "../tulipallo_core/KeyNotFoundException.h"

static const std::string PROPERTY_RX_LOCAL_HOST  = "xplane.rx.listening.ip4.address";
static const std::string PROPERTY_TX_LOCAL_HOST  = "xplane.tx.listening.ip4.address";
static const std::string PROPERTY_TX_REMOTE_HOST = "xplane.tx.remote.ip4.address";
static const std::string PROPERTY_RX_LOCAL_PORT  = "xplane.rx.port";
static const std::string PROPERTY_TX_REMOTE_PORT = "xplane.tx.port";
static const std::string PROPERTY_RX_SENTENCE    = "xplane.rx.sentences";

/**
 * <p/>
 * <tt>Tulipallo - The Java Finite Volume Method Simulation<br />
 * Copyright &copy; 2010 M2 Astronautics<br />
 * <p/>
 * <tt>This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.</tt>
 * <p/>
 * <tt>You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.</tt>
 * 
 * @author Robert R Murrell
 * @version 1.0 beta
 */
class MessageHandler {
public:
    static MessageHandler* getInstance();
    
    virtual MessageReciever*    getMessageReciever();
    virtual MessageTransmitter* getMessageTransmitter();
    
    virtual ~MessageHandler();
    
private:
    MessageHandler();
    MessageHandler(MessageHandler const&){};
    MessageHandler& operator = (MessageHandler const&){};   

    MessageTransmitter* tx;
    MessageReciever*    rx;
    
    static MessageHandler*  instance;
};

#endif	/* MESSAGEHANDLER_H */

