/* 
 * File:   ControlSurfaceSentence.h
 * Author: Robert
 *
 * Created on June 10, 2013, 10:02 PM
 */

#ifndef CONTROLSURFACESENTENCE_H
#define	CONTROLSURFACESENTENCE_H

#include <sstream>
#include "XPlaneSentence.h"

const int SURFACE_COMMAND = 11;

class ControlSurfaceSentence : public XPlaneSentence {
public:
    ControlSurfaceSentence();
    ControlSurfaceSentence(float elevator, float aileron, float rudder);
    ControlSurfaceSentence(const ControlSurfaceSentence& orig);
    
    virtual float getElevator();
    virtual float getAileron();
    virtual float getRudder();
    
    virtual int         getCommand();
    virtual std::string toString();
    
    virtual void unmarshall(DataStream* stream) 
                throw (MarshallingException);
    virtual void marshall(DataStream* stream) 
                throw (MarshallingException);
    
    virtual ~ControlSurfaceSentence();
    
private:
    float elevator;
    float aileron;
    float rudder;
};

#endif	/* CONTROLSURFACESENTENCE_H */

