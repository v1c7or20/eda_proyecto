//
// Created by msi on 6/07/2021.
//

#include "TravelPoint.h"

TravelPoint::TravelPoint() = default;

TravelPoint::TravelPoint(coordinate_t coordinate, bool start){
    this->point = Point<double,2>({coordinate.first,coordinate.second});
    this->startingPoint = start;
}

bool TravelPoint::isInsidePolygon(std::vector<coordinate_t> polygon) const {

    unsigned int i, j=polygon.size()-1 ;
    bool  oddNodes= false      ;

    for (i=0; i<polygon.size(); i++) {
        if ((polygon[i].second< this->point.get(1) && polygon[j].second>=this->point.get(1)
             ||   polygon[j].second< this->point.get(1) && polygon[i].second>=this->point.get(1))
            &&  (polygon[i].first<=this->point.get(0) || polygon[j].first<=this->point.get(0))) {
            oddNodes^=(polygon[i].first+(this->point.get(1)-polygon[i].second)/(polygon[j].second-polygon[i].second)*(polygon[j].first-polygon[i].first)<this->point.get(0)); }
        j=i; }

    return oddNodes;
}

bool TravelPoint::isInsideRectangle(std::pair<float, float> min, std::pair<float, float> max) const {
    return (min.first <= this->point.get(0) and this->point.get(0) <= max.first
    and min.second <= this->point.get(1) and this->point.get(1) <= max.second);
}

const Point<double, 2> &TravelPoint::getPoint() const {
    return point;
}

Neighborhood *TravelPoint::getNeighborhood() const {
    return neighborhood;
}

bool TravelPoint::isStartingPoint() const {
    return startingPoint;
}

TravelPoint *TravelPoint::getNext() const {
    return next;
}

void TravelPoint::setNeighborhood(Neighborhood *neighborhood) {
    TravelPoint::neighborhood = neighborhood;
}

void TravelPoint::setNext(TravelPoint *next) {
    TravelPoint::next = next;
}
