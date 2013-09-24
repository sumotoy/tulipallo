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

#ifndef DATAGRAMPACKET_H
#define	DATAGRAMPACKET_H

#include <string>
#include <vector>
#include "InternetAddress.h"
#include "Epsilon.h"
#include "DataStream.h"

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
class DatagramPacket : public DataStream {
public:
    DatagramPacket();
    DatagramPacket(int packetSize);
    
    virtual InternetAddress   getSourceAddress();
    virtual void              setSourceAddress(InternetAddress address);
    virtual int               getPacketSize();
    virtual void              setPacketSize(int packetSize);
    virtual std::vector<char> getData();
    virtual void              setData(std::vector<char>* data);
    virtual void              clear();
    
    virtual char        getByte();
    virtual void        setByte(int value);
    virtual float       getFloat();
    virtual float       setFloat(float value);
    virtual float       getEpsilonFloat();
    virtual std::string getString(int numberOfBytes);
    virtual void        setString(std::string value);
    virtual void        skip();
    virtual void        skip(int numberOfBytes);
    
    virtual ~DatagramPacket();
    
private:
    std::vector<char> buffer;
    int               packetSize;
    InternetAddress   source;
    Epsilon           epsilon;
};

#endif	/* DATAGRAMPACKET_H */

