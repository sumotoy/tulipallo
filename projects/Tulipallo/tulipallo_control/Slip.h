/* 
 * File:   Slip.h
 * Author: Robert
 *
 * Created on June 26, 2013, 10:50 PM
 */

#ifndef SLIP_H
#define	SLIP_H

class Slip {
public:
    Slip();
    Slip(double slip);
    
    virtual void   copy(const Slip& orig);
    virtual double getSlip();
    virtual void   setSlip(double slip);
    
    virtual ~Slip();
    
private:
    double slip;
    
};

#endif	/* SLIP_H */

