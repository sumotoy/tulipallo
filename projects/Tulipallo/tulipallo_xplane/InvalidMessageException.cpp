/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "InvalidMessageException.h"

InvalidMessageException::InvalidMessageException() throw () :
                Exception() {
    //
}

InvalidMessageException::InvalidMessageException(
                        const InvalidMessageException& source) throw () :
                Exception(source) {
    //
}

InvalidMessageException::InvalidMessageException(std::string message) throw () :
                Exception(message) {
    //
}

InvalidMessageException::InvalidMessageException(int code, std::string message) throw () :
                Exception(code, message) {
    //
}

InvalidMessageException::~InvalidMessageException() throw () {
    //
}

