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

#include "DatagramSocketServer.h"

DatagramSocketServer::DatagramSocketServer(std::string address, 
                                           unsigned short port) 
        throw (SocketException) : 
                DatagramSocket(address, port) {
    //
}

DatagramSocketServer::DatagramSocketServer(InternetAddress address) 
        throw (SocketException) : 
                DatagramSocket(address) {
    //
}

void DatagramSocketServer::receive(DatagramPacket* packet) 
        throw (SocketException) {
    sockaddr_in client;
    socklen_t   length = sizeof(client);
    
    std::vector<char> buffer = 
                std::vector<char>(packet->getPacketSize());
    
    int bytesRead = ::recvfrom(this->socketDescriptor, &buffer[0], 
                               packet->getPacketSize(), 0, (sockaddr*)&client, 
                               (socklen_t*)&length);
    
    if(bytesRead < 0) {
        throw SocketException("Receive failed.");
    }
    
    packet->setData(&buffer);
    packet->setSourceAddress(InternetAddress(client));
}

DatagramSocketServer::~DatagramSocketServer()
        throw (SocketException) {
    //
}

