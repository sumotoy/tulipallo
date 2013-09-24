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

#ifndef SPEEDSENTENCE_H
#define	SPEEDSENTENCE_H

#include <sstream>
#include <string>
#include "XPlaneSentence.h"

static const int SPEED_COMMAND = 3;

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
class SpeedSentence : public XPlaneSentence {
public:
    SpeedSentence();
    SpeedSentence(float indKias, float indKeas, float trueKtas, float trueKtgs, 
                  float indMph, float trueMphas, float trueMphgs);
    SpeedSentence(const SpeedSentence& orig);
    
    virtual float getVindKias();
    virtual float getVindKeas();
    virtual float getVtrueKtas();
    virtual float getVtrueKtgs();
    virtual float getVindMph();
    virtual float getVtrueMphas();
    virtual float getVtrueMphgs();
    
    virtual int         getCommand();
    virtual std::string toString();
    
    virtual void unmarshall(DataStream* stream) 
                throw (MarshallingException);
    virtual void marshall(DataStream* stream) 
                throw (MarshallingException);
    
    virtual ~SpeedSentence();
    
private:
    float indKias;
    float indKeas;
    float trueKtas;
    float trueKtgs;
    float indMph;
    float trueMphas;
    float trueMphgs;
};

#endif	/* SPEEDSENTENCE_H */

