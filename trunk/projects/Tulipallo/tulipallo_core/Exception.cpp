/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#include "Exception.h"

Exception::Exception() throw () {
}

Exception::Exception(const Exception& source) throw () {
    this->code    = source.code;
    this->message = source.message;
}

Exception::Exception(std::string message) throw () {
    this->message = message;
}

Exception::Exception(int code, std::string message) throw () {
    this->code    = code;
    this->message = message;
}

/**
 * The optional message related to this exception.
 * <p/>
 * May be empty.
 * 
 * @return an optional message related to this exception.
 */
std::string Exception::getMessage() throw () {
    return this->message;
}

/**
 * 
 * @return 
 */
int Exception::getCode() throw () {
    return this->code;
}

Exception::~Exception() throw () {
}

