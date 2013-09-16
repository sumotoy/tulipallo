/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "SocketException.h"

SocketException::SocketException() 
        throw () : Exception() {
}

SocketException::SocketException(const SocketException& cause) 
        throw () : Exception(cause) {
    //
}

SocketException::SocketException(std::string message) 
        throw () : Exception(message) {
    //
}

SocketException::SocketException(int code, std::string message) 
        throw () : Exception(code, message) {
    //
}

SocketException::~SocketException() 
        throw () {
}

