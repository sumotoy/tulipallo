/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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

