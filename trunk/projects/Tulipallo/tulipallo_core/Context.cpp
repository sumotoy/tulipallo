/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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

