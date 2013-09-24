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

#ifndef CONTROLSURFACEPOSITION_H
#define	CONTROLSURFACEPOSITION_H

const double DEFAULT_LIMIT = 1;

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
class ControlSurfacePosition {
public:
    ControlSurfacePosition();
    ControlSurfacePosition(float elevator, float aileron, float rudder);
    ControlSurfacePosition(float elevator, float aileron, float rudder, 
                           float limit);
    ControlSurfacePosition(const ControlSurfacePosition& orig);
    
    virtual void  copy(const ControlSurfacePosition& orig);
    virtual float getElevator();
    virtual void  setElevator(float elevator);
    virtual float getAileron();
    virtual void  setAileron(float aileron);
    virtual float getRudder();
    virtual void  setRudder(float rudder);
    virtual float getLimit();
    virtual void  setLimit(float limit);
    
    virtual ~ControlSurfacePosition();

protected:
    virtual double limitValue(float value);
    
private:
    float elevator;
    float aileron;
    float rudder;
    float limit;
    
};

#endif	/* CONTROLSURFACEPOSITION_H */

