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

