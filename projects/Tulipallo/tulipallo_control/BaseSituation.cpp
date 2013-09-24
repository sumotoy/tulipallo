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

#include "BaseSituation.h"

BaseSituation::BaseSituation() {
    this->attitude               = new Attitude();
    this->inputAttitude          = new Attitude();
    this->slip                   = new Slip();
    this->yaw                    = new Yaw();
    this->position               = new Position();
    this->inputControlSurface    = new ControlSurfacePosition();
    this->controlSurfacePosition = new ControlSurfacePosition();
}

BaseSituation::BaseSituation(const BaseSituation& orig) {
    this->attitude               = orig.attitude;
    this->inputAttitude          = orig.inputAttitude;
    this->slip                   = orig.slip;
    this->yaw                    = orig.yaw;
    this->position               = orig.position;
    this->inputControlSurface    = orig.inputControlSurface;
    this->controlSurfacePosition = orig.controlSurfacePosition;
    this->clock                  = orig.clock;
    this->abort                  = orig.abort;
    this->preempt                = orig.preempt;
}

void BaseSituation::setInputYaw(const Yaw& yaw) {
    this->yaw->copy(yaw);
}

Yaw* BaseSituation::getInputYaw() {
    return this->yaw;
}

Attitude* BaseSituation::getAttitude() {
    return this->attitude;
}

void BaseSituation::setAttitude(const Attitude& orientation) {
    this->attitude->copy(orientation);
}

Attitude* BaseSituation::getInputAttitude() {
    return this->inputAttitude;
}

void BaseSituation::setInputAttitude(const Attitude& inputOrientation) {
    this->inputAttitude->copy(inputOrientation);
}

Slip* BaseSituation::getSlip() {
    return this->slip;
}

void BaseSituation::setSlip(const Slip& slip) {
    this->slip->copy(slip);     
}

Position* BaseSituation::getPosition() {
    return this->position;
}

void BaseSituation::setPosition(const Position& position) {
    this->position->copy(position);
}

ControlSurfacePosition* BaseSituation::getControlSurfacePosition() {
    return this->controlSurfacePosition;
}

void BaseSituation::setControlSurfacePosition(const ControlSurfacePosition& position) {
    this->controlSurfacePosition->copy(position);
}

ControlSurfacePosition* BaseSituation::getInputControlSurfacePosition() {
    return this->inputControlSurface;
}

void BaseSituation::setInputControlSurfacePosition(const ControlSurfacePosition& position) {
    this->inputControlSurface->copy(position);
}

Clock* BaseSituation::getClock(){
    return this->clock;
}

 void BaseSituation::setClock(Clock* clock){
    this->clock = clock;
}

void BaseSituation::setPreempted(bool preempted) {
    this->preempt = preempted;
}

bool BaseSituation::isPreempted() {
    return this->preempt;
}

void BaseSituation::setAborted(bool aborted) {
    this->abort = aborted;
}

bool BaseSituation::isAborted() {
    return this->abort;
}

BaseSituation::~BaseSituation() {
    delete this->attitude;
    delete this->inputAttitude;
    delete this->slip;
    delete this->position;
    delete this->controlSurfacePosition;
    delete this->inputControlSurface;
}

