/* 
 * File:   XPlaneGPS.h
 * Author: Robert
 *
 * Created on June 8, 2013, 5:32 PM
 */

#ifndef XPLANEGPS_H
#define	XPLANEGPS_H

#include "../tulipallo_control/IGPS.h"
#include "../tulipallo_xplane/ISentenceListener.h"
#include "../tulipallo_xplane/LocationSentence.h"
#include "../tulipallo_control/Position.h"
#include "../tulipallo_core/Thread.h"
#include "../tulipallo_core/Context.h"
#include "../tulipallo_xplane/MessageHandler.h"

class XPlaneGPS : public IGPS, public ISentenceListener {
public:
    XPlaneGPS();
    
    virtual Position getPosition();
    virtual void     handleSentenceReceived(SentenceReceivedEvent event);
    
    virtual ~XPlaneGPS();
    
private:
    Position*        position;
    pthread_mutex_t* mutex;
};

#endif	/* XPLANEGPS_H */

