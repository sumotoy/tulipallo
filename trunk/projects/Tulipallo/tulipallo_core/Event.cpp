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

#include "Event.h"

Event::Event() {
    //
}

Event::Event(void* source) {
    this->source = source;
}

Event::Event(unsigned long long time, void* source) {
    this->time   = time;
    this->source = source;
}

Event::Event(const Event& source) {
    this->time   = source.time;
    this->source = source.source;
}

unsigned long long Event::getTime() {
    return this->time;
}

void* Event::getSource() {
    return this->source;
}

Event::~Event() {
}

