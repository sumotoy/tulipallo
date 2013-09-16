/* 
 * File:   GPIO.h
 * Author: Robert
 *
 * Created on June 15, 2013, 12:57 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#include <list>
#include "Pin.h"
#include "IStateChangedListener.h"
#include "Thread.h"
#include "GPIOException.h"
#include "StateChangedEvent.h"

enum IO_STATE {
    IO_LOW, IO_HIGH
};

enum IO_INTERRUPT_STATE {
    IO_INTERRUPTED, IO_TIMED_OUT
};

enum IO_INTERRUPT_EDGE {
    IO_EDGE_SETUP, IO_EDGE_FALLING, IO_EDGE_RISING, IO_EDGE_BOTH
};

class GPIO {
public:
    GPIO(Pin* pin);
    
    /**
     * Callback function triggered when an IRQ is handled.
     * 
     * @param context The context passed to the IRQ.
     */
    static void interrupted(void* context) {
        ((GPIO*)context)->handleInterrupted();
    }
    
    virtual IO_STATE           getState()                          throw (GPIOException) = 0;
    virtual void               setState(IO_STATE state)            throw (GPIOException) = 0;
    virtual void               waitForInterrupt()                  throw (GPIOException) = 0;
    virtual IO_INTERRUPT_STATE waitForInterrupt(int timeOutMillis) throw (GPIOException) = 0;
    virtual bool               isInterruptable();
    virtual void               setInterruptable();
    virtual void               addStateChangedListener(IStateChangedListener* listener);
    virtual void               removeStateChangedListener(IStateChangedListener* listener);
    virtual Pin*               getPin();
    
    virtual ~GPIO();
    
protected:
    Pin* pin;
    
    virtual void registerInterrupt(void (*callback)(void*), IO_INTERRUPT_EDGE edge) throw (GPIOException) = 0;
    virtual void handleInterrupted();
    
private:
    bool                               interruptable;
    std::list<IStateChangedListener*>* listeners;
    pthread_mutex_t*                   mutex;
    StateChangedEvent*                 event;
};

#endif	/* GPIO_H */

