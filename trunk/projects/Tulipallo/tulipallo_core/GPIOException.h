/* 
 * File:   GPIOException.h
 * Author: Robert
 *
 * Created on June 15, 2013, 2:31 PM
 */

#ifndef GPIOEXCEPTION_H
#define	GPIOEXCEPTION_H

#include "Exception.h"

class GPIOException : public Exception {
public:
    GPIOException() throw ();
    GPIOException(const GPIOException& source) throw ();
    GPIOException(std::string message) throw ();    
    GPIOException(int code, std::string message) throw ();
    
    virtual ~GPIOException() throw ();
private:

};

#endif	/* GPIOEXCEPTION_H */

