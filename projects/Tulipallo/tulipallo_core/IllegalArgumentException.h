/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#ifndef ILLEGALARGUMENTEXCEPTION_H
#define	ILLEGALARGUMENTEXCEPTION_H

#include "Exception.h"

class IllegalArgumentException : public Exception {
public:
    IllegalArgumentException() throw () ;
    IllegalArgumentException(const IllegalArgumentException& source) throw () ;
    IllegalArgumentException(std::string message) throw () ;
    IllegalArgumentException(int code, std::string message) throw () ;
    
    virtual ~IllegalArgumentException() throw ();
};

#endif	/* ILLEGALARGUMENTEXCEPTION_H */

