/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "FlightController.h"

FlightController::FlightController() {
    this->situation        = new BaseSituation();
    this->gncMutex         = new pthread_mutex_t();
    this->runningMutex     = new pthread_mutex_t();
    this->clock            = new Clock();
    this->controlRuleChain = new PIDControlRule();
    this->enabled          = false;
    
    this->situation->setClock(this->clock);
    Thread::initialize(this->gncMutex);
    Thread::initialize(this->runningMutex);
}

void FlightController::setClockFrequency(unsigned int clockFrequency) {
    this->clock->setFrequency(clockFrequency);
}

unsigned int FlightController::getClockFrequency() {
    return this->clock->getFrequency();
}

void FlightController::setGyro(IGyro* gyro) {
    this->gyro = gyro;
}

IGyro* FlightController::getGyro() {
    return this->gyro;
}

void FlightController::setGPS(IGPS* gps) {
    this->gps = gps;
}

IGPS* FlightController::getGPS() {
    return this->gps;
}

void FlightController::setControlSurface(IControlSurface* controlSurfaces) {
    this->controlSurfaces = controlSurfaces;
}

IControlSurface* FlightController::getControlSurface() {
    return this->controlSurfaces;
}

void FlightController::setSlipIndicator(ISlipIndicator* slipIndicator) {
    this->slipIndicator = slipIndicator;
}

ISlipIndicator* FlightController::getSlipIndicator() {
    return this->slipIndicator;
}

void FlightController::setEnabled(bool enabled) {
    Thread::lock(this->gncMutex);
    this->enabled = enabled;
    Thread::unlock(this->gncMutex);
}

bool FlightController::isEnabled() {
    Thread::lock(this->gncMutex);
    bool local = this->enabled;
    Thread::unlock(this->gncMutex);
    
    return local;
}

void FlightController::on() {
    Thread::lock(this->gncMutex);
    this->clock->addClockListener(this);
    this->clock->initialize();
    this->clock->start(true);
    this->running = true;
    Thread::unlock(this->gncMutex);
}

void FlightController::off() {
    Thread::lock(this->gncMutex);
    Thread::lock(this->runningMutex);
    this->clock->stop();
    this->clock->terminate();
    this->clock->removeClockListener(this);
    this->running = false;
    Thread::unlock(this->runningMutex);
    Thread::unlock(this->gncMutex);
}

bool FlightController::isOn() {
    Thread::lock(this->runningMutex);
    bool local = this->running;
    Thread::unlock(this->runningMutex);
    
    return local;
}

void FlightController::join() throw (ThreadException) {
    this->clock->join();
}

PIDController* FlightController::getHeadingController() {
    return this->controlRuleChain->getHeadingController();
}

PIDController* FlightController::getPitchController() {
    return this->controlRuleChain->getPitchController();
}

PIDController* FlightController::getRollController() {
    return this->controlRuleChain->getRollController();
}

PIDController* FlightController::getYawController() {
    return this->controlRuleChain->getYawController();
}

void FlightController::addGuidanceRule(Rule* command) {
    if(!this->isOn()) {
        Thread::lock(this->gncMutex);
        if(this->guidanceRuleChain != NULL) {
            this->guidanceRuleChain->addLink(command);
        }
        else {
            this->guidanceRuleChain = command;
        }
        Thread::unlock(this->gncMutex);
    }
    else {
        throw IllegalStateException();
    }
}

void FlightController::addNavigationRule(Rule* command) {
    if(!this->isOn()) {
        Thread::lock(this->gncMutex);
        if(this->navigationRuleChain != NULL) {
            this->navigationRuleChain->addLink(command);
        }
        else {
            this->navigationRuleChain = command;
        }
        Thread::unlock(this->gncMutex);
    }
    else {
        throw IllegalStateException();
    }
}

void FlightController::addControlRule(Rule* command) {
    if(!this->isOn()) {
        Thread::lock(this->gncMutex);
        this->controlRuleChain->addLink(command);
        Thread::unlock(this->gncMutex);
    }
    else {
        throw IllegalStateException();
    }
}

void FlightController::handleClockStart(ClockStartEvent event) {
    std::cout << "Clock has started. \r\n";
}

void FlightController::handleClockStop(ClockStopEvent event) {
    std::cout << "Clock has stopped. \r\n";
}

ISituation* FlightController::getSituation() {
    return this->situation;
}

/**
 * This method performs a simple Guidance, Navigation, Control, or GNC process 
 * loop. 
 * <p/>
 * Guidance loads the <tt>situation</tt> with the current attitude, velocity, 
 * etc... then executes the guidance rule chain, followed by the navigation rule
 * chain, then the control rule chain. The control rule chain generally converts 
 * desired attitude inputs to the correct, corresponding control surface 
 * deflections and nulling out turbulence, drift, slip, or other errors. 
 * Navigation can be preempted by guidance, allowing for the activation of 
 * things like spin recovery or flight leveling. Finally, the desired inputs are 
 * set to the control surface for output.
 * <p/>
 * This locks on <tt>gncMutex</tt> to make the adding of rules thread safe.
 * 
 * @param event The ClockTickEvent from the system clock.
 */
void FlightController::handleClockTick(ClockTickEvent event) {
    Thread::lock(this->gncMutex);
    
    // Load the situation from the sensors and controls
    this->loadSituation();
    
    // Perform Guidance
    this->executeGuidanceRuleChain();
    
    if(!this->situation->isAborted()) {
        if(!this->situation->isPreempted()) {
            this->executeNavigationRuleChain();
        }
        
        if(!this->situation->isAborted() && this->enabled) {
            // Perform Control
            // TODO: Use the preempted to determine how "dramatic" we respond to 
            // control input. i.e. if preempted try to get to new orientation 
            // as quickly as possible...
            this->executeControlRuleChain();

            // Send Control Commands
            this->controlSurfaces->setPosition(
                    this->situation->getInputControlSurfacePosition());
        } // TODO: Do something on an abort...
    } // TODO: Do something on an abort...
    
    this->situation->setPreempted(false);
    
    Thread::unlock(this->gncMutex);
}

void FlightController::executeGuidanceRuleChain() {
    if(this->guidanceRuleChain != NULL) {
        this->guidanceRuleChain->execute(this->situation);
    }
}

void FlightController::executeNavigationRuleChain() {
    if(this->navigationRuleChain != NULL) {
        this->navigationRuleChain->execute(this->situation);
    }
}

void FlightController::executeControlRuleChain() {
    if(this->controlRuleChain != NULL) {
        this->controlRuleChain->execute(this->situation);
    }
}

void FlightController::loadSituation() {
    // Need to figure out if I need to lock ALL devices on one mutex or just
    // assume the changes in situation between calls to devices will be trivial 
    // and NULLed out by the PID controllers
    this->situation->setAttitude(this->gyro->getAttitude());
    this->situation->setPosition(this->gps->getPosition());
    this->situation->setControlSurfacePosition(this->controlSurfaces->getPosition());
    this->situation->setSlip(this->slipIndicator->getSlip());
}

void FlightController::handleException(ExceptionEvent event) throw() {
    std::cout << "Exception: code=" << event.getException().getCode() 
              << ", message=" << event.getException().getMessage() << "\r\n";
}

FlightController::~FlightController() {
    Thread::destroy(this->gncMutex);
    Thread::destroy(this->runningMutex);
    
    this->clock->stop();
    this->clock->terminate();
    
    delete this->gncMutex;
    delete this->runningMutex;
    delete this->clock;
    delete this->situation;
    delete this->controlRuleChain;
}

