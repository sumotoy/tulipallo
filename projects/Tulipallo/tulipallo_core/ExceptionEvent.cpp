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

#include "ExceptionEvent.h"

ExceptionEvent::ExceptionEvent(Exception exception) : 
        Event() {
    this->exception = exception;
}

ExceptionEvent::ExceptionEvent(void* source, Exception exception) : 
        Event(source) {
    this->exception = exception;
}

ExceptionEvent::ExceptionEvent(unsigned long long time, void* source, 
                               Exception exception) : Event(time, source) {
    this->exception = exception;
}

/**
 * Returns the Exception that caused this event to be thrown.
 * 
 * @return the Exception that caused this event to be thrown.
 */
Exception ExceptionEvent::getException() {
    return this->exception;
}

ExceptionEvent::~ExceptionEvent() {
}

