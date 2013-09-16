/* 
 * File:   SentenceFactoryNotFoundException.h
 * Author: Robert
 *
 * Created on June 6, 2013, 9:13 AM
 */

#ifndef MARSHALLERNOTFOUNDEXCEPTION_H
#define	MARSHALLERNOTFOUNDEXCEPTION_H

#include "../tulipallo_core/Exception.h"

class MarshallingException : public Exception {
public:
    MarshallingException(int command) throw ();
    MarshallingException(const MarshallingException& source) throw ();
    MarshallingException(int command, std::string message) throw ();    
    MarshallingException(int command, int code, std::string message) throw ();
    
    virtual int getCommand() throw ();
    
    virtual ~MarshallingException() throw ();
    
private:
    int command;
};

#endif	/* MARSHALLERNOTFOUNDEXCEPTION_H */

