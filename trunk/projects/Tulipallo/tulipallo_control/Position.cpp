/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "Position.h"

Position::Position() {
    //
}

Position::Position(double latitude, double longitude, double altitude) {
    this->latitude  = latitude;
    this->longitude = longitude;
    this->altitude  = altitude;
}

Position::Position(const Position& orig) {
    this->copy(orig);
}

void Position::copy(const Position& orig) {
    this->latitude  = orig.latitude;
    this->longitude = orig.longitude;
    this->altitude  = orig.altitude;
}

double Position::getLatitude() {
    return this->latitude;
}

void Position::setLatitude(double latitude) {
    this->latitude = latitude;
}

double Position::getLongitude() {
    return this->longitude;
}

void Position::setLongitude(double longitude) {
    this->longitude = longitude;
}

double Position::getAltitude() {
    return this->altitude;
}

void Position::setAltitude(double altitude) {
    this->altitude = altitude;
}

Position::~Position() {
}

