/* 
 * File:   GertGPIO.h
 * Author: Robert
 *
 * Created on June 16, 2013, 2:49 PM
 */

#ifndef GERTGPIO_H
#define	GERTGPIO_H

#include <wiringPi.h>
#include "../tulipallo_core/GPIO.h"

class GertboardGPIO : public GPIO {
public:
    GertboardGPIO(Pin* pin);
    
    virtual IO_STATE           getState()                          throw (GPIOException);
    virtual void               setState(IO_STATE state)            throw (GPIOException);
    virtual void               waitForInterrupt()                  throw (GPIOException);
    virtual IO_INTERRUPT_STATE waitForInterrupt(int timeOutMillis) throw (GPIOException);
    
    virtual ~GertboardGPIO();
    
protected:
    virtual void registerInterrupt(void (*callback)(void*), IO_INTERRUPT_EDGE edge) throw (GPIOException);
    
private:

};

#endif	/* GERTGPIO_H */

