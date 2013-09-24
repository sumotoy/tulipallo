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

#ifndef BASESITUATION_H
#define	BASESITUATION_H

#include "ISituation.h"

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
class BaseSituation : public ISituation {
public:
    BaseSituation();
    BaseSituation(const BaseSituation& orig);
    
    virtual Attitude*               getAttitude();
    virtual void                    setAttitude(const Attitude& orientation);
    virtual Attitude*               getInputAttitude();
    virtual void                    setInputAttitude(const Attitude& inputOrientation);
    virtual Slip*                   getSlip();
    virtual void                    setSlip(const Slip& slip);
    virtual void                    setInputYaw(const Yaw& yaw);
    virtual Yaw*                    getInputYaw();
    virtual Position*               getPosition();
    virtual void                    setPosition(const Position& position);
    virtual ControlSurfacePosition* getControlSurfacePosition();
    virtual void                    setControlSurfacePosition(const ControlSurfacePosition& position);
    virtual ControlSurfacePosition* getInputControlSurfacePosition();
    virtual void                    setInputControlSurfacePosition(const ControlSurfacePosition& position);
    virtual Clock*                  getClock();
    virtual void                    setClock(Clock* clock);
    virtual void                    setPreempted(bool preempted);
    virtual bool                    isPreempted();
    virtual void                    setAborted(bool aborted);
    virtual bool                    isAborted();
    
    virtual ~BaseSituation();
    
private:
    Attitude*               attitude;
    Attitude*               inputAttitude;
    Slip*                   slip;
    Yaw*                    yaw;
    Position*               position;
    ControlSurfacePosition* controlSurfacePosition;
    ControlSurfacePosition* inputControlSurface;
    bool                    preempt;
    bool                    abort;
    Clock*                  clock;
};

#endif	/* BASESITUATION_H */

