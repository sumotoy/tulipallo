/* 
 * File:   ControlSurfacePosition.h
 * Author: Robert
 *
 * Created on June 10, 2013, 10:27 PM
 */

#ifndef CONTROLSURFACEPOSITION_H
#define	CONTROLSURFACEPOSITION_H

const double DEFAULT_LIMIT = 1;

class ControlSurfacePosition {
public:
    ControlSurfacePosition();
    ControlSurfacePosition(float elevator, float aileron, float rudder);
    ControlSurfacePosition(float elevator, float aileron, float rudder, 
                           float limit);
    ControlSurfacePosition(const ControlSurfacePosition& orig);
    
    virtual void  copy(const ControlSurfacePosition& orig);
    virtual float getElevator();
    virtual void  setElevator(float elevator);
    virtual float getAileron();
    virtual void  setAileron(float aileron);
    virtual float getRudder();
    virtual void  setRudder(float rudder);
    virtual float getLimit();
    virtual void  setLimit(float limit);
    
    virtual ~ControlSurfacePosition();

protected:
    virtual double limitValue(float value);
    
private:
    float elevator;
    float aileron;
    float rudder;
    float limit;
    
};

#endif	/* CONTROLSURFACEPOSITION_H */

