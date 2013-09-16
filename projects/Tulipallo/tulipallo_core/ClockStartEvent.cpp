/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#include "ClockStartEvent.h"

ClockStartEvent::ClockStartEvent() : Event() {
    //
}

ClockStartEvent::ClockStartEvent(void* source) : 
                Event(source) {
    //
}

ClockStartEvent::ClockStartEvent(unsigned long long time, void* source) : 
                Event(time, source) {
    //
}

ClockStartEvent::ClockStartEvent(const ClockStartEvent& source) : Event(source) {
    //
}

ClockStartEvent::~ClockStartEvent() {
}

