/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "InternetAddress.h"

InternetAddress::InternetAddress(std::string address, unsigned short port) {
    this->address = address;
    this->port    = port;
}

InternetAddress::InternetAddress(sockaddr_in address) {
    this->address = inet_ntoa(address.sin_addr);
    this->port    = ntohs(address.sin_port);
}

InternetAddress::InternetAddress() {
    //
}

std::string InternetAddress::getAddress() {
    return this->address;
}

void InternetAddress::setAddress(std::string address) {
    this->address = address;
}

unsigned short InternetAddress::getPort() {
    return this->port;
}

void InternetAddress::setPort(unsigned short port) {
    this->port = port;
}

sockaddr_in InternetAddress::toSocketAddress() {
    return  createSocketAddress(this->address, this->port);
}

InternetAddress::~InternetAddress() {
}

