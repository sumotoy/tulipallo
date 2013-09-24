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

#include "PIDController.h"

PIDController::PIDController() {
    this->previousError = 0;
    this->integral      = 0;
    this->Kp            = DEFAULT_GAIN;
    this->Ki            = DEFAULT_GAIN;
    this->Kd            = DEFAULT_GAIN;
    
    this->mutex = new pthread_mutex_t();
    Thread::initialize(this->mutex);
}

PIDController::PIDController(double previousError, double integral) {
    this->previousError = previousError;
    this->integral      = integral;
    this->Kp            = DEFAULT_GAIN;
    this->Ki            = DEFAULT_GAIN;
    this->Kd            = DEFAULT_GAIN;
    
    this->mutex = new pthread_mutex_t();
    Thread::initialize(this->mutex);
}

PIDController::PIDController(double previousError, double integral, double Kp, 
                             double Ki, double Kd) {
    this->previousError = previousError;
    this->integral      = integral;
    this->Kp            = Kp;
    this->Ki            = Ki;
    this->Kd            = Kd;
    
    this->mutex = new pthread_mutex_t();
    Thread::initialize(this->mutex);
}

PIDController::PIDController(const PIDController& orig) {
    this->previousError = orig.previousError;
    this->integral      = orig.integral;
    this->Kp            = orig.Kp;
    this->Ki            = orig.Ki;
    this->Kd            = orig.Kd;
    
    this->mutex = new pthread_mutex_t();
    Thread::initialize(this->mutex);
}

void PIDController::reset() {
    Thread::lock(this->mutex);
    this->previousError = 0;
    this->integral      = 0;
    Thread::unlock(this->mutex);
}

void PIDController::setProportionalGain(double Kp) {
    Thread::lock(this->mutex);
    this->Kp = Kp;
    Thread::unlock(this->mutex);
}

double PIDController::getProportionalGain() {
    Thread::lock(this->mutex);
    double local = this->Kp;
    Thread::unlock(this->mutex);
    
    return local;
}

void PIDController::setIntegralGain(double Ki) {
    Thread::lock(this->mutex);
    this->Ki = Ki;
    Thread::unlock(this->mutex);
}

double PIDController::getIntegralGain() {
    Thread::lock(this->mutex);
    double local = this->Ki;
    Thread::unlock(this->mutex);
    
    return local;
}

void PIDController::setDerivativeGain(double Kd) {
    Thread::lock(this->mutex);
    this->Kd = Kd;
    Thread::unlock(this->mutex);
}

double PIDController::getDerivativeGain() {
    Thread::lock(this->mutex);
    double local =  this->Kd;
    Thread::unlock(this->mutex);
    
    return local;
}

void PIDController::setControlPoint(double setPoint) {
    Thread::lock(this->mutex);
    this->controlPoint = setPoint;
    Thread::unlock(this->mutex);
}

double PIDController::getControlPoint() {
    Thread::lock(this->mutex);
    double local = this->controlPoint;
    Thread::unlock(this->mutex);
    
    return local;
}

double PIDController::getIntegral() {
    Thread::lock(this->mutex);
    double local = this->integral;
    Thread::unlock(this->mutex);
    
    return local;
}

void PIDController::setIntegral(double integral) {
    Thread::lock(this->mutex);
    this->integral = integral;
    Thread::unlock(this->mutex);
}

double PIDController::getPreviousError() {
    Thread::lock(this->mutex);
    double local = this->previousError;
    Thread::unlock(this->mutex);
    
    return local;
}

void PIDController::setPreviousError(double previousError) {
    Thread::lock(this->mutex);
    this->previousError = previousError;
    Thread::unlock(this->mutex);
}

double PIDController::getOutput() {
    Thread::lock(this->mutex);
    double local = this->output;
    Thread::unlock(this->mutex);
    
    return local;
}

double PIDController::calculate(double measurement, unsigned long long dt) {
    Thread::lock(this->mutex);
    double error        = this->controlPoint - measurement;
    this->integral      = this->integral + error * dt;
    double derivative   = (error - this->previousError) / dt;
    this->output        = this->Kp * error + this->Ki * this->integral + 
                          this->Kd * derivative;
    this->previousError = error;
    Thread::unlock(this->mutex);
    
    return this->output;
}

PIDController::~PIDController() {
    Thread::destroy(this->mutex);
    
    delete this->mutex;
}


