/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#ifndef ICLOCKLISTENER_H
#define	ICLOCKLISTENER_H

#include "ClockStartEvent.h"
#include "ClockStopEvent.h"
#include "ClockTickEvent.h"
#include "IExceptionListener.h"

class IClockListener : public IExceptionListener {
public:
    IClockListener();
    
    virtual void handleClockStart(ClockStartEvent event) = 0;
    virtual void handleClockStop(ClockStopEvent event)   = 0;
    virtual void handleClockTick(ClockTickEvent event)   = 0;
    
    virtual ~IClockListener();
};

#endif	/* ICLOCKLISTENER_H */

