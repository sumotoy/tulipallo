/* 
 * File:   SlipSentence.h
 * Author: Robert
 *
 * Created on June 26, 2013, 10:24 PM
 */

#ifndef SLIPSENTENCE_H
#define	SLIPSENTENCE_H

#include <sstream>
#include "XPlaneSentence.h"

const int SLIP_COMMAND = 18;

class SlipSentence : public XPlaneSentence {
public:
    SlipSentence();
    SlipSentence(float slip);
    SlipSentence(const SlipSentence& orig);
    
    virtual int         getCommand();
    virtual std::string toString();
    virtual float       getSlip();
    virtual void        setSlip(float slip);
    
    virtual void unmarshall(DataStream* stream) 
                throw (MarshallingException);
    virtual void marshall(DataStream* stream) 
                throw (MarshallingException);
    
    virtual ~SlipSentence();
    
private:
    float slip;
    
};

#endif	/* SLIPSENTENCE_H */

