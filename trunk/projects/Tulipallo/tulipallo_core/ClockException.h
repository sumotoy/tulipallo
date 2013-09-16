/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#ifndef CLOCKEXCEPTION_H
#define	CLOCKEXCEPTION_H

#include "Exception.h"

class ClockException : public Exception {
public:
    ClockException() 
            throw () ;
    ClockException(const ClockException& source) 
            throw () ;
    ClockException(std::string message) 
            throw () ; 
    ClockException(int code, std::string message) 
            throw () ;
    
    virtual ~ClockException() 
            throw ();
};

#endif	/* CLOCKEXCEPTION_H */

