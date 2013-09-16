/* 
 * File:   SpeedSentence.h
 * Author: Robert
 *
 * Created on June 5, 2013, 9:00 PM
 */

#ifndef SPEEDSENTENCE_H
#define	SPEEDSENTENCE_H

#include <sstream>
#include <string>
#include "XPlaneSentence.h"

static const int SPEED_COMMAND = 3;

class SpeedSentence : public XPlaneSentence {
public:
    SpeedSentence();
    SpeedSentence(float indKias, float indKeas, float trueKtas, float trueKtgs, 
                  float indMph, float trueMphas, float trueMphgs);
    SpeedSentence(const SpeedSentence& orig);
    
    virtual float getVindKias();
    virtual float getVindKeas();
    virtual float getVtrueKtas();
    virtual float getVtrueKtgs();
    virtual float getVindMph();
    virtual float getVtrueMphas();
    virtual float getVtrueMphgs();
    
    virtual int         getCommand();
    virtual std::string toString();
    
    virtual void unmarshall(DataStream* stream) 
                throw (MarshallingException);
    virtual void marshall(DataStream* stream) 
                throw (MarshallingException);
    
    virtual ~SpeedSentence();
    
private:
    float indKias;
    float indKeas;
    float trueKtas;
    float trueKtgs;
    float indMph;
    float trueMphas;
    float trueMphgs;
};

#endif	/* SPEEDSENTENCE_H */

