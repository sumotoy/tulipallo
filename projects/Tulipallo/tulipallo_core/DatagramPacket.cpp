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

#include "DatagramPacket.h"

DatagramPacket::DatagramPacket() {
    this->packetSize = 0;
}

DatagramPacket::DatagramPacket(int packetSize) {
    this->packetSize = packetSize;
}

InternetAddress DatagramPacket::getSourceAddress() {
    return this->source;
}

void DatagramPacket::setSourceAddress(InternetAddress address) {
    this->source = address;
}

int DatagramPacket::getPacketSize() {
    return this->packetSize;
}

void DatagramPacket::setPacketSize(int packetSize) {
    this->packetSize = packetSize;
}

std::vector<char> DatagramPacket::getData() {
    return this->buffer;
}

void DatagramPacket::setData(std::vector<char>* data) {
    this->buffer.clear();
    this->buffer.insert(this->buffer.begin(), data->begin(), data->end());
}

void DatagramPacket::clear() {
    this->buffer.clear();
}

char DatagramPacket::getByte() {
    unsigned char temp = this->buffer.front();
    this->buffer.erase(this->buffer.begin());
    return temp;
}

void DatagramPacket::setByte(int value) {
    this->buffer.insert(this->buffer.end(), value);
}

float DatagramPacket::getFloat() {
    float output;
    
    *((char*)(&output) + 3) = this->buffer[3];
    *((char*)(&output) + 2) = this->buffer[2];
    *((char*)(&output) + 1) = this->buffer[1];
    *((char*)(&output) + 0) = this->buffer[0];

    this->buffer.erase(this->buffer.begin(), this->buffer.begin() + 4);
    
    return output;
}

float DatagramPacket::setFloat(float value) {
    this->setByte(*((char*)(&value) + 0));
    this->setByte(*((char*)(&value) + 1));
    this->setByte(*((char*)(&value) + 2));
    this->setByte(*((char*)(&value) + 3));
}

float DatagramPacket::getEpsilonFloat() {
    float epsFloat = this->getFloat();
    
    if(this->epsilon.isLessThan(epsFloat))
        return 0;
    else
        return epsFloat;
}

std::string DatagramPacket::getString(int numberOfBytes) {
    std::string value = std::string(this->buffer[0], numberOfBytes);
    this->buffer.erase(this->buffer.begin(),  
                       this->buffer.begin() + numberOfBytes);
    return value;
}

void DatagramPacket::setString(std::string value) {
    this->buffer.insert(this->buffer.end(), value.begin(), value.end());
}

void DatagramPacket::skip() {
    this->skip(1);
}

void DatagramPacket::skip(int numberOfBytes) {
    this->buffer.erase(this->buffer.begin(),  
                       this->buffer.begin() + numberOfBytes);
}

DatagramPacket::~DatagramPacket() {
}

