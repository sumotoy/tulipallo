/* 
 * File:   PIDGuidanceRule.h
 * Author: Robert
 *
 * Created on June 14, 2013, 10:24 PM
 */

#ifndef PIDCONTROLRULE_H
#define	PIDCONTROLRULE_H

#include "Rule.h"
#include "../tulipallo_control/PIDAttitude.h"
#include "../tulipallo_control/Attitude.h"
#include "../tulipallo_control/PIDController.h"
#include "../tulipallo_control/Yaw.h"

class PIDControlRule : public Rule {
public:
    PIDControlRule();
    
    virtual PIDController* getHeadingController();
    virtual PIDController* getRollController();
    virtual PIDController* getPitchController();
    virtual PIDController* getYawController();
    
    virtual ~PIDControlRule();
    
protected:
    virtual void doCommand(ISituation* situation);
    
private:
    PIDAttitude*   pattitude;
    PIDController* yawController;
};

#endif	/* PIDCONTROLRULE_H */

