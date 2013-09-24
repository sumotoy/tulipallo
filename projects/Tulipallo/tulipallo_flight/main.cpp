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

#include <iostream>
#include "../tulipallo_xplane/MessageHandler.h" // TODO: ELIMINATE THIS REFERENCE to an implementation.
#include "FlightController.h"
#include "LevelFlightGuidanceRule.h"
#include "AttitudeToControlSurfaceRule.h"
#include "FlightControllerActivator.h"
#include "FlightControllerOff.h"
#include "PIDControllerZero.h"
#include "../tulipallo_control/ControlSurfacePosition.h"
#include "../tulipallo_control/PIDAttitude.h"
#include "../tulipallo_control/PIDController.h"
#include "../tulipallo_core/GPIOFactorySingleton.h"
#include "../tulipallo_core/IGPIOFactory.h"
#include "../tulipallo_core/GPIO.h"
#include "../tulipallo_core/Properties.h"
#include "../tulipallo_core/ObjectFactory.h"
#include "../tulipallo_control/IGyro.h"

/**
 * 
 */
int main(int argc, char** argv) {
    Properties* factoryProperties = new Properties();
    factoryProperties->load("factory.properties");
    
    ObjectFactory* factory = new ObjectFactory();
    factory->load(factoryProperties);
    
    IGyro*                gyro  = factory->newInstance<IGyro*>("IGyro");
    IGPS*                 gps   = factory->newInstance<IGPS*>("IGPS");
    ISlipIndicator*       slp   = factory->newInstance<ISlipIndicator*>("ISlipIndicator");
    IControlSurface*      csp   = factory->newInstance<IControlSurface*>("IControlSurface");
    IGPIOFactoryProvider* gpiof = factory->newInstance<IGPIOFactoryProvider*>("IGPIOFactoryProvider");
    
    GPIOFactorySingleton::create(gpiof);
    
    IGPIOFactory* gpioFactory  = GPIOFactorySingleton::getInstance();
    GPIO* gpio3 = gpioFactory->registerGPIO(new Pin(3, IO_OUTPUT));
    GPIO* gpio4 = gpioFactory->registerGPIO(new Pin(4, IO_OUTPUT));
    GPIO* gpio0 = gpioFactory->registerGPIO(new Pin(0, IO_INPUT, IO_PULL_UP));
    GPIO* gpio1 = gpioFactory->registerGPIO(new Pin(1, IO_INPUT, IO_PULL_UP));
    GPIO* gpio2 = gpioFactory->registerGPIO(new Pin(2, IO_INPUT, IO_PULL_UP));
    
    FlightController* controller = new FlightController();
    
    LevelFlightGuidanceRule*      levelRule   = new LevelFlightGuidanceRule();
    AttitudeToControlSurfaceRule* controlRule = new AttitudeToControlSurfaceRule();
    
    FlightControllerActivator* activator = 
            new FlightControllerActivator(controller, gpio4, 
            MessageHandler::getInstance()->getMessageTransmitter());
    FlightControllerOff*       deactivator = 
            new FlightControllerOff(controller);
    
    PIDControllerZero* errorZero = new PIDControllerZero(controller);
    
    gpio0->addStateChangedListener(activator);
    gpio1->addStateChangedListener(errorZero);
    gpio2->addStateChangedListener(deactivator);
    
    controller->setClockFrequency(50);
    controller->setControlSurface(csp);
    controller->setGPS(gps);
    controller->setGyro(gyro);
    controller->setSlipIndicator(slp);
    controller->addGuidanceRule(levelRule);
    controller->addControlRule(controlRule);
    
    controller->getHeadingController()->setProportionalGain(1);
    controller->getHeadingController()->setIntegralGain(0.001);
    controller->getHeadingController()->setDerivativeGain(1);
    
    controller->getPitchController()->setProportionalGain(1);
    controller->getPitchController()->setIntegralGain(0.001);
    controller->getPitchController()->setDerivativeGain(1);
    
    controller->getRollController()->setProportionalGain(.5);
    controller->getRollController()->setIntegralGain(0.0001);
    controller->getRollController()->setDerivativeGain(.8);
    
    controller->getYawController()->setProportionalGain(.5);
    controller->getYawController()->setIntegralGain(0.0001);
    controller->getYawController()->setDerivativeGain(.8);
    
    gpio3->setState(IO_HIGH);
    gpio0->setInterruptable();
    gpio1->setInterruptable();
    gpio2->setInterruptable();
    
    controller->on();
    
    controller->join();
    
    gpio3->setState(IO_LOW);
    gpio4->setState(IO_LOW);
    gpio0->setState(IO_LOW);
    gpio1->setState(IO_LOW);
    gpio2->setState(IO_LOW);
    
    ControlSurfaceSentence* cp = new ControlSurfaceSentence(-999.0, -999.0, -999.0);
    
    MessageHandler::getInstance()->getMessageTransmitter()->queue(cp);
    MessageHandler::getInstance()->getMessageTransmitter()->send();
    
    return 0;
}