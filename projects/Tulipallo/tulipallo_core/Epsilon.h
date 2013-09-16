/* 
 * File:   Epsilon.h
 * Author: Robert
 *
 * Created on June 3, 2013, 11:45 PM
 */

#ifndef EPSILON_H
#define	EPSILON_H

#include <math.h>

const double BINARY16_PRECISION  = pow(2, -11);
const double BINARY32_PRECISION  = pow(2, -24);
const double BINARY64_PRECISION  = pow(2, -53);
const double BINARY128_PRECISION = pow(2, -113);

class Epsilon {
public:
    Epsilon();
    Epsilon(double precision);
    Epsilon(const Epsilon& source);
    
    virtual double getPrecision();
    virtual bool isLessThan(float value);
    
    virtual ~Epsilon();
private:
    double precision;
};

#endif	/* EPSILON_H */

