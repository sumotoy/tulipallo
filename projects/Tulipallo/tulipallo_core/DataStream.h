/* 
 * File:   DataStream.h
 * Author: Robert
 *
 * Created on June 4, 2013, 9:20 PM
 */

#ifndef DATASTREAM_H
#define	DATASTREAM_H

#include <string>

class DataStream {
public:
    DataStream();
    
    virtual char        getByte()                    = 0;
    virtual void        setByte(int value)           = 0;
    virtual float       getFloat()                   = 0;
    virtual float       setFloat(float value)        = 0;
    virtual float       getEpsilonFloat()            = 0;
    virtual std::string getString(int numberOfBytes) = 0;
    virtual void        skip()                       = 0;
    virtual void        skip(int numberOfBytes)      = 0;
    
    virtual ~DataStream();
private:

};

#endif	/* DATASTREAM_H */

