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

#ifndef PROPERTIES_H
#define	PROPERTIES_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Thread.h"
#include "PropertiesException.h"
#include "KeyNotFoundException.h"

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

