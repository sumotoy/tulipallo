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

#include "ObjectFactory.h"

ObjectFactory::ObjectFactory() {
    this->context   = new Context();
    this->factories = new std::map<std::string, ObjectFactoryMethod*>();
    this->mutex     = new pthread_mutex_t();
    
    Thread::initialize(this->mutex);
}

void ObjectFactory::load(std::string key, std::string library) 
                throw (ObjectFactoryException) {
    Thread::lock(this->mutex);
    
    if(this->factories->count(key) == 0) {
        ObjectFactoryMethod* factory = this->containsLibrary(library);
        
        if(factory == NULL) {
            factory = this->create(library);
        }
        
        this->factories->insert(
                    std::pair<std::string, ObjectFactoryMethod*>(key, factory));
    }
    else {
        throw new ObjectFactoryException("Key '" + key + "' already exists.");
    }
    
    Thread::unlock(this->mutex);
}

void ObjectFactory::load(Properties* properties) 
                throw (ObjectFactoryException) {
    std::map<std::string, std::string>* props = properties->getProperties();
    
    for(std::map<std::string, std::string>::iterator it = 
                props->begin(); it != props->end(); ++it) {
        this->load((*it).first, (*it).second);
    }
}

ObjectFactoryMethod* ObjectFactory::containsLibrary(std::string library) {
    ObjectFactoryMethod* factory = NULL;
    
    for(std::map<std::string, ObjectFactoryMethod*>::iterator it = 
                this->factories->begin(); it != this->factories->end(); ++it) {
        if((*it).first.compare(library) == 0) {
            factory = (*it).second;
            break;
        }
    }
    
    return factory;
}

ObjectFactoryMethod* ObjectFactory::create(std::string library) 
                        throw (ObjectFactoryException) {
    void* handle = dlopen(library.c_str(), RTLD_NOW);
            
    if(handle == NULL) {
        std::string message = "Error loading library: ";
        throw ObjectFactoryException(message += dlerror());
    }

    void* (*factory)(Context*) = (void*(*)(Context*))dlsym(handle, 
            FACTORY_METHOD_NAME);
    
    return new ObjectFactoryMethod(library, handle, factory);
}

Context* ObjectFactory::getContext() {
    return this->context;
}

ObjectFactory::~ObjectFactory() {
    Thread::destroy(this->mutex);
    
    for(std::map<std::string, ObjectFactoryMethod*>::iterator it = 
                this->factories->begin(); it != this->factories->end(); ++it) {
        delete (*it).second;
    }
    
    delete this->mutex;
    delete this->factories;
    delete this->context;
}