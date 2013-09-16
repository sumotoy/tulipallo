/* 
 * File:   PreviousErrorZero.h
 * Author: Robert
 *
 * Created on June 26, 2013, 9:17 PM
 */

#ifndef PIDCONTROLLERZERO_H
#define	PIDCONTROLLERZERO_H

#include "../tulipallo_core/IStateChangedListener.h"
#include "FlightController.h"

class PIDControllerZero : public IStateChangedListener {
public:
    PIDControllerZero(FlightController* controller);
    
    virtual void handleStateChanged(StateChangedEvent event);
    
    virtual ~PIDControllerZero();
    
private:
    FlightController* controller;
    
};

#endif	/* PIDCONTROLLERZERO_H */

