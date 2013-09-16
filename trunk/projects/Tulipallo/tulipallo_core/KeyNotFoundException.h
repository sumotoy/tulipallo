/* 
 * File:   KeyNotFoundException.h
 * Author: Robert
 *
 * Created on July 5, 2013, 3:31 PM
 */

#ifndef KEYNOTFOUNDEXCEPTION_H
#define	KEYNOTFOUNDEXCEPTION_H

#include "Exception.h"

class KeyNotFoundException : public Exception {
public:
    KeyNotFoundException(std::string key) 
            throw ();
    KeyNotFoundException(const KeyNotFoundException& source) 
            throw ();
    KeyNotFoundException(std::string message, std::string key) 
            throw (); 
    KeyNotFoundException(int code, std::string message, std::string key) 
            throw ();
    
    virtual std::string getKey() throw ();
    
    virtual ~KeyNotFoundException() throw ();
    
private:
    std::string key;
    
};

#endif	/* KEYNOTFOUNDEXCEPTION_H */

