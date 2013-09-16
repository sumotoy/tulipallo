/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#include "ClockStopEvent.h"

ClockStopEvent::ClockStopEvent() : Event() {
    //
}

ClockStopEvent::ClockStopEvent(void* source) : 
                Event(source) {
    //
}

ClockStopEvent::ClockStopEvent(unsigned long long time, void* source) : 
                Event(time, source) {
    //
}

ClockStopEvent::ClockStopEvent(const ClockStopEvent& source) : Event(source) {
    //
}

ClockStopEvent::~ClockStopEvent() {
}

