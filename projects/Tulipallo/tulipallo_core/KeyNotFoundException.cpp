/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "KeyNotFoundException.h"

KeyNotFoundException::KeyNotFoundException(std::string key) 
        throw () : Exception() {
    this->key = key;
}

KeyNotFoundException::KeyNotFoundException(const KeyNotFoundException& cause) 
        throw () : Exception(cause) {
    this->key = key;
}

KeyNotFoundException::KeyNotFoundException(std::string message, std::string key) 
        throw () : Exception(message) {
    this->key = key;
}

KeyNotFoundException::KeyNotFoundException(int cause, std::string message, 
                                           std::string key) 
        throw () : Exception(cause, message) {
    this->key = key;
}

std::string KeyNotFoundException::getKey()  throw () {
    return this->key;
}

KeyNotFoundException::~KeyNotFoundException()  throw () {
}

