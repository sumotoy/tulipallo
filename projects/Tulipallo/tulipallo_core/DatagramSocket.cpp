/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "DatagramSocket.h"

DatagramSocket::DatagramSocket(std::string address, unsigned short port) 
        throw (SocketException) {
    this->address = InternetAddress(address, port);
}

DatagramSocket::DatagramSocket(InternetAddress address) 
        throw (SocketException) {
    this->address = address;
}
    
InternetAddress DatagramSocket::getAddress() 
        throw (SocketException) {
    return this->address;
}

void DatagramSocket::setAddress(InternetAddress address) 
        throw (SocketException) {
    this->address = address;
}

int DatagramSocket::getSocketDescriptor() {
    return this->socketDescriptor;
}

void DatagramSocket::close() 
        throw (SocketException) {
    sockaddr_in nullAddress;
    
    nullAddress.sin_family = AF_UNSPEC;

    // Try to disconnect
    if(::connect(this->socketDescriptor, (sockaddr*)&nullAddress, 
                  sizeof(nullAddress)) < 0) {
        if (errno != EAFNOSUPPORT) {
                throw SocketException("Close failed.");
        }
    }
}

void DatagramSocket::bind() 
        throw (SocketException) {
    if((this->socketDescriptor = ::socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) 
            < 0) {
        throw SocketException("Socket creation failed.");
    }
    
    sockaddr_in sockAddress = this->address.toSocketAddress();
    
    if(::bind(this->socketDescriptor, (sockaddr*)&sockAddress, 
            sizeof(sockaddr_in)) < 0) {
        throw SocketException("Binding of address and port failed.");
    }
}

DatagramSocket::~DatagramSocket() 
        throw (SocketException) {
    this->close();
}