/* 
 * File:   Psition.h
 * Author: Robert
 *
 * Created on June 8, 2013, 5:23 PM
 */

#ifndef POSITION_H
#define	POSITION_H

class Position {
public:
    Position();
    Position(double latitude, double longitude, double altitude);
    Position(const Position& orig);
    
    virtual void   copy(const Position& orig);
    virtual double getLatitude();
    virtual void   setLatitude(double latitude);
    virtual double getLongitude();
    virtual void   setLongitude(double longitude);
    virtual double getAltitude();
    virtual void   setAltitude(double altitude);
    
    virtual ~Position();
    
private:
    double latitude;
    double longitude;
    double altitude;
};

#endif	/* POSITION_H */

