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

#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include "../tulipallo_core/Thread.h"

const double DEFAULT_GAIN = 1;

/**
 * <p/>
 * <tt>Tulipallo - The Java Finite Volume Method Simulation<br />
 * Copyright &copy; 2010 M2 Astronautics<br />
 * <p/>
 * <tt>This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.</tt>
 * <p/>
 * <tt>You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.</tt>
 * 
 * @author Robert R Murrell
 * @version 1.0 beta
 */
class PIDController {
public:
    PIDController();
    PIDController(double previousError, double integral);
    PIDController(double previousError, double integral, double Kp, 
                  double Ki, double Kd);
    PIDController(const PIDController& orig);

    virtual void   setProportionalGain(double Kp);
    virtual double getProportionalGain();
    virtual void   setIntegralGain(double Ki);
    virtual double getIntegralGain();
    virtual void   setDerivativeGain(double Kd);
    virtual double getDerivativeGain();
    virtual void   setControlPoint(double setPoint);
    virtual double getControlPoint();
    virtual void   reset();
    virtual double getIntegral();
    virtual void   setIntegral(double integral);
    virtual double getPreviousError();
    virtual void   setPreviousError(double previousError);
    
    virtual double getOutput();
    
    virtual double calculate(double measurement, unsigned long long dt);
    
    virtual ~PIDController();
    
private:
    double previousError;
    double integral;
    double controlPoint;
    double output;
    double Kp;
    double Ki;
    double Kd;
    
    pthread_mutex_t* mutex;
};

#endif /* PIDCONTROLLER_H */