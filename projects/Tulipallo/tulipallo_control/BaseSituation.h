/* 
 * File:   Situation.h
 * Author: Robert
 *
 * Created on June 8, 2013, 9:59 PM
 */

#ifndef BASESITUATION_H
#define	BASESITUATION_H

#include "ISituation.h"

class BaseSituation : public ISituation {
public:
    BaseSituation();
    BaseSituation(const BaseSituation& orig);
    
    virtual Attitude*               getAttitude();
    virtual void                    setAttitude(const Attitude& orientation);
    virtual Attitude*               getInputAttitude();
    virtual void                    setInputAttitude(const Attitude& inputOrientation);
    virtual Slip*                   getSlip();
    virtual void                    setSlip(const Slip& slip);
    virtual void                    setInputYaw(const Yaw& yaw);
    virtual Yaw*                    getInputYaw();
    virtual Position*               getPosition();
    virtual void                    setPosition(const Position& position);
    virtual ControlSurfacePosition* getControlSurfacePosition();
    virtual void                    setControlSurfacePosition(const ControlSurfacePosition& position);
    virtual ControlSurfacePosition* getInputControlSurfacePosition();
    virtual void                    setInputControlSurfacePosition(const ControlSurfacePosition& position);
    virtual Clock*                  getClock();
    virtual void                    setClock(Clock* clock);
    virtual void                    setPreempted(bool preempted);
    virtual bool                    isPreempted();
    virtual void                    setAborted(bool aborted);
    virtual bool                    isAborted();
    
    virtual ~BaseSituation();
    
private:
    Attitude*               attitude;
    Attitude*               inputAttitude;
    Slip*                   slip;
    Yaw*                    yaw;
    Position*               position;
    ControlSurfacePosition* controlSurfacePosition;
    ControlSurfacePosition* inputControlSurface;
    bool                    preempt;
    bool                    abort;
    Clock*                  clock;
};

#endif	/* BASESITUATION_H */

