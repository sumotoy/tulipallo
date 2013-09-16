/* 
 * File:   LocationSentence.h
 * Author: Robert
 *
 * Created on June 6, 2013, 6:07 PM
 */

#ifndef LOCATIONSENTENCE_H
#define	LOCATIONSENTENCE_H

#include <sstream>
#include "XPlaneSentence.h"

static const int LOCATION_COMMAND = 20;

class LocationSentence : public XPlaneSentence {
public:
    LocationSentence();
    LocationSentence(float latDeg, float lonDeg, float altFtmsl, float altFtagl, 
                     bool  onRunway, float altInd, float latSouth, float lonWest);
    LocationSentence(const LocationSentence& orig);
    
    virtual float getLatDeg();
    virtual float getLonDeg();
    virtual float getAltFtmsl();
    virtual float getAltFtagl();
    virtual bool  isOnRunway();
    virtual float getAltInd();
    virtual float getLatSouth();
    virtual float getLonWest();
    
    virtual int         getCommand();
    virtual std::string toString();
    
    virtual void unmarshall(DataStream* stream) 
                throw (MarshallingException);
    virtual void marshall(DataStream* stream) 
                throw (MarshallingException);
    
    virtual ~LocationSentence();
    
private:
    float latDeg;
    float lonDeg;
    float altFtmsl;
    float altFtagl;
    bool  onRunway;
    float altInd;
    float latSouth;
    float lonWest;
};

#endif	/* LOCATIONSENTENCE_H */

