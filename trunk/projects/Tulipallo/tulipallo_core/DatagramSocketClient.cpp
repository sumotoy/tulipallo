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

#include "DatagramSocketClient.h"

DatagramSocketClient::DatagramSocketClient(std::string address, 
                                           std::string remote, 
                                           unsigned short port) 
            throw (SocketException) : DatagramSocket(address, port) {
    this->remote = InternetAddress(remote, port);
}

DatagramSocketClient::DatagramSocketClient(InternetAddress address, 
                                           InternetAddress remote) 
            throw (SocketException) : DatagramSocket(address) {
    this->remote = remote;
}

InternetAddress DatagramSocketClient::getRemoteAddress() 
            throw (SocketException) {
    return this->remote;
}

void DatagramSocketClient::setRemoteAddress(InternetAddress remote) 
            throw (SocketException) {
    this->remote = remote;
}

#include <iostream>

void DatagramSocketClient::send(DatagramPacket* packet) 
            throw (SocketException) {
    sockaddr_in destination = this->remote.toSocketAddress();
    
    std::vector<char> buffer = packet->getData();
    
    if(::sendto(this->socketDescriptor, &buffer[0], 
                buffer.size(), 0, (sockaddr*)&destination, 
                sizeof(destination)) < 0) {
        throw SocketException("Send failed.");
    }
}

DatagramSocketClient::~DatagramSocketClient()  
            throw (SocketException) {
    //
}

