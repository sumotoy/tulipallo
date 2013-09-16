/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "StateChangedEvent.h"

StateChangedEvent::StateChangedEvent() 
                : Event(){
    //
}

StateChangedEvent::StateChangedEvent(void* source) 
                : Event(source){
    //
}

StateChangedEvent::StateChangedEvent(unsigned long long time, void* source) 
                : Event(time, source) {
    //
}

StateChangedEvent::StateChangedEvent(const Event& source) 
                : Event(source) {
    //
}

StateChangedEvent::~StateChangedEvent() {
}

