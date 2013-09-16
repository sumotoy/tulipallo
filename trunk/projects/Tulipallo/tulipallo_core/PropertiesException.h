/* 
 * File:   PropertiesException.h
 * Author: Robert
 *
 * Created on June 25, 2013, 8:21 PM
 */

#ifndef PROPERTIESEXCEPTION_H
#define	PROPERTIESEXCEPTION_H

#include "Exception.h"

class PropertiesException : public Exception {
public:
    PropertiesException() 
            throw () ;
    PropertiesException(const PropertiesException& source) 
            throw () ;
    PropertiesException(std::string message) 
            throw () ; 
    PropertiesException(int code, std::string message) 
            throw () ;
    
    virtual ~PropertiesException()
            throw ();
private:

};

#endif	/* PROPERTIESEXCEPTION_H */

