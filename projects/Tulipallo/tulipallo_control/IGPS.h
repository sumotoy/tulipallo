/* 
 * File:   GlobalPositioningService.h
 * Author: Robert
 *
 * Created on June 8, 2013, 5:23 PM
 */

#ifndef IGPS_H
#define	IGPS_H

#include "Position.h"

class IGPS {
public:
    IGPS();
    
    virtual Position getPosition() = 0;
    
    virtual ~IGPS();
private:

};

#endif	/* IGPS_H */

