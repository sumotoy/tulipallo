/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "IllegalStateException.h"

IllegalStateException::IllegalStateException() throw () : 
                Exception() {
}

IllegalStateException::IllegalStateException(
                        const IllegalStateException& cause) throw () : 
        Exception(cause) {
    //
}

IllegalStateException::IllegalStateException(std::string message) throw () : 
        Exception(message) {
    //
}

IllegalStateException::IllegalStateException(int code, 
                                             std::string message) throw () : 
        Exception(code, message) {
    //
}

IllegalStateException::~IllegalStateException()  throw () {
}

