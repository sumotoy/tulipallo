/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#include "ClockException.h"

ClockException::ClockException() 
        throw () : Exception() {
}

ClockException::ClockException(const ClockException& cause) 
        throw () : Exception(cause) {
    //
}

ClockException::ClockException(std::string message) 
        throw () : Exception(message) {
    //
}

ClockException::ClockException(int cause, std::string message) 
        throw () : Exception(cause, message) {
    //
}

ClockException::~ClockException() 
        throw () {
}

