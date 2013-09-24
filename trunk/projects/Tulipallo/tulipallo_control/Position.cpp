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

