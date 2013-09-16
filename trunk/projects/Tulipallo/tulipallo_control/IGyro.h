/* 
 * File:   Gyro.h
 * Author: Robert
 *
 * Created on June 8, 2013, 5:52 PM
 */

#ifndef IGYRO_H
#define	IGYRO_H

#include "Attitude.h"

class IGyro {
public:
    IGyro();
    
    virtual Attitude getAttitude() = 0;
    
    virtual ~IGyro();
    
private:

};

#endif	/* IGYRO_H */

