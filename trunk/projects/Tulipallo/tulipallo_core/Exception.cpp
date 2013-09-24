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

