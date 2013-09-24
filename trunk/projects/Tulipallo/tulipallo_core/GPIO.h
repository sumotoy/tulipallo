/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2010 M2 Astronautics
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 *
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

/**
 * <p/>
 * <tt>Tulipallo - The Java Finite Volume Method Simulation<br />
 * Copyright &copy; 2010 M2 Astronautics<br />
 * <p/>
 * <tt>This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.</tt>
 * <p/>
 * <tt>You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.</tt>
 * 
 * @author Robert R Murrell
 * @version 1.0 beta
 */
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

