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

#ifndef INTERNETADDRESS_H
#define	INTERNETADDRESS_H

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "INetworkAddress.h"
#include "SocketException.h"

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
class InternetAddress : public INetworkAddress {
public:
    InternetAddress(std::string address, unsigned short port);
    InternetAddress(sockaddr_in address);
    InternetAddress();
    
    virtual std::string    getAddress();
    virtual void           setAddress(std::string address);
    virtual unsigned short getPort();
    virtual void           setPort(unsigned short port);
    virtual sockaddr_in    toSocketAddress();
    
    sockaddr_in createSocketAddress(const std::string &address, 
                                    unsigned short port) {
        sockaddr_in socketAddress;
        socketAddress.sin_family = AF_INET;

        hostent *host;
        if((host = gethostbyname(address.c_str())) == NULL) {
                throw SocketException("Failed to resolve name.");
        }
        
        socketAddress.sin_addr.s_addr = *((unsigned long*)host->h_addr_list[0]);
        socketAddress.sin_port = htons(port);
        
        return socketAddress;
    }
    
    virtual ~InternetAddress();

private:
    std::string    address;
    unsigned short port;
};

#endif	/* INETADDRESS_H */

