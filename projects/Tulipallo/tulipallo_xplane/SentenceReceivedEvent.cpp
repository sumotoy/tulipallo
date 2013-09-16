/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "SentenceReceivedEvent.h"

SentenceReceivedEvent::SentenceReceivedEvent(XPlaneSentence* sentence) : Event() {
    this->sentence = sentence;
}

SentenceReceivedEvent::SentenceReceivedEvent(void* source, XPlaneSentence* sentence) : Event(source) {
    this->sentence = sentence;
}

SentenceReceivedEvent::SentenceReceivedEvent(unsigned long long time, void* source, 
                                             XPlaneSentence* sentence) : Event(time, source) {
    this->sentence = sentence;
}

SentenceReceivedEvent::SentenceReceivedEvent(const SentenceReceivedEvent& source) : Event(source) {
    this->sentence = source.sentence;
}

XPlaneSentence* SentenceReceivedEvent::getSentence() {
    return this->sentence;
}

SentenceReceivedEvent::~SentenceReceivedEvent() {
}

