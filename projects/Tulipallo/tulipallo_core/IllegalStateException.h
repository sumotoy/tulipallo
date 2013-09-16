/* 
 * File:   IllegalStateException.h
 * Author: Robert
 *
 * Created on June 15, 2013, 9:37 AM
 */

#ifndef ILLEGALSTATEEXCEPTION_H
#define	ILLEGALSTATEEXCEPTION_H

#include "Exception.h"

class IllegalStateException : public Exception {
public:
    IllegalStateException() throw () ;
    IllegalStateException(const IllegalStateException& source) throw () ;
    IllegalStateException(std::string message) throw () ;
    IllegalStateException(int code, std::string message) throw () ;
    
    virtual ~IllegalStateException() throw ();
private:

};

#endif	/* ILLEGALSTATEEXCEPTION_H */

