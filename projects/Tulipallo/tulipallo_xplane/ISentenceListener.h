/* 
 * File:   IMessageReceivedListener.h
 * Author: Robert
 *
 * Created on May 26, 2013, 10:52 PM
 */

#ifndef ISENTENCELISTENER_H
#define	ISENTENCELISTENER_H

#include "SentenceReceivedEvent.h"

class ISentenceListener {
public:
    ISentenceListener();
    
    virtual void handleSentenceReceived(SentenceReceivedEvent event) = 0;
    
    virtual ~ISentenceListener();
private:

};

#endif	/* ISENTENCELISTENER_H */

