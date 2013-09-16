/* 
 * File:   XPlaneSlipIndicator.h
 * Author: Robert
 *
 * Created on June 26, 2013, 10:59 PM
 */

#ifndef XPLANESLIPINDICATOR_H
#define	XPLANESLIPINDICATOR_H

#include "../tulipallo_control/ISlipIndicator.h"
#include "../tulipallo_core/Thread.h"
#include "../tulipallo_xplane/ISentenceListener.h"
#include "../tulipallo_xplane/SlipSentence.h"
#include "../tulipallo_core/Context.h"
#include "../tulipallo_xplane/MessageHandler.h"

class XPlaneSlipIndicator : public ISlipIndicator, public ISentenceListener {
public:
    XPlaneSlipIndicator();
    
    virtual Slip getSlip();
    virtual void handleSentenceReceived(SentenceReceivedEvent event);
    
    virtual ~XPlaneSlipIndicator();
    
private:
    Slip*            slip;
    pthread_mutex_t* mutex;
};

#endif	/* XPLANESLIPINDICATOR_H */

