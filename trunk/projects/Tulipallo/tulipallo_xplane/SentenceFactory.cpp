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

#include "SentenceFactory.h"

SentenceFactory::SentenceFactory() {
    this->link = NULL;
}

void SentenceFactory::addLink(SentenceFactory* link) {
    if(this->link == NULL) {
        this->link = link;
    }
    else {
        this->link->addLink(link);
    }
}

XPlaneSentence* SentenceFactory::create(int command) 
                throw (MarshallingException) {
    if(this->isFactory(command)) {
        return this->newInstance();
    }
    else {
        if(this->link != NULL) {
            return this->link->create(command);
        }
        else {
            return NULL;
        }
    }
}

SentenceFactory::~SentenceFactory() {
}

