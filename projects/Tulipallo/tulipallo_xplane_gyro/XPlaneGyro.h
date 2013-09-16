/* 
 * File:   XPlaneGyro.h
 * Author: Robert
 *
 * Created on June 8, 2013, 5:59 PM
 */

#ifndef XPLANEGYRO_H
#define	XPLANEGYRO_H

#include "../tulipallo_control/IGyro.h"
#include "../tulipallo_xplane/ISentenceListener.h"
#include "../tulipallo_xplane/SituationSentence.h"
#include "../tulipallo_core/Thread.h"
#include "../tulipallo_core/Context.h"
#include "../tulipallo_xplane/MessageHandler.h"

class XPlaneGyro : public IGyro, public ISentenceListener {
public:
    XPlaneGyro();
    
    virtual Attitude getAttitude();
    virtual void     handleSentenceReceived(SentenceReceivedEvent event);
    
    virtual ~XPlaneGyro();
    
private:
    Attitude*        attitude;
    pthread_mutex_t* mutex;
};
#endif	/* XPLANEGYRO_H */
