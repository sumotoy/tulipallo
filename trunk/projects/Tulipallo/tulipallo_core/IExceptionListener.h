/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#ifndef IEXCEPTIONEVENTLISTENER_H
#define	IEXCEPTIONEVENTLISTENER_H

#include "ExceptionEvent.h"

class IExceptionListener {
public:
    IExceptionListener();
    
    /**
     * Handler invoked by Objects who want to asynchronously notify a listener 
     * that a relevant exception has occurred.
     * <p/>
     * The term relevant is up to the Object of concern.
     * 
     * @param event The event containing the exception that occurred.
     */
    virtual void handleException(ExceptionEvent event) throw() = 0;
    
    virtual ~IExceptionListener();
private:

};

#endif	/* IEXCEPTIONEVENTLISTENER_H */

