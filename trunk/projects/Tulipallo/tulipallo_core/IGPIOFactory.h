/* 
 * File:   IGPIOManager.h
 * Author: Robert
 *
 * Created on June 15, 2013, 4:38 PM
 */

#ifndef IGPIOFACTORY_H
#define	IGPIOFACTORY_H

#include "Pin.h"
#include "GPIO.h"
#include "GPIOException.h"

class IGPIOFactory {
public:
    IGPIOFactory();
    
    virtual GPIO* registerGPIO(Pin* pin) throw (GPIOException) = 0;
    
    virtual ~IGPIOFactory();
private:

};

#endif	/* IGPIOFACTORY_H */

