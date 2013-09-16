/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#include "IllegalArgumentException.h"

IllegalArgumentException::IllegalArgumentException() throw () : 
                Exception() {
}

IllegalArgumentException::IllegalArgumentException(
                        const IllegalArgumentException& cause) throw () : 
        Exception(cause) {
    //
}

IllegalArgumentException::IllegalArgumentException(std::string message) throw () : 
        Exception(message) {
    //
}

IllegalArgumentException::IllegalArgumentException(int code, 
                                                   std::string message) throw () : 
        Exception(code, message) {
    //
}

IllegalArgumentException::~IllegalArgumentException() throw () {
}

