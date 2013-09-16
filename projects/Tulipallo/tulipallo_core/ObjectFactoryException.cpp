/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "ObjectFactoryException.h"

ObjectFactoryException::ObjectFactoryException() 
        throw () : Exception() {
}

ObjectFactoryException::ObjectFactoryException(const ObjectFactoryException& cause) 
        throw () : Exception(cause) {
    //
}

ObjectFactoryException::ObjectFactoryException(std::string message) 
        throw () : Exception(message) {
    //
}

ObjectFactoryException::ObjectFactoryException(int cause, std::string message) 
        throw () : Exception(cause, message) {
    //
}

ObjectFactoryException::~ObjectFactoryException() throw () {
}

