/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#ifndef CLOCKTICKEVENT_H
#define	CLOCKTICKEVENT_H

#include "Event.h"

class ClockTickEvent : public Event {
public:
    ClockTickEvent();
    ClockTickEvent(void* source);
    ClockTickEvent(unsigned long long time, void* source);
    ClockTickEvent(const ClockTickEvent& source);
    
    virtual ~ClockTickEvent();
};

#endif	/* CLOCKTICKEVENT_H */

