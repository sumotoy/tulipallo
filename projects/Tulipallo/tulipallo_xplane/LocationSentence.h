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

#ifndef LOCATIONSENTENCE_H
#define	LOCATIONSENTENCE_H

#include <sstream>
#include "XPlaneSentence.h"

static const int LOCATION_COMMAND = 20;

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
class LocationSentence : public XPlaneSentence {
public:
    LocationSentence();
    LocationSentence(float latDeg, float lonDeg, float altFtmsl, float altFtagl, 
                     bool  onRunway, float altInd, float latSouth, float lonWest);
    LocationSentence(const LocationSentence& orig);
    
    virtual float getLatDeg();
    virtual float getLonDeg();
    virtual float getAltFtmsl();
    virtual float getAltFtagl();
    virtual bool  isOnRunway();
    virtual float getAltInd();
    virtual float getLatSouth();
    virtual float getLonWest();
    
    virtual int         getCommand();
    virtual std::string toString();
    
    virtual void unmarshall(DataStream* stream) 
                throw (MarshallingException);
    virtual void marshall(DataStream* stream) 
                throw (MarshallingException);
    
    virtual ~LocationSentence();
    
private:
    float latDeg;
    float lonDeg;
    float altFtmsl;
    float altFtagl;
    bool  onRunway;
    float altInd;
    float latSouth;
    float lonWest;
};

#endif	/* LOCATIONSENTENCE_H */

