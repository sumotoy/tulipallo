/* 
 * File:   GertboardGPIOFactoryMethod.h
 * Author: Robert
 *
 * Created on June 16, 2013, 2:43 PM
 */

#ifndef GERTBOARDGPIOFACTORYPROVIDER_H
#define	GERTBOARDGPIOFACTORYPROVIDER_H

#include <wiringPi.h>
#include "GertboardGPIO.h"
#include "../tulipallo_core/GPIO.h"
#include "../tulipallo_core/IGPIOFactoryProvider.h"
#include "../tulipallo_core/Pin.h"
#include "../tulipallo_core/Context.h"

class GertboardGPIOFactoryProvider : public IGPIOFactoryProvider {
public:
    GertboardGPIOFactoryProvider();
    
    virtual void  initialize() throw (GPIOException);
    virtual GPIO* create(Pin* pin) throw (GPIOException);
    
    virtual ~GertboardGPIOFactoryProvider();
private:

};

#endif	/* GERTBOARDGPIOFACTORYPROVIDER_H */

