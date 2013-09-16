/* 
 * File:   InputOrientationDecorator.h
 * Author: Robert
 *
 * Created on June 11, 2013, 8:39 PM
 */

#ifndef PIDATTITUDE_H
#define	PIDATTITUDE_H

#include "Attitude.h"
#include "PIDController.h"

class PIDAttitude {
public:
    PIDAttitude();
    
    virtual void           setControlPoint(Attitude* iatt);
    virtual void           calculate(Attitude* iatt, Attitude* oatt, 
                                     unsigned long long dt);
    virtual PIDController* getHeadingController();
    virtual PIDController* getPitchController();
    virtual PIDController* getRollController();
    
    virtual ~PIDAttitude();
    
private:
    PIDController* headingController;
    PIDController* pitchController;
    PIDController* rollController;
};

#endif	/* PIDATTITUDE_H */

