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

#ifndef DATAGRAMSOCKETSERVER_H
#define	DATAGRAMSOCKETSERVER_H

#include "DatagramSocket.h"
#include "DatagramPacket.h"
#include "InternetAddress.h"
#include "IllegalArgumentException.h"

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
class DatagramSocketServer : public DatagramSocket {
public:
    DatagramSocketServer(std::string address, unsigned short port)
            throw (SocketException);
    DatagramSocketServer(InternetAddress address)
            throw (SocketException);
    
    virtual void receive(DatagramPacket* packet) 
            throw (SocketException);
    
    virtual ~DatagramSocketServer()
            throw (SocketException);
    
private:

};

#endif	/* DATAGRAMSOCKETSERVER_H */

