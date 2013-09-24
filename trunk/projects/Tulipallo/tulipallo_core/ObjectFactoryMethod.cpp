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

#include "ObjectFactoryMethod.h"

ObjectFactoryMethod::ObjectFactoryMethod(std::string library, void* handle, 
                                         void* (*factory)(Context*)) {
    this->lib     = library;
    this->handle  = handle;
    this->factory = factory;
}

void* ObjectFactoryMethod::newInstance(Context* context) 
                throw (ObjectFactoryException) {
    try {
        return this->factory(context);
    }
    catch(...) {
        throw ObjectFactoryException(
                "Exception creating instance for library '"  + this->lib  + "'.");
    }
}

std::string ObjectFactoryMethod::getLibrary() {
    return this->lib;
}

ObjectFactoryMethod::~ObjectFactoryMethod() {
    dlclose(this->handle);
    
    free(this->handle);
    free((void*)this->factory);
}

