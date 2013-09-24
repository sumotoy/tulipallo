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

#include "Button.h"

Button::Button() {
    this->listeners   = new std::list<IButtonListener*>();
    this->buttonMutex = new pthread_mutex_t();
    Thread::initialize(this->buttonMutex);
}

Button::Button(bool toggable) {
    this->listeners   = new std::list<IButtonListener*>();
    this->buttonMutex = new pthread_mutex_t();
    this->togglable   = toggable;
    Thread::initialize(this->buttonMutex);
}

Button::Button(IButtonCommand* command) {
    this->listeners   = new std::list<IButtonListener*>();
    this->buttonMutex = new pthread_mutex_t();
    this->command     = command;
    Thread::initialize(this->buttonMutex);
}

Button::Button(bool toggable, IButtonCommand* command) {
    this->listeners   = new std::list<IButtonListener*>();
    this->buttonMutex = new pthread_mutex_t();
    this->command     = command;
    this->togglable   = toggable;
    Thread::initialize(this->buttonMutex);
}

bool Button::isTogglable() {
    Thread::lock(this->buttonMutex);
    bool local = this->togglable;
    Thread::unlock(this->buttonMutex);
    
    return local;
}

void Button::setTogglable(bool togglable) {
    Thread::lock(this->buttonMutex);
    this->togglable = togglable;
    Thread::unlock(this->buttonMutex);
}

bool Button::isToggled() {
    Thread::lock(this->buttonMutex);
    bool local = this->toggled;
    Thread::unlock(this->buttonMutex);
    
    return local;
}

/**
 * Sets the toggled state without firing events.
 * 
 * @param toggled The toggle state for this button to be in.
 */
void Button::setToggled(bool toggled) {
    Thread::lock(this->buttonMutex);
    this->toggled = toggled;
    Thread::unlock(this->buttonMutex);
}

void Button::setCommand(IButtonCommand* command) {
    Thread::lock(this->buttonMutex);
    this->command = command;
    Thread::unlock(this->buttonMutex);
}

void Button::push() {
    Thread::lock(this->buttonMutex);
    this->fireButtonDownEvent();
    this->fireButtonUpEvent();
    this->fireButtonPressEvent();
    
    if(this->togglable) {
        this->toggled = !this->toggled;
        this->fireButtonToggledEvent();
    }
    Thread::unlock(this->buttonMutex);
}

void Button::addButtonListener(IButtonListener* listener) {
    Thread::lock(this->buttonMutex);
    this->listeners->push_back(listener);
    Thread::unlock(this->buttonMutex);
}

void Button::removeButtonListener(IButtonListener* listener) {
    Thread::lock(this->buttonMutex);
    this->listeners->remove(listener);
    Thread::unlock(this->buttonMutex);
}

void Button::fireButtonDownEvent() {
    //
}

void Button::fireButtonUpEvent() {
    //
}

void Button::fireButtonPressEvent() {
    //
}

void Button::fireButtonToggledEvent() {
    //
}

Button::~Button() {
    Thread::destroy(this->buttonMutex);
    
    delete this->listeners;
    delete this->buttonMutex;
}

