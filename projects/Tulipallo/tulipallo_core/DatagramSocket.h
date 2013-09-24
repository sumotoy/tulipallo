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

#ifndef DATAGRAMSOCKET_H
#define	DATAGRAMSOCKET_H

#include <errno.h>
#include <cerrno>
#include <string>
#include <sys/socket.h> 
#include "SocketException.h"
#include "InternetAddress.h"

const int SOCK_SUCCESS = 0;

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
class DatagramSocket {
public:
    DatagramSocket(std::string address, unsigned short port) 
            throw (SocketException);
    DatagramSocket(InternetAddress address) 
            throw (SocketException);
    
    virtual InternetAddress getAddress() 
            throw (SocketException);
    virtual void            setAddress(InternetAddress address) 
            throw (SocketException);
    virtual int             getSocketDescriptor();
    virtual void            bind()
            throw (SocketException);
    virtual void            close() 
            throw (SocketException);
    
    virtual ~DatagramSocket() 
            throw (SocketException);
    
protected:
    InternetAddress address;
    int             socketDescriptor;
};

#endif	/* DATAGRAMSOCKET_H */

