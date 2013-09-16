/* 
 * File:   MessageReciever.h
 * Author: Robert
 *
 * Created on May 26, 2013, 10:17 PM
 */

#ifndef MESSAGERECIEVER_H
#define	MESSAGERECIEVER_H

#include <string>
#include <math.h>
#include <list>
#include "InvalidMessageException.h"
#include "SentenceFactory.h"
#include "SpeedFactory.h"
#include "SituationFactory.h"
#include "LocationFactory.h"
#include "ISentenceListener.h"
#include "ControlSurfaceFactory.h"
#include "SlipFactory.h"

#include "../tulipallo_core/IExceptionListener.h"
#include "../tulipallo_core/DatagramSocketServer.h"
#include "../tulipallo_core/DatagramPacket.h"
#include "../tulipallo_core/SocketException.h"
#include "../tulipallo_core/Thread.h"



const std::string PREAMBLE         = "DATA";
const double      PRECISION_BINARY = pow(2, -11);

class MessageReciever : public Thread {
public:
    MessageReciever();
    MessageReciever(std::string address, 
                    unsigned short port, 
                    unsigned int dataPointsPerMessage);
    
    virtual void initialize() throw (ThreadException);
    virtual void initialize(std::string address, 
                            unsigned short port, 
                            unsigned int dataPointsPerMessage) throw (ThreadException);
    
    virtual void addExceptionListener(IExceptionListener* listener);
    virtual void removeExceptionListener(IExceptionListener* listener);
    virtual void addSentenceListener(ISentenceListener* listener);
    virtual void removeSentenceListener(ISentenceListener* listener);
    
    virtual ~MessageReciever();
    
protected:
    virtual void cleanup();
    virtual void run() 
            throw (ThreadException);
    
    virtual bool  isValidMessage();
    virtual void  fireExceptionEvent(Exception exception);
    virtual void  fireSentenceReceivedEvent(XPlaneSentence* sentence);
    
private:
    unsigned int                    dataPointsPerMessage;
    std::string                     address;
    unsigned short                  port;
    DatagramSocketServer*           server;
    DatagramPacket*                 packet;
    SentenceFactory*                factory;
    ControlSurfaceFactory*          controlFactoryLink;
    LocationFactory*                locationFactoryLink;
    SituationFactory*               situationFactoryLink;
    SlipFactory*                    slipFactoryLink;
    std::list<ISentenceListener*>*  sentenceListeners;
    pthread_mutex_t*                sentenceListenerMutex;
    std::list<IExceptionListener*>* exceptionListeners;
    pthread_mutex_t*                exceptionListenerMutex;
};

#endif	/* MESSAGERECIEVER_H */

