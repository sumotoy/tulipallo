/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#include "ThreadException.h"

ThreadException::ThreadException() 
        throw () : Exception () {
    //
}

ThreadException::ThreadException(const ThreadException& source) 
        throw () : Exception(source) {
    //
}

ThreadException::ThreadException(std::string message) 
        throw () : Exception(message) {
    //
}

ThreadException::ThreadException(int code, std::string message) 
         throw () : Exception(code, message) {
    //
}

ThreadException::~ThreadException() 
        throw () {
}

