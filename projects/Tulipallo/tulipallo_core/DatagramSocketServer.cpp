/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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

