/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#include "ExceptionEvent.h"

ExceptionEvent::ExceptionEvent(Exception exception) : 
        Event() {
    this->exception = exception;
}

ExceptionEvent::ExceptionEvent(void* source, Exception exception) : 
        Event(source) {
    this->exception = exception;
}

ExceptionEvent::ExceptionEvent(unsigned long long time, void* source, 
                               Exception exception) : Event(time, source) {
    this->exception = exception;
}

/**
 * Returns the Exception that caused this event to be thrown.
 * 
 * @return the Exception that caused this event to be thrown.
 */
Exception ExceptionEvent::getException() {
    return this->exception;
}

ExceptionEvent::~ExceptionEvent() {
}

