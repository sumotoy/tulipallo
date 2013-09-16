/* 
 * File:   MessageTransmitter.h
 * Author: Robert
 *
 * Created on June 8, 2013, 1:56 PM
 */

#ifndef MESSAGETRANSMITTER_H
#define	MESSAGETRANSMITTER_H

#include "XPlaneSentence.h"
#include "../tulipallo_core/DatagramSocketClient.h"
#include "../tulipallo_core/Thread.h"
#include "../tulipallo_core/InternetAddress.h"

class MessageTransmitter {
public:
    MessageTransmitter();
    MessageTransmitter(std::string address, std::string remote, 
                       unsigned short port);
    
    virtual void queue(XPlaneSentence* sentence);
    virtual void send();
    virtual void initialize();
    virtual void initialize(std::string address, std::string remote, 
                            unsigned short port);
    virtual void terminate();
    
    virtual ~MessageTransmitter();

protected:
    virtual void setPreamble();
    
private:
    DatagramSocketClient* client;
    DatagramPacket*       packet;
    std::string           address;
    std::string           remote;
    unsigned short        port;
    pthread_mutex_t*      mutex;
    
};

#endif	/* MESSAGETRANSMITTER_H */

