/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "ObjectFactoryMethod.h"

ObjectFactoryMethod::ObjectFactoryMethod(std::string library, void* handle, 
                                         void* (*factory)(Context*)) {
    this->lib     = library;
    this->handle  = handle;
    this->factory = factory;
}

void* ObjectFactoryMethod::newInstance(Context* context) 
                throw (ObjectFactoryException) {
    try {
        return this->factory(context);
    }
    catch(...) {
        throw ObjectFactoryException(
                "Exception creating instance for library '"  + this->lib  + "'.");
    }
}

std::string ObjectFactoryMethod::getLibrary() {
    return this->lib;
}

ObjectFactoryMethod::~ObjectFactoryMethod() {
    dlclose(this->handle);
    
    free(this->handle);
    free((void*)this->factory);
}

