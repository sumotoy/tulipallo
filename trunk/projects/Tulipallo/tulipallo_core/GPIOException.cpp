/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "GPIOException.h"

GPIOException::GPIOException() throw () : 
        Exception() {
}

GPIOException::GPIOException(const GPIOException& cause) throw () : 
        Exception(cause) {
    //
}

GPIOException::GPIOException(std::string message) throw () : 
        Exception(message) {
    //
}

GPIOException::GPIOException(int code, std::string message) throw () : 
        Exception(code, message) {
    //
}

GPIOException::~GPIOException() throw () {
}

