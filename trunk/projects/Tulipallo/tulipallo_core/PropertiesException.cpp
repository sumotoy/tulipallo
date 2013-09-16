/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "PropertiesException.h"

PropertiesException::PropertiesException() 
        throw () : Exception() {
}

PropertiesException::PropertiesException(const PropertiesException& cause) 
        throw () : Exception(cause) {
    //
}

PropertiesException::PropertiesException(std::string message) 
        throw () : Exception(message) {
    //
}

PropertiesException::PropertiesException(int cause, std::string message) 
        throw () : Exception(cause, message) {
    //
}

PropertiesException::~PropertiesException() 
        throw () {
}

