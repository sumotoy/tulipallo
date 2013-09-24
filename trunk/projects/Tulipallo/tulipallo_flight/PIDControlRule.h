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

#ifndef PIDCONTROLRULE_H
#define	PIDCONTROLRULE_H

#include "Rule.h"
#include "../tulipallo_control/PIDAttitude.h"
#include "../tulipallo_control/Attitude.h"
#include "../tulipallo_control/PIDController.h"
#include "../tulipallo_control/Yaw.h"

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
class PIDControlRule : public Rule {
public:
    PIDControlRule();
    
    virtual PIDController* getHeadingController();
    virtual PIDController* getRollController();
    virtual PIDController* getPitchController();
    virtual PIDController* getYawController();
    
    virtual ~PIDControlRule();
    
protected:
    virtual void doCommand(ISituation* situation);
    
private:
    PIDAttitude*   pattitude;
    PIDController* yawController;
};

#endif	/* PIDCONTROLRULE_H */

