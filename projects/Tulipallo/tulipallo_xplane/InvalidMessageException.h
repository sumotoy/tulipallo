/* 
 * File:   InvalidMessageException.h
 * Author: Robert
 *
 * Created on June 2, 2013, 2:19 PM
 */

#ifndef INVALIDMESSAGEEXCEPTION_H
#define	INVALIDMESSAGEEXCEPTION_H

#include "../tulipallo_core/Exception.h"

class InvalidMessageException : public Exception {
public:
    InvalidMessageException() throw ();
    InvalidMessageException(const InvalidMessageException& source) throw ();
    InvalidMessageException(std::string message) throw ();
    InvalidMessageException(int code, std::string message) throw ();
    
    virtual ~InvalidMessageException() throw ();
    
private:
    
};

#endif	/* INVALIDMESSAGEEXCEPTION_H */

