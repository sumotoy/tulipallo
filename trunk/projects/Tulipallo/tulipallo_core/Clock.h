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
#ifndef CLOCK_H
#define	CLOCK_H

#include <pthread.h>
#include <time.h>
#include <errno.h>
#include <cxxabi.h>
#include <list>
#include "IllegalArgumentException.h"
#include "IClockListener.h"
#include "ClockException.h"
#include "Thread.h"

static const unsigned int  MILLISECONDS      = 1000;
static const unsigned long NANOSECONDS       = 1000000;
static const unsigned int  MIN_FREQUECY      = 1;
static const unsigned int  MAX_FREQUECY      = 1000;
static const unsigned int  DEFAULT_FREQUENCY = 25;
static const int           NANOSLEEP_FAILURE = -1;

static const std::string MSG_CL_EINT_EXPECTED     = "Expected interrupt.";
static const std::string MSG_CL_UNEXPECTED        = "Unexpected exception.";
static const std::string MSG_CL_LISTENER_NULL     = "Argument 'listener' cannot be NULL.";
static const std::string MSG_CL_FREQ_LESS_MIN     = "Argument 'frequency' cannot be less then MIN_FREQUECY.";
static const std::string MSG_CL_FREQ_GRTR_MAX     = "Argument 'frequency' cannot be greater then MAX_FREQUECY.";

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
class Clock : public Thread {
public:
    Clock();
    
    virtual void               addClockListener(IClockListener* listener);
    virtual void               removeClockListener(IClockListener* listener);
    virtual unsigned int       getFrequency();
    virtual void               setFrequency(unsigned int frequency);
    virtual unsigned long long getInterval(); 
    virtual bool               isStarted();
    virtual void               start();
    virtual void               start(bool reset);
    virtual void               stop();
    virtual void               terminate() throw (ThreadException);
    
    virtual ~Clock();

protected:
    virtual void fireClockTickEvent(unsigned long long interval);
    virtual void fireClockStartEvent();
    virtual void fireClockStopEvent();
    virtual void fireClockExceptionEvent(int errorcode);
    virtual void fireClockExceptionEvent(int errorcode, std::string message);
    virtual void fireClockExceptionEvent(ClockException e);
    virtual void cleanup();
    virtual void run() 
            throw (ThreadException);
    virtual void setInterval(unsigned long long interval);
    virtual unsigned long long incrementInterval();
    virtual void advanceWaitTime();
    
private:
    unsigned int                frequency;
    unsigned long long          interval;
    bool                        started;
    std::list<IClockListener*>* clockListeners;
    timespec*                   sleepTime;
    timespec*                   waitTime;
    
    pthread_mutex_t*    intervalMutex;
    pthread_mutex_t*    controlMutex;
    pthread_mutex_t*    listenerMutex;
    pthread_cond_t*     startCondition;
    pthread_condattr_t* startAttribute;
    pthread_cond_t*     stopCondition;
    pthread_condattr_t* stopAttribute;
};

#endif	/* CLOCK_H */

