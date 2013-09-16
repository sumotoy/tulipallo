/* 
 * File:   IControlSurface.h
 * Author: Robert
 *
 * Created on June 10, 2013, 10:24 PM
 */

#ifndef ICONTROLSURFACE_H
#define	ICONTROLSURFACE_H

#include "ControlSurfacePosition.h"

class IControlSurface {
public:
    IControlSurface();
    
    virtual ControlSurfacePosition getPosition()                                 = 0;
    virtual void                   setPosition(ControlSurfacePosition* position) = 0;
    
    virtual ~IControlSurface();
private:

};

#endif	/* ICONTROLSURFACE_H */

