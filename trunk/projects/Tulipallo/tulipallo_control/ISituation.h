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

#ifndef ISITUATION_H
#define	ISITUATION_H

#include "Attitude.h"
#include "Position.h"
#include "ControlSurfacePosition.h"
#include "Slip.h"
#include "Yaw.h"
#include "../tulipallo_core/Clock.h"

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
class ISituation {
public:
    ISituation();
    
    virtual Clock*                  getClock()                                                             = 0;
    virtual Attitude*               getAttitude()                                                          = 0;
    virtual Slip*                   getSlip()                                                              = 0;
    virtual void                    setInputYaw(const Yaw& yaw)                                            = 0;
    virtual Yaw*                    getInputYaw()                                                          = 0;
    virtual Attitude*               getInputAttitude()                                                     = 0;
    virtual void                    setInputAttitude(const Attitude& inputOrientation)                     = 0;
    virtual Position*               getPosition()                                                          = 0;
    virtual ControlSurfacePosition* getControlSurfacePosition()                                            = 0;
    virtual ControlSurfacePosition* getInputControlSurfacePosition()                                       = 0;
    virtual void                    setInputControlSurfacePosition(const ControlSurfacePosition& position) = 0;
    virtual void                    setPreempted(bool preempted)                                           = 0;
    virtual bool                    isPreempted()                                                          = 0;
    virtual void                    setAborted(bool aborted)                                               = 0;
    virtual bool                    isAborted()                                                            = 0;
    
    virtual ~ISituation();

};

#endif	/* ISITUATION_H */

