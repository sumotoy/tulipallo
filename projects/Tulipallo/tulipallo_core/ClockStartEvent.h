/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#ifndef CLOCKSTARTEVENT_H
#define	CLOCKSTARTEVENT_H

#include "Event.h"

class ClockStartEvent : public Event {
public:
    ClockStartEvent();
    ClockStartEvent(void* source);
    ClockStartEvent(unsigned long long time, void* source);
    ClockStartEvent(const ClockStartEvent& source);
    
    virtual ~ClockStartEvent();
};

#endif	/* CLOCKSTARTEVENT_H */

