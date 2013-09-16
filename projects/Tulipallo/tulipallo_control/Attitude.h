/* 
 * File:   Orientation.h
 * Author: Robert
 *
 * Created on June 8, 2013, 5:52 PM
 */

#ifndef ATTITUDE_H
#define	ATTITUDE_H

class Attitude {
public:
    Attitude();
    Attitude(double heading, double pitch, double roll);
    Attitude(const Attitude& orig);
    
    virtual void   copy(const Attitude& orig);
    virtual void   setHeading(double heading);
    virtual double getHeading();
    virtual void   setPitch(double pitch);
    virtual double getPitch();  
    virtual void   setRoll(double roll);
    virtual double getRoll();
    
    virtual ~Attitude();
    
private:
    double heading;
    double pitch;
    double roll;
};

#endif	/* ATTITUDE_H */

