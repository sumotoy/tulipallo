/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#include "Event.h"

Event::Event() {
    //
}

Event::Event(void* source) {
    this->source = source;
}

Event::Event(unsigned long long time, void* source) {
    this->time   = time;
    this->source = source;
}

Event::Event(const Event& source) {
    this->time   = source.time;
    this->source = source.source;
}

unsigned long long Event::getTime() {
    return this->time;
}

void* Event::getSource() {
    return this->source;
}

Event::~Event() {
}

