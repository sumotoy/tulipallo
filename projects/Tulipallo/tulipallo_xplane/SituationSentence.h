/* 
 * File:   SituationSentence.h
 * Author: Robert
 *
 * Created on June 6, 2013, 10:34 PM
 */

#ifndef SITUATIONSENTENCE_H
#define	SITUATIONSENTENCE_H

#include <sstream>
#include "../tulipallo_xplane/XPlaneSentence.h"

static const int SITUATION_COMMAND = 17;

class SituationSentence : public XPlaneSentence {
public:
    SituationSentence();
    SituationSentence(float pitchDeg, float rollDeg, float headingTrue, 
                      float headingMag);
    SituationSentence(const SituationSentence& orig);
    
    virtual float       getPitchDeg();
    virtual float       getRollDeg();
    virtual float       getHeadingTrue();
    virtual float       getHeadingMag();
    
    virtual int         getCommand();
    virtual std::string toString();
    
    virtual void unmarshall(DataStream* stream) 
                throw (MarshallingException);
    virtual void marshall(DataStream* stream) 
                throw (MarshallingException);
    
    virtual ~SituationSentence();
private:
    float pitchDeg;
    float rollDeg;
    float headingTrue;
    float headingMag;
};

#endif	/* SITUATIONSENTENCE_H */

