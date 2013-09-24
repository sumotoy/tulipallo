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

