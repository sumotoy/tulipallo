/* 
 * File:   LevelFlightGuidanceRuleActivator.h
 * Author: Robert
 *
 * Created on June 16, 2013, 11:30 PM
 */

#ifndef FLIGHTCONTROLLERACTIVATOR_H
#define	FLIGHTCONTROLLERACTIVATOR_H

#include "../tulipallo_core/IStateChangedListener.h"
#include "../tulipallo_core/GPIO.h"
#include "FlightController.h"
#include "../tulipallo_xplane/ControlSurfaceSentence.h"
#include "../tulipallo_xplane/MessageTransmitter.h"

class FlightControllerActivator : public IStateChangedListener {
public:
    FlightControllerActivator(FlightController* controller, GPIO* gpio, 
                              MessageTransmitter* tx);
    
    virtual void handleStateChanged(StateChangedEvent event);
    
    virtual ~FlightControllerActivator();
    
private:
    FlightController*       controller;
    GPIO*                   gpio;
    bool                    state;
    ControlSurfaceSentence* cp;
    MessageTransmitter*     tx;
};

#endif	/* FLIGHTCONTROLLERACTIVATOR_H */

