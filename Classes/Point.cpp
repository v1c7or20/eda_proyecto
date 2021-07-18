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

bool Point::isStart() const {
    return this->start;
}

Travel * Point::getTravelInformation() {
    return this->travelInformation;
}

void Point::setCoordinate(const coordinate_t &_coordinate) {
    Point::coordinate = _coordinate;
}

void Point::setStart(bool start) {
    Point::start = start;
}

void Point::setTravelInformation(Travel * _travelInformation) {
    Point::travelInformation = _travelInformation;
}

bool Point::isInsidePolygon(std::vector<coordinate_t> polygon) const {

    unsigned int i, j=polygon.size()-1 ;
    bool  oddNodes= false      ;

    for (i=0; i<polygon.size(); i++) {
        if ((polygon[i].second< this->coordinate.second && polygon[j].second>=this->coordinate.second
             ||   polygon[j].second< this->coordinate.second && polygon[i].second>=this->coordinate.second)
            &&  (polygon[i].first<=this->coordinate.first || polygon[j].first<=this->coordinate.first)) {
            oddNodes^=(polygon[i].first+(this->coordinate.second-polygon[i].second)/(polygon[j].second-polygon[i].second)*(polygon[j].first-polygon[i].first)<this->coordinate.first); }
        j=i; }

    return oddNodes;
}

bool Point::isInsideRectangle(std::pair<float, float> min, std::pair<float, float> max) const {
    return (min.first <= this->coordinate.first and this->coordinate.first <= max.first
    and min.second <= this->coordinate.second and this->coordinate.second <= max.second);
}

Point::Point() = default;

void Point::setNext(Point *_next) {
    Point::next = _next;
}
