/* 
 * File:   XPlaneSentence.h
 * Author: Robert
 *
 * Created on June 4, 2013, 9:40 PM
 */

#ifndef XPLANESENTENCE_H
#define	XPLANESENTENCE_H

#include <string>
#include "MarshallingException.h"
#include "../tulipallo_core/DataStream.h"

class XPlaneSentence {
public:
    XPlaneSentence();
    XPlaneSentence(const XPlaneSentence& orig);
    
    virtual int         getCommand() = 0;
    virtual std::string toString();
    
    virtual void unmarshall(DataStream* stream) 
                throw (MarshallingException) = 0;
    virtual void marshall(DataStream* stream) 
                throw (MarshallingException);
    
    virtual ~XPlaneSentence();
    
private:
    
};

#endif	/* XPLANESENTENCE_H */

