/* 
 * File:   Tulipallo.h
 * Author: Robert
 *
 * Created on June 8, 2013, 8:31 PM
 */

#ifndef FLIGHTCONTROLLER_H
#define	FLIGHTCONTROLLER_H

#include <iostream>
#include "../tulipallo_control/IGPS.h"
#include "../tulipallo_control/IGyro.h"
#include "../tulipallo_control/IControlSurface.h"
#include "../tulipallo_control/ISlipIndicator.h"
#include "../tulipallo_control/BaseSituation.h"
#include "Rule.h"
#include "PIDControlRule.h"
#include "../tulipallo_core/Clock.h"
#include "../tulipallo_core/IClockListener.h"
#include "../tulipallo_core/Thread.h"
#include "../tulipallo_core/IllegalStateException.h"

class FlightController : public IClockListener {
public:
    FlightController();
    
    virtual void             setClockFrequency(unsigned int clockFrequency);
    virtual unsigned int     getClockFrequency();
    virtual void             setGyro(IGyro* gyro);
    virtual IGyro*           getGyro();
    virtual void             setGPS(IGPS* gps);
    virtual IGPS*            getGPS();
    virtual void             setControlSurface(IControlSurface* controlSurfaces);
    virtual IControlSurface* getControlSurface();
    virtual void             setSlipIndicator(ISlipIndicator* slipIndicator);
    virtual ISlipIndicator*  getSlipIndicator();
    
    virtual void             addGuidanceRule(Rule* command);
    virtual void             addNavigationRule(Rule* command);
    virtual void             addControlRule(Rule* command);
    
    virtual ISituation*      getSituation();
    virtual void             setEnabled(bool enabled);
    virtual bool             isEnabled();
    virtual void             join() throw (ThreadException);
    virtual PIDController*   getHeadingController();
    virtual PIDController*   getPitchController();
    virtual PIDController*   getRollController();
    virtual PIDController*   getYawController();
    
    virtual void on();
    virtual void off();
    virtual bool isOn();
    
    virtual ~FlightController();
    
protected:
    virtual void handleClockStart(ClockStartEvent event);
    virtual void handleClockStop(ClockStopEvent event);
    virtual void handleClockTick(ClockTickEvent event);
    virtual void handleException(ExceptionEvent event) throw();
    virtual void loadSituation();
    virtual void executeGuidanceRuleChain();
    virtual void executeNavigationRuleChain();
    virtual void executeControlRuleChain();
    
private:
    Clock*           clock;
    IGyro*           gyro;
    IGPS*            gps;
    ISlipIndicator*  slipIndicator;
    IControlSurface* controlSurfaces;
    BaseSituation*   situation;
    pthread_mutex_t* gncMutex;
    pthread_mutex_t* runningMutex;
    Rule*            guidanceRuleChain;
    Rule*            navigationRuleChain;
    PIDControlRule*  controlRuleChain;
    bool             running;
    bool             enabled;
};

#endif	/* FLIGHTCONTROLLER_H */

