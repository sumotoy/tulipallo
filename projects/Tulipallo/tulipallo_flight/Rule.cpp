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

