/* 
 * File:   StateChangedEvent.h
 * Author: Robert
 *
 * Created on June 16, 2013, 7:02 PM
 */

#ifndef STATECHANGEDEVENT_H
#define	STATECHANGEDEVENT_H

#include "Event.h"

class StateChangedEvent : public Event {
public:
    StateChangedEvent();
    StateChangedEvent(void* source);
    StateChangedEvent(unsigned long long time, void* source);
    StateChangedEvent(const Event& source);
    
    virtual ~StateChangedEvent();
    
private:
    
};

#endif	/* STATECHANGEDEVENT_H */

