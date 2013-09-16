/* 
 * File:   LevelFlightGuidanceRule.h
 * Author: Robert
 *
 * Created on June 11, 2013, 11:27 PM
 */

#ifndef LEVELFLIGHTGUIDANCERULE_H
#define	LEVELFLIGHTGUIDANCERULE_H

#include "../tulipallo_control/PIDAttitude.h"
#include "Rule.h"
#include "../tulipallo_control/Yaw.h"

class LevelFlightGuidanceRule : public Rule {
public:
    LevelFlightGuidanceRule();
    
    virtual ~LevelFlightGuidanceRule();
    
protected:
    virtual void doCommand(ISituation* situation);
    
};

#endif	/* LEVELFLIGHTGUIDANCERULE_H */

