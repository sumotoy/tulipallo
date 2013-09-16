/* 
 * File:   Yaw.h
 * Author: Robert
 *
 * Created on June 27, 2013, 8:53 PM
 */

#ifndef YAW_H
#define	YAW_H

class Yaw {
public:
    Yaw();
    Yaw(double degrees);
    
    virtual void copy(const Yaw& orig);
    virtual void setDegrees(double degrees);
    virtual double getDegrees();
    
    virtual ~Yaw();
    
private:
    double degrees;
    
};

#endif	/* YAW_H */

