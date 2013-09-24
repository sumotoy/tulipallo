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

#ifndef THREAD_H
#define	THREAD_H

#include <time.h>
#include <pthread.h>
#include <cxxabi.h>
#include <string>
#include <errno.h>
#include "ThreadException.h"

#define THREAD_SUCCESS 0

static const char* THREAD_MGS_ERR_ATTR_INIT   = "Error initializing thread attributes.";
static const char* THREAD_MGS_ERR_SCHD_PLCY   = "Error initializing thread scheduling policy.";
static const char* THREAD_MGS_ERR_SCHD_PARAM  = "Error initializing thread scheduling parameters.";
static const char* THREAD_MGS_ERR             = "Error creating thread.";
static const char* THREAD_MGS_ERR_YIELD       = "Error yielding thread.";
static const char* THREAD_MGS_ERR_CANCEL      = "Error canceling thread.";
static const char* THREAD_MGS_ERR_JOIN        = "Error joining thread.";
static const char* THREAD_MGS_ERR_LOCK        = "Error locking mutex.";
static const char* THREAD_MGS_ERR_UNLOCK      = "Error unlocking mutex.";
static const char* THREAD_MGS_ERR_WAIT        = "Exception waiting thread.";
static const char* THREAD_MGS_ERR_SIG         = "Exception signaling thread.";
static const char* THREAD_MGS_ERR_BCAST       = "Exception broadcasting thread.";
static const char* THREAD_MGS_ERR_SETCLCK     = "Exception setting condition clock.";
static const char* THREAD_MGS_ERR_MTX_INIT    = "Exception initializing mutex.";
static const char* THREAD_MGS_ERR_MTX_DTRY    = "Exception destroying mutex.";

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
class Thread {
public:
    Thread();
    
    virtual void      initialize() 
            throw (ThreadException);
    virtual void      terminate() 
            throw (ThreadException);
    virtual bool      isRunning();
    virtual int       getPriority();
    virtual void      setPriority(int priority);
    virtual int       getPolicy();
    virtual void      setPolicy(int policy);
    virtual pthread_t getThread();
    virtual void      join();
    virtual bool      equals(Thread& thread);
    
    virtual ~Thread();
    
    /**
     * Callback from thread to execute the threaded routine.
     */
    static void* threadExecute(void* context) {
        ((Thread*)context)->execute();
        return context;
    }
    
    /**
     * Callback from thread to cleanup the thread on sig shutdown.
     */
    static void threadCleanup(void* context) {
        ((Thread*)context)->cleanup();
    }
    
    /**
     * 
     * @param mutex
     * 
     * @throws ThreadException
     */
    static void lock(pthread_mutex_t* mutex) 
                throw (ThreadException) {
        checkException(pthread_mutex_lock(mutex), THREAD_MGS_ERR_LOCK);
    }
    
    /**
     * 
     * @param mutex
     * 
     * @throws ThreadException
     */
    static void unlock(pthread_mutex_t* mutex) 
                throw (ThreadException) {
        checkException(pthread_mutex_unlock(mutex), THREAD_MGS_ERR_UNLOCK);
    }
    
    /**
     * 
     * @param mutex
     * @param condition
     * 
     * @throws ThreadException
     */
    static void wait(pthread_mutex_t* mutex, pthread_cond_t* condition) 
                throw (ThreadException) {
        checkException(pthread_cond_wait(condition, mutex), 
                THREAD_MGS_ERR_WAIT);
    }
    
    /**
     * 
     * @param mutex
     * @param condition
     * @param time
     * 
     * @throws ThreadException
     */
    static int timedwait(pthread_mutex_t* mutex, pthread_cond_t* condition, 
                     timespec* time) 
                throw (ThreadException) {
        int local = pthread_cond_timedwait(condition, mutex, time);
        
        if(local != ETIMEDOUT) {
            checkException(local, THREAD_MGS_ERR_WAIT);
        }
        
        return local;
    }
    
    /**
     * 
     * @param condition
     * 
     * @throws ThreadException
     */
    static void signal(pthread_cond_t* condition)  
                throw (ThreadException) {
        checkException(pthread_cond_signal(condition), 
                THREAD_MGS_ERR_SIG);
    }
    
    /**
     * 
     * @param condition
     * 
     * @throws ThreadException
     */
    static void broadcast(pthread_cond_t* condition)  
                throw (ThreadException) {
        checkException(pthread_cond_broadcast(condition), 
                THREAD_MGS_ERR_BCAST);
    }
    
    /**
     * 
     * @param t1
     * @param t2
     * @param result
     */
    static void add(timespec* t1, timespec* t2, timespec* result) {
        result->tv_sec  = t1->tv_sec  + t2->tv_sec;
        result->tv_nsec = t1->tv_nsec + t2->tv_nsec;
        if (result->tv_nsec >= 1000000000L) {		/* Carry? */
            result->tv_sec++;  
            result->tv_nsec = result->tv_nsec - 1000000000L;
        }
    }
    
    /**
     * 
     * @param attribute
     * @param id
     * 
     * @throws ThreadException
     */
    static void setClockAttribute(pthread_condattr_t* attribute, 
                                  __clockid_t id)  
                throw (ThreadException) {
        checkException(pthread_condattr_setclock(attribute, id), 
                THREAD_MGS_ERR_SETCLCK);
    }
    
    /**
     * 
     * @param thread
     * 
     * @throws ThreadException
     */
    static void join(pthread_t thread)  
                throw (ThreadException) {
        checkException(pthread_join(thread, NULL), THREAD_MGS_ERR_JOIN);
    }
    
    /**
     * 
     * @param mutex
     * 
     * @throws ThreadException
     */
    static void initialize(pthread_mutex_t* mutex)  
                throw (ThreadException) {
        checkException(pthread_mutex_init(mutex, NULL), 
                                THREAD_MGS_ERR_MTX_INIT);
    }
    
    /**
     * 
     * @param att
     * 
     * @throws ThreadException
     */
    static void initialize(pthread_attr_t* att)  
                throw (ThreadException) {
        checkException(pthread_attr_init(att), THREAD_MGS_ERR_ATTR_INIT);
    }
    
    /**
     * 
     * @param att
     * @param policy
     * 
     * @throws ThreadException
     */
    static void setSchedulePolicy(pthread_attr_t* att, int policy)  
                throw (ThreadException) {
        checkException(pthread_attr_setschedpolicy(
                att, policy), THREAD_MGS_ERR_SCHD_PLCY);
    }
    
    /**
     * 
     * @param att
     * @param param
     * 
     * @throws ThreadException
     */
    static void setScheduleParameter(pthread_attr_t* att, sched_param param) 
                throw (ThreadException) {
        checkException(pthread_attr_setschedparam(att, &param), 
                THREAD_MGS_ERR_SCHD_PARAM);
    }
    
    /**
     * 
     * @param thread
     * @param att
     * @param routine
     * @param args
     * 
     * @throws ThreadException
     */
    static void create(pthread_t thread, pthread_attr_t* att, 
                       void *(*routine)(void *), void* args) 
                throw (ThreadException) {
        checkException(pthread_create(&thread, att, routine, args), 
                       THREAD_MGS_ERR);
    }
    
    /**
     * 
     * @param thread
     * 
     * @throws ThreadException
     */
    static void cancel(pthread_t& thread) {
        checkException(pthread_cancel(thread), THREAD_MGS_ERR_CANCEL);
    }
    
    /**
     * 
     * @param mutex
     * 
     * @throws ThreadException
     */
    static void destroy(pthread_mutex_t* mutex) 
                throw (ThreadException) {
        checkException(pthread_mutex_destroy(mutex), 
                                   THREAD_MGS_ERR_MTX_DTRY);
    }
    
    /**
     * 
     * @param mutex
     * 
     * @throws ThreadException
     */
    static void destroy(pthread_attr_t* attribute) 
                throw (ThreadException) {
        checkException(pthread_attr_destroy(attribute), 
                                       THREAD_MGS_ERR_MTX_DTRY);
    }
    
    /**
     * 
     * @throws ThreadException
     */
    static void yield() 
                throw (ThreadException) {
        checkException(pthread_yield(), THREAD_MGS_ERR_YIELD);
    }
    
protected:
    /**
     * 
     * @param result
     * @param message
     */
    static void checkException(int result, const char* message) {
        if(result != THREAD_SUCCESS) {
            throw ThreadException(result, message);
        }
    }
    
private:
    virtual void run() throw (ThreadException) = 0;
    virtual void cleanup() = 0;
    virtual void execute();
    
    bool            running;
    int             priority;
    int             policy;
    
    pthread_t        thread;
    pthread_mutex_t* runningMutex;
    pthread_attr_t*  attributes;
};

#endif	/* THREAD_H */

