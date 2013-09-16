/* 
 * File:   ISituation.h
 * Author: Robert
 *
 * Created on June 12, 2013, 5:49 AM
 */

#ifndef ISITUATION_H
#define	ISITUATION_H

#include "Attitude.h"
#include "Position.h"
#include "ControlSurfacePosition.h"
#include "Slip.h"
#include "Yaw.h"
#include "../tulipallo_core/Clock.h"

class ISituation {
public:
    ISituation();
    
    virtual Clock*                  getClock()                                                             = 0;
    virtual Attitude*               getAttitude()                                                          = 0;
    virtual Slip*                   getSlip()                                                              = 0;
    virtual void                    setInputYaw(const Yaw& yaw)                                            = 0;
    virtual Yaw*                    getInputYaw()                                                          = 0;
    virtual Attitude*               getInputAttitude()                                                     = 0;
    virtual void                    setInputAttitude(const Attitude& inputOrientation)                     = 0;
    virtual Position*               getPosition()                                                          = 0;
    virtual ControlSurfacePosition* getControlSurfacePosition()                                            = 0;
    virtual ControlSurfacePosition* getInputControlSurfacePosition()                                       = 0;
    virtual void                    setInputControlSurfacePosition(const ControlSurfacePosition& position) = 0;
    virtual void                    setPreempted(bool preempted)                                           = 0;
    virtual bool                    isPreempted()                                                          = 0;
    virtual void                    setAborted(bool aborted)                                               = 0;
    virtual bool                    isAborted()                                                            = 0;
    
    virtual ~ISituation();

};

#endif	/* ISITUATION_H */

