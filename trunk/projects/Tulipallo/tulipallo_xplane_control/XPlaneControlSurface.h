/* 
 * File:   XPlaneControlSurface.h
 * Author: Robert
 *
 * Created on June 10, 2013, 10:52 PM
 */

#ifndef XPLANECONTROLSURFACE_H
#define	XPLANECONTROLSURFACE_H

#include "../tulipallo_control/IControlSurface.h"
#include "../tulipallo_xplane/ISentenceListener.h"
#include "../tulipallo_xplane/ControlSurfaceSentence.h"
#include "../tulipallo_xplane/MessageTransmitter.h"
#include "../tulipallo_core/Thread.h"
#include "../tulipallo_core/Context.h"
#include "../tulipallo_xplane/MessageHandler.h"

class XPlaneControlSurface : public IControlSurface, public ISentenceListener {
public:
    XPlaneControlSurface(MessageTransmitter* tx);
    
    virtual ControlSurfacePosition getPosition();
    virtual void                   setPosition(ControlSurfacePosition* position);
    virtual void                   handleSentenceReceived(SentenceReceivedEvent event);
    
    virtual ~XPlaneControlSurface();
    
private:
    ControlSurfacePosition* position;
    pthread_mutex_t*        mutex;
    MessageTransmitter*     tx;
};

#endif	/* XPLANECONTROLSURFACE_H */

