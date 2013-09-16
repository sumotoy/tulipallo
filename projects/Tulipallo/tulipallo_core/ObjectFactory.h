/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#ifndef OBJECTFACTORY_H
#define	OBJECTFACTORY_H

#include <string>
#include <map>
#include "Properties.h"
#include "ObjectFactoryException.h"
#include "ObjectFactoryMethod.h"
#include "KeyNotFoundException.h"
#include "Context.h"
#include "Thread.h"

static const char* FACTORY_METHOD_NAME = "create";

class ObjectFactory {
public:
    ObjectFactory();
    
    virtual void load(std::string key, std::string library) 
                throw (ObjectFactoryException);
    virtual void load(Properties* properties) 
                throw (ObjectFactoryException);
    
    virtual Context* getContext();
    
    template<class T>
    T newInstance(std::string key) 
                throw (KeyNotFoundException, ObjectFactoryException);
    
    
    virtual ~ObjectFactory();
    
protected:
    ObjectFactoryMethod* containsLibrary(std::string library);
    ObjectFactoryMethod* create(std::string library) 
                throw (ObjectFactoryException);
    
private:
    Context*                                     context;
    std::map<std::string, ObjectFactoryMethod*>* factories;
    pthread_mutex_t*                             mutex;
};

template<class T>
T ObjectFactory::newInstance(std::string key) 
                throw (KeyNotFoundException, ObjectFactoryException){
    T local;
    
    Thread::lock(this->mutex);
    if(this->factories->count(key) > 0) {
        local = static_cast<T>(this->factories->at(key)->newInstance(this->context));
    }
    else {
        throw new KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

#endif	/* OBJECTFACTORY_H */

