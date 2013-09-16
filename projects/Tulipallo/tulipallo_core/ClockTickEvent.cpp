/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#include "ClockTickEvent.h"

ClockTickEvent::ClockTickEvent() : 
                Event() {
    //
}

ClockTickEvent::ClockTickEvent(void* source) : 
                Event(source) {
    //
}

ClockTickEvent::ClockTickEvent(unsigned long long time, void* source) : 
                Event(time, source) {
    //
}

ClockTickEvent::ClockTickEvent(const ClockTickEvent& source) : 
                Event(source) {
    //
}

ClockTickEvent::~ClockTickEvent() {
}

