/* 
 * File:   FlightControllerOff.h
 * Author: Robert
 *
 * Created on June 17, 2013, 12:41 AM
 */

#ifndef FLIGHTCONTROLLEROFF_H
#define	FLIGHTCONTROLLEROFF_H

#include "../tulipallo_core/IStateChangedListener.h"
#include "FlightController.h"

class FlightControllerOff : public IStateChangedListener {
public:
    FlightControllerOff(FlightController* controller);
    
    virtual void handleStateChanged(StateChangedEvent event);
    
    virtual ~FlightControllerOff();
    
private:
    FlightController* controller;
    
};

#endif	/* FLIGHTCONTROLLEROFF_H */

