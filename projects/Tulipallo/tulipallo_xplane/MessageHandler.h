/* 
 * File:   MessageHandler.h
 * Author: Robert
 *
 * Created on June 29, 2013, 11:25 PM
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

