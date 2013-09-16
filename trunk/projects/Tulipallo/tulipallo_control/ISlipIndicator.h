/* 
 * File:   ISlipIndicator.h
 * Author: Robert
 *
 * Created on June 26, 2013, 10:57 PM
 */

#ifndef ISLIPINDICATOR_H
#define	ISLIPINDICATOR_H

#include "Slip.h"

class ISlipIndicator {
public:
    ISlipIndicator();
    
    virtual Slip getSlip() = 0;
    
    virtual ~ISlipIndicator();
private:

};

#endif	/* ISLIPINDICATOR_H */

