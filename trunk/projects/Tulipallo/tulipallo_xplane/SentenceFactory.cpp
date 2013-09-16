/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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

