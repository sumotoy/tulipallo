/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "MarshallingException.h"

MarshallingException::MarshallingException(
        int command) throw () : Exception() {
    this->command = command;
}

MarshallingException::MarshallingException(
        const MarshallingException& source) throw () : Exception(source) {
    this->command = source.command;
}

MarshallingException::MarshallingException(
        int command, std::string message) throw () : Exception(message) {
    this->command = command;
}

MarshallingException::MarshallingException(
        int command, int code, std::string message) throw () : Exception(code, message) {
    this->command = command;
}

int MarshallingException::getCommand() throw () {
    return this->command;
}

MarshallingException::~MarshallingException() throw () {
}

