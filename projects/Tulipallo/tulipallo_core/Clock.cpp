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

#include <bits/pthreadtypes.h>

#include "Clock.h"

Clock::Clock() {
    this->clockListeners    = new std::list<IClockListener*>();
    this->frequency         = DEFAULT_FREQUENCY;
    
    this->waitTime           = new timespec();
    this->sleepTime          = new timespec();
    this->sleepTime->tv_sec  = 0;
    this->sleepTime->tv_nsec = (MILLISECONDS / this->frequency) * NANOSECONDS;
    
    this->controlMutex  = new pthread_mutex_t();
    this->intervalMutex = new pthread_mutex_t();
    this->listenerMutex = new pthread_mutex_t();
    initialize(this->controlMutex);
    initialize(this->intervalMutex);
    initialize(this->listenerMutex);
    
    this->stopAttribute  = new pthread_condattr_t();
    this->startAttribute = new pthread_condattr_t();
    this->startCondition = new pthread_cond_t();
    this->stopCondition  = new pthread_cond_t();
    setClockAttribute(this->stopAttribute,  CLOCK_REALTIME);
    setClockAttribute(this->startAttribute, CLOCK_REALTIME);
    pthread_cond_init(this->stopCondition,  this->stopAttribute);
    pthread_cond_init(this->startCondition, this->startAttribute);
    
    this->started = false;
}

void Clock::addClockListener(IClockListener* listener) {
    lock(this->listenerMutex);
    this->clockListeners->push_back(listener);
    unlock(this->listenerMutex);
}

void Clock::removeClockListener(IClockListener* listener) {
    lock(this->listenerMutex);
    this->clockListeners->remove(listener);
    unlock(this->listenerMutex);
}

bool Clock::isStarted() {
    bool local = false;
    lock(this->controlMutex);
    local = this->started;
    unlock(this->controlMutex);
    return local;
}

void Clock::start() {
    this->start(false);
}

void Clock::start(bool reset) {
    lock(this->controlMutex);
    if(!this->started) {
        this->started = true;
        if(reset) {
            this->setInterval(0);
        }
        signal(this->startCondition);
        this->fireClockStartEvent();
    }
    unlock(this->controlMutex);
}

void Clock::stop() {
    lock(this->controlMutex);
    if(this->started) {
        this->started = false;
        signal(this->stopCondition);
        this->fireClockStopEvent();
    }
    unlock(this->controlMutex);
}

void Clock::terminate() throw (ThreadException){
    Thread::terminate();
    this->stop();
}

void Clock::advanceWaitTime() {
    clock_gettime(CLOCK_REALTIME, this->waitTime);
    add(this->waitTime, this->sleepTime, this->waitTime);
}

unsigned long long Clock::incrementInterval() {
    unsigned long long localInterval;
    lock(this->intervalMutex);
    ++this->interval;
    localInterval = this->interval;    
    unlock(this->intervalMutex);
    return localInterval;
}

void Clock::run()
        throw (ThreadException) {
    try {
        lock(this->controlMutex);
        while(this->isRunning()) {
            pthread_testcancel();
            
            if(this->started) {
                while(this->started) {
                    pthread_testcancel();  
                    if(timedwait(this->controlMutex, this->stopCondition, 
                                 this->waitTime) == ETIMEDOUT) {
                        this->fireClockTickEvent(this->incrementInterval());
                        this->advanceWaitTime();
                    }
                }
            }
            else {
                wait(this->controlMutex, this->startCondition);
            }
        }
        unlock(this->controlMutex);
    }
    catch(abi::__forced_unwind&) {
        // Expected during a shutdown.
        throw;
    }
    catch(...) {
        this->cleanup();
        this->fireClockExceptionEvent(ClockException(errno, MSG_CL_UNEXPECTED));
    }
}

void Clock::fireClockTickEvent(unsigned long long interval) {
    ClockTickEvent event = ClockTickEvent(interval, this);
    
    lock(this->listenerMutex);
    for(std::list<IClockListener*>::iterator it = this->clockListeners->begin();
            it != this->clockListeners->end(); ++it) {
        (*it)->handleClockTick(event);
    }
    unlock(this->listenerMutex);
}

void Clock::fireClockStartEvent() {
    ClockStartEvent event = ClockStartEvent(this);
    
    lock(this->listenerMutex);
    for(std::list<IClockListener*>::iterator it = this->clockListeners->begin();
            it != this->clockListeners->end(); ++it) {
        (*it)->handleClockStart(event);
    }
    unlock(this->listenerMutex);
}

void Clock::fireClockStopEvent() {
    ClockStopEvent event = ClockStopEvent(this);
    
    lock(this->listenerMutex);
    for(std::list<IClockListener*>::iterator it = this->clockListeners->begin();
            it != this->clockListeners->end(); ++it) {
        (*it)->handleClockStop(event);
    }
    unlock(this->listenerMutex);
}

void Clock::fireClockExceptionEvent(int errorcode) {
    this->fireClockExceptionEvent(ClockException(errorcode, MSG_CL_UNEXPECTED));
}

void Clock::fireClockExceptionEvent(int errorcode, std::string message) {
    this->fireClockExceptionEvent(ClockException(errorcode, message));
}

void Clock::fireClockExceptionEvent(ClockException e) {
    ExceptionEvent event = ExceptionEvent(this->getInterval(), this, e);
    
    lock(this->listenerMutex);
    for(std::list<IClockListener*>::iterator it = this->clockListeners->begin();
            it != this->clockListeners->end(); ++it) {
        (*it)->handleException(event);
    }
    unlock(this->listenerMutex);
}

void Clock::cleanup() {
    unlock(this->intervalMutex);
    unlock(this->controlMutex);
    unlock(this->listenerMutex);
}

unsigned int Clock::getFrequency() {
    lock(this->controlMutex);
    unsigned int local =  this->frequency;
    unlock(this->controlMutex);
    
    return local;
}

void Clock::setFrequency(unsigned int frequency) {
    if(frequency < MIN_FREQUECY) {
        throw IllegalArgumentException(MSG_CL_FREQ_LESS_MIN);
    }
    if(frequency > MAX_FREQUECY) {
        throw IllegalArgumentException(MSG_CL_FREQ_GRTR_MAX);
    }
    lock(this->controlMutex);
    this->frequency = frequency;
    unlock(this->controlMutex);
}

void Clock::setInterval(unsigned long long interval) {
    lock(this->intervalMutex);
    this->interval = interval;
    unlock(this->intervalMutex);
}

unsigned long long Clock:: getInterval() {
    unsigned long long localInterval;
    lock(this->intervalMutex);
    localInterval = this->interval;
    unlock(this->intervalMutex);
    return localInterval;
}

Clock::~Clock() {
    pthread_cond_destroy(this->stopCondition);
    pthread_cond_destroy(this->startCondition);
    
    destroy(this->listenerMutex);
    destroy(this->intervalMutex);
    destroy(this->controlMutex);
    
    delete this->startCondition;
    delete this->startAttribute;
    delete this->stopCondition;
    delete this->stopAttribute;
    delete this->clockListeners;
    delete this->listenerMutex;
    delete this->intervalMutex;
    delete this->controlMutex;
    delete this->waitTime;
    delete this->sleepTime;
}