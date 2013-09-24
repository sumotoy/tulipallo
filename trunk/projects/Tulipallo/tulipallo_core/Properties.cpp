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

#include <stdlib.h>

#include "Properties.h"

Properties::Properties() {
    this->properties = new std::map<std::string, std::string>();
    this->mutex      = new pthread_mutex_t();
    
    Thread::initialize(this->mutex);
}

Properties::Properties(const Properties& orig) {
    this->properties = new std::map<std::string, std::string>(
            orig.properties->begin(), orig.properties->end());
    this->mutex = new pthread_mutex_t();
    
    Thread::initialize(this->mutex);
}

void Properties::load(std::string path) throw (PropertiesException) {
    Thread::lock(this->mutex);
    
    std::ifstream propertyfile;
    std::string   line;
    
    propertyfile.open(path.c_str());
    
    if(propertyfile.is_open()){
      while(propertyfile.good()) {
            std::getline(propertyfile, line);
            this->parseLine(line);
      }
      propertyfile.close();
    }
    else {
        throw PropertiesException("Exception loading file '" + path + "'.");
    }
    
    Thread::unlock(this->mutex);
}

void Properties::parseLine(std::string line) {
    if(line.length() > 1 && line.at(0) != '#') {
        std::string::size_type equals = line.find("=");
        
        // TODO Remove the trailing CR at the end of all lines.
        if(line.at((line.length() - 1)) == '\r')
                line.erase((line.length() - 1));
        
        if(equals != std::string::npos) {
            this->properties->insert(
                    std::pair<std::string, std::string>(line.substr(0, equals),
                                                        line.substr(equals + 1, line.length())));
        }
    }
}

std::string Properties::getProperty(std::string key) throw (KeyNotFoundException) {
    std::string local;
            
    Thread::lock(this->mutex);
    if(this->properties->count(key) > 0) {
        local = this->properties->at(key);
    }
    else {
        throw KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

int Properties::getInteger(std::string key) throw (KeyNotFoundException) {
    int local;
    
    Thread::lock(this->mutex);
    if(this->properties->count(key) > 0) {
        local = atoi(this->properties->at(key).c_str());
    }
    else {
        throw KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

unsigned int Properties::getUnsignedInteger(std::string key) throw (KeyNotFoundException) {
    unsigned int local;
    
    Thread::lock(this->mutex);
    if(this->properties->count(key) > 0) {
        local = atoi(this->properties->at(key).c_str());
    }
    else {
        throw KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

float Properties::getFloat(std::string key) throw (KeyNotFoundException) {
    float local;
    
    Thread::lock(this->mutex);
    if(this->properties->count(key) > 0) {
        local = atof(this->properties->at(key).c_str());
    }
    else {
        throw KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

double Properties::getDouble(std::string key) throw (KeyNotFoundException) {
    double local;
    
    Thread::lock(this->mutex);
    if(this->properties->count(key) > 0) {
        local = strtod(this->properties->at(key).c_str(), NULL);
    }
    else {
        throw KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

short Properties::getShort(std::string key) throw (KeyNotFoundException) {
    short local;
    
    Thread::lock(this->mutex);
    if(this->properties->count(key) > 0) {
        local = (short)atoi(this->properties->at(key).c_str());
    }
    else {
        throw KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

unsigned short Properties::getUnsignedShort(std::string key) throw (KeyNotFoundException) {
    unsigned short local;
    
    Thread::lock(this->mutex);
    if(this->properties->count(key) > 0) {
        local = (unsigned short)atoi(this->properties->at(key).c_str());
    }
    else {
        throw KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

long Properties::getLong(std::string key) throw (KeyNotFoundException) {
    long local;
    
    Thread::lock(this->mutex);
    if(this->properties->count(key) > 0) {
        local = atol(this->properties->at(key).c_str());
    }
    else {
        throw KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

unsigned long Properties::getUnsignedLong(std::string key) throw (KeyNotFoundException) {
    unsigned long local;
    
    Thread::lock(this->mutex);
    if(this->properties->count(key) > 0) {
        local = (unsigned long)atol(this->properties->at(key).c_str());
    }
    else {
        throw KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

bool Properties::getBoolean(std::string key) throw (KeyNotFoundException) {
    bool local;
    
    Thread::lock(this->mutex);
    if(this->properties->count(key) > 0) {
        local = (bool)this->properties->at(key).c_str();
    }
    else {
        throw KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

char Properties::getChar(std::string key) throw (KeyNotFoundException) {
    char local;
    
    Thread::lock(this->mutex);
    if(this->properties->count(key) > 0) {
        local = this->properties->at(key).at(0);
    }
    else {
        throw KeyNotFoundException(key);
    }
    Thread::unlock(this->mutex);
    
    return local;
}

std::map<std::string, std::string>* Properties::getProperties() throw (KeyNotFoundException) {
    return this->properties;
}

Properties::~Properties() {
    Thread::destroy(this->mutex);
    
    delete this->mutex;
    delete this->properties;
}

