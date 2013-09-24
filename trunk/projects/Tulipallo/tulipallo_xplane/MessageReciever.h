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

