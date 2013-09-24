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

#include "Context.h"

Context::Context() {
    this->properties = new std::map<std::string, void*>();
}

Context::Context(const Context& orig) {
}

void* Context::getProperty(std::string key) {
    return this->properties->at(key);
}

void Context::setProperty(std::string key, void* value) {
    this->properties->insert(std::pair<std::string, void*>(key, value));
}

void Context::setProperties(Properties* properties) {
//    std::map<std::string, std::string>* props = properties->getProperties();
//    
//    for(std::map<std::string, std::string>::iterator it = props->begin();
//            it != props->end(); ++it) {
//        this->properties->insert(
//                std::pair<std::string, void*>(it->first, it->second));
//    }
}

void Context::setProperties(std::map<std::string, void*>* properties) {
    this->properties->insert(properties->begin(), properties->end());
}

bool Context::contains(std::string key) {
    return this->properties->count(key) > 0;
}

Context::~Context() {
    delete this->properties;
}

