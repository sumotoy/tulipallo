/* 
 * File:   Properties.h
 * Author: Robert
 *
 * Created on June 24, 2013, 10:28 PM
 */

#ifndef PROPERTIES_H
#define	PROPERTIES_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Thread.h"
#include "PropertiesException.h"
#include "KeyNotFoundException.h"

class Properties {
public:
    Properties();
    Properties(const Properties& properties);
    
    virtual void load(std::string path) throw (PropertiesException);
    
    virtual std::string    getProperty(std::string key) throw (KeyNotFoundException);
    virtual int            getInteger(std::string key) throw (KeyNotFoundException);
    virtual unsigned int   getUnsignedInteger(std::string key) throw (KeyNotFoundException);
    virtual float          getFloat(std::string key) throw (KeyNotFoundException);
    virtual double         getDouble(std::string key) throw (KeyNotFoundException);
    virtual short          getShort(std::string key) throw (KeyNotFoundException);
    virtual unsigned short getUnsignedShort(std::string key) throw (KeyNotFoundException);
    virtual long           getLong(std::string key) throw (KeyNotFoundException);
    virtual unsigned long  getUnsignedLong(std::string key) throw (KeyNotFoundException);
    virtual bool           getBoolean(std::string key) throw (KeyNotFoundException);
    virtual char           getChar(std::string key) throw (KeyNotFoundException);
    
    virtual std::map<std::string, std::string>* getProperties() throw (KeyNotFoundException);
    
    virtual ~Properties();

protected:
    virtual void parseLine(std::string  line);
    std::map<std::string, std::string>* properties;
    
private:
    std::string      path;
    pthread_mutex_t* mutex;
};

#endif	/* PROPERTIES_H */

