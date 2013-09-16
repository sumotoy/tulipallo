/* 
 * File:   SocketException.h
 * Author: Robert
 *
 * Created on May 16, 2013, 9:31 PM
 */

#ifndef SOCKETEXCEPTION_H
#define	SOCKETEXCEPTION_H

#include "Exception.h"

class SocketException : public Exception {
public:
    SocketException() 
            throw ();
    SocketException(const SocketException& cause) 
            throw ();
    SocketException(std::string message) 
            throw ();
    SocketException(int cause, std::string message) 
            throw ();
    
    virtual ~SocketException() 
            throw ();
    
private:

};

#endif	/* SOCKETEXCEPTION_H */

