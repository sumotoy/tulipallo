#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include "../tulipallo_core/Thread.h"

const double DEFAULT_GAIN = 1;

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