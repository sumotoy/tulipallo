/* 
 * File:   ObjectFactoryException.h
 * Author: Robert
 *
 * Created on June 24, 2013, 9:26 PM
 */

#ifndef OBJECTFACTORYEXCEPTION_H
#define	OBJECTFACTORYEXCEPTION_H

#include "Properties.h"

class ObjectFactoryException : public Exception {
public:
    ObjectFactoryException() 
            throw () ;
    ObjectFactoryException(const ObjectFactoryException& source) 
            throw () ;
    ObjectFactoryException(std::string message) 
            throw () ; 
    ObjectFactoryException(int code, std::string message) 
            throw () ;
    
    virtual ~ObjectFactoryException()
            throw ();
private:

};

#endif	/* OBJECTFACTORYEXCEPTION_H */

