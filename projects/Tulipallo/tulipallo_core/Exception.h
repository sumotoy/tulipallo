/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#ifndef EXCEPTION_H
#define	EXCEPTION_H

#include <string>
#include <exception>

class Exception : public std::exception {
public:
    Exception() throw ();
    Exception(const Exception& source) throw ();
    Exception(std::string message) throw ();    
    Exception(int code, std::string message) throw ();
    
    virtual std::string getMessage() throw ();
    virtual int         getCode() throw ();
    
    const char* what() const throw() {
        return this->message.c_str();
    }
    
    virtual ~Exception() throw ();
    
private:
    std::string message;
    int         code;
};

#endif	/* EXCEPTION_H */

