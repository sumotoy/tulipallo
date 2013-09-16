/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#ifndef EXCEPTIONEVENT_H
#define	EXCEPTIONEVENT_H

#include "Event.h"
#include "Exception.h"

class ExceptionEvent : public Event{
public:
    ExceptionEvent(Exception exception);
    ExceptionEvent(void* source, Exception exception);
    ExceptionEvent(unsigned long long time, void* source, Exception exception);
    
    virtual Exception getException();
    virtual ~ExceptionEvent();
    
private:
    Exception exception;
};

#endif	/* EXCEPTIONEVENT_H */

