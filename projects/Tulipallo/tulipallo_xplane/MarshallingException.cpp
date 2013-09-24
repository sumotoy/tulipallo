/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2010 M2 Astronautics
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 *
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

