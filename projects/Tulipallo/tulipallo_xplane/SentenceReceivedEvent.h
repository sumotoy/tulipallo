/* 
 * File:   SentenceReceivedEvent.h
 * Author: Robert
 *
 * Created on June 5, 2013, 8:57 PM
 */

#ifndef SENTENCERECEIVEDEVENT_H
#define	SENTENCERECEIVEDEVENT_H

#include "XPlaneSentence.h"
#include "../tulipallo_core/Event.h"

class SentenceReceivedEvent : public Event {
public:
    SentenceReceivedEvent(XPlaneSentence* sentence);
    SentenceReceivedEvent(void* source, XPlaneSentence* sentence);
    SentenceReceivedEvent(unsigned long long time, void* source, 
                          XPlaneSentence* sentence);
    SentenceReceivedEvent(const SentenceReceivedEvent& source);
    
    virtual XPlaneSentence* getSentence();
    
    virtual ~SentenceReceivedEvent();
private:
    XPlaneSentence* sentence;
    
};

#endif	/* SENTENCERECEIVEDEVENT_H */

