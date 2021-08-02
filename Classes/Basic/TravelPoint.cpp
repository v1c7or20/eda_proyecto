//
// Created by msi on 6/07/2021.
//

#include "TravelPoint.h"

TravelPoint::TravelPoint(){
    this->neighborhood = nullptr;
}

TravelPoint::TravelPoint(point_t coordinate, bool start){
    this->point = coordinate;
    this->startingPoint = start;
}

bool TravelPoint::isInsidePolygon(std::vector<point_t> polygon) const {
    unsigned int i, j=polygon.size()-1 ;
    bool oddNodes = false;

    for (i=0; i<polygon.size(); i++) {
        if ((polygon[i][1]< this->point.get(1) && polygon[j][1]>=this->point.get(1)
             ||   polygon[j][1]< this->point.get(1) && polygon[i][1]>=this->point.get(1))
            &&  (polygon[i][0]<=this->point.get(0) || polygon[j][0]<=this->point.get(0))) {
            oddNodes^=(polygon[i][0]+(this->point.get(1)-polygon[i][1])/(polygon[j][1]-polygon[i][1])*(polygon[j][0]-polygon[i][0])<this->point.get(0)); 
            }
        j=i; 
    }

    return oddNodes;
}

bool TravelPoint::isInsideRectangle(point_t min, point_t max) const {
    return (min[0] <= this->point.get(0) and this->point.get(0) <= max[0]
    and min[1] <= this->point.get(1) and this->point.get(1) <= max[1]);
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

void TravelPoint::setNeighborhood(Neighborhood *neighborhood) {
    TravelPoint::neighborhood = neighborhood;
}

TravelPoint::TravelPoint(const TravelPoint &obj) {
    point = obj.point;
    neighborhood = obj.neighborhood;
    startingPoint = obj.startingPoint;
}

TravelPoint& TravelPoint::operator=(const TravelPoint &obj) {
    point = obj.point;
    neighborhood = obj.neighborhood;
    startingPoint = obj.startingPoint;
    return *this;
}