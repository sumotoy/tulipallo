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

