/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#ifndef THREADEXCEPTION_H
#define	THREADEXCEPTION_H

#include "Exception.h"

class ThreadException : public Exception {
public:
    ThreadException() 
            throw () ;
    ThreadException(const ThreadException& cause) 
            throw () ;
    ThreadException(std::string message) 
            throw () ;
    ThreadException(int code, std::string message) 
            throw () ;
    
    virtual ~ThreadException() 
            throw ();
private:

};

#endif	/* THREADEXCEPTION_H */

