/* 
 * File:   GPIO.h
 * Author: Robert
 *
 * Created on June 15, 2013, 10:51 AM
 */

#ifndef GPIOFACTORYSINGLETON_H
#define	GPIOFACTORYSINGLETON_H

#include <map>
#include <list>
#include <stdexcept>
#include <wiringPi.h>
#include "GPIO.h"
#include "GPIOException.h"
#include "IGPIOFactory.h"
#include "IGPIOFactoryProvider.h"
#include "Pin.h"
#include "Thread.h"
#include "IllegalStateException.h"

class GPIOFactorySingleton : public IGPIOFactory {
public:
    virtual ~GPIOFactorySingleton();
    
    virtual GPIO* registerGPIO(Pin* pin) throw (GPIOException);
    
    static void          create(IGPIOFactoryProvider* provider);
    static void          destroy();
    static IGPIOFactory* getInstance();
    
protected:
    GPIOFactorySingleton(IGPIOFactoryProvider* provider);
    
private:
    std::map<Pin*, GPIO*>*       gpiopins;
    pthread_mutex_t*             gpioMutex;
    IGPIOFactoryProvider*        provider;
    
    static GPIOFactorySingleton* factory;
};

#endif	/* GPIOFACTORYSINGLETON_H */

