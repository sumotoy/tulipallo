/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
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

