//
// Created by msi on 6/07/2021.
//

#include "Point.h"

Point::Point(coordinate_t coordinate, bool start, address_t travelInformation){
    this->coordinate = coordinate;
    this->start = start;
    this->travelInformation = travelInformation;
}

coordinate_t Point::getCoordinate() {
    return this->coordinate;
}

bool Point::isStart() { 
    return this->start;
}

address_t Point::getTravelInformation() {
    return this->travelInformation;
}