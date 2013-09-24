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

