/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "Rule.h"

Rule::Rule() {
    this->link    = NULL;
    this->mutex   = new pthread_mutex_t();
    this->enabled = true;
    Thread::initialize(this->mutex);
}

void Rule::execute(ISituation* situation) {
    Thread::lock(this->mutex);
    if(this->enabled)
        this->doCommand(situation);
    if(this->link != NULL) {
        if((!situation->isPreempted() || !situation->isAborted()) 
                    && this->enabled) {
            this->link->execute(situation);
        }
    }
    Thread::unlock(this->mutex);
}

void Rule::addLink(Rule* link) {
    Thread::lock(this->mutex);
    if(this->link != NULL) {
        this->link->addLink(link);
    }
    else {
        this->link = link;
    }
    Thread::unlock(this->mutex);
}

bool Rule::isEnabled() {
    Thread::lock(this->mutex);
    return this->enabled;
    Thread::unlock(this->mutex);
}

void Rule::setEnabled(bool enabled) {
    Thread::lock(this->mutex);
    this->enabled = enabled;
    Thread::unlock(this->mutex);
}

Rule::~Rule() {
    // Do not delete link because its not mine...
    Thread::destroy(this->mutex);
    
    delete this->mutex;
}

