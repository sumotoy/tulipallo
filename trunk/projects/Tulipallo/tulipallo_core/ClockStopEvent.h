/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#ifndef CLOCKSTOPEVENT_H
#define	CLOCKSTOPEVENT_H

#include "Event.h"

class ClockStopEvent : public Event {
public:
    ClockStopEvent();
    ClockStopEvent(void* source);
    ClockStopEvent(unsigned long long time, void* source);
    ClockStopEvent(const ClockStopEvent& source);
    
    virtual ~ClockStopEvent();
};

#endif	/* CLOCKSTOPEVENT_H */

