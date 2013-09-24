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

#ifndef SITUATIONSENTENCE_H
#define	SITUATIONSENTENCE_H

#include <sstream>
#include "../tulipallo_xplane/XPlaneSentence.h"

static const int SITUATION_COMMAND = 17;

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
class SituationSentence : public XPlaneSentence {
public:
    SituationSentence();
    SituationSentence(float pitchDeg, float rollDeg, float headingTrue, 
                      float headingMag);
    SituationSentence(const SituationSentence& orig);
    
    virtual float       getPitchDeg();
    virtual float       getRollDeg();
    virtual float       getHeadingTrue();
    virtual float       getHeadingMag();
    
    virtual int         getCommand();
    virtual std::string toString();
    
    virtual void unmarshall(DataStream* stream) 
                throw (MarshallingException);
    virtual void marshall(DataStream* stream) 
                throw (MarshallingException);
    
    virtual ~SituationSentence();
private:
    float pitchDeg;
    float rollDeg;
    float headingTrue;
    float headingMag;
};

#endif	/* SITUATIONSENTENCE_H */

