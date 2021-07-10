//
// Created by msi on 6/07/2021.
//

#include "Point.h"

Point::Point(coordinate_t coordinate, bool start, address_t travelInformation){
    this->coordinate = coordinate;
    this->start = start;
    this->travelInformation = nullptr;
}

coordinate_t Point::getCoordinate() {
    return this->coordinate;
}

bool Point::isStart() { 
    return this->start;
}

Travel * Point::getTravelInformation() {
    return this->travelInformation;
}

void Point::setCoordinate(const coordinate_t &coordinate) {
    Point::coordinate = coordinate;
}

void Point::setStart(bool start) {
    Point::start = start;
}

void Point::setTravelInformation(Travel * travelInformation) {
    Point::travelInformation = travelInformation;
}

Point::Point() {}

void Point::setNext(Point *next) {
    Point::next = next;
}
