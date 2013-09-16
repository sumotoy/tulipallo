/* 
 * File:   AttitudeToControlSurfaceRule.h
 * Author: Robert
 *
 * Created on June 12, 2013, 11:17 PM
 */

#ifndef ATTITUDETOCONTROLSURFACERULE_H
#define	ATTITUDETOCONTROLSURFACERULE_H

#include <math.h>
#include "../tulipallo_control/Attitude.h"
#include "../tulipallo_control/Yaw.h"
#include "Rule.h"
#include "../tulipallo_control/ControlSurfacePosition.h"

class AttitudeToControlSurfaceRule : public Rule {
public:
    AttitudeToControlSurfaceRule();
    virtual ~AttitudeToControlSurfaceRule();
    
protected:
    virtual void doCommand(ISituation* situation);
    
private:
    double min;
    double max;    
};

#endif	/* ATTITUDETOCONTROLSURFACERULE_H */

