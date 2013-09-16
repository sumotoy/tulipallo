/* 
 * File:   IGPIOFactoryMethod.h
 * Author: Robert
 *
 * Created on June 16, 2013, 2:37 PM
 */

#ifndef IGPIOFACTORYPROVIDER_H
#define	IGPIOFACTORYPROVIDER_H

#include "GPIO.h"

class IGPIOFactoryProvider {
public:
    IGPIOFactoryProvider();
    
    virtual void  initialize() throw (GPIOException)     = 0;
    virtual GPIO* create(Pin* pin) throw (GPIOException) = 0;
    
    virtual ~IGPIOFactoryProvider();
private:

};

#endif	/* IGPIOFACTORYPROVIDER_H */

