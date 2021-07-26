//
// Created by msi on 6/07/2021.
//

#include "TravelPoint.h"

TravelPoint::TravelPoint() = default;

TravelPoint::TravelPoint(coordinate_t coordinate, bool start, address_t travelInformation){
    this->coordinate = coordinate;
    this->start = start;
    this->travelInformation = nullptr;
}

coordinate_t TravelPoint::getCoordinate() {
    return this->coordinate;
}

bool TravelPoint::isStart() const {
    return this->start;
}

Travel * TravelPoint::getTravelInformation() {
    return this->travelInformation;
}

void TravelPoint::setCoordinate(const coordinate_t &_coordinate) {
    this->coordinate = _coordinate;
}

void TravelPoint::setStart(bool start) {
    this->start = start;
}

void TravelPoint::setTravelInformation(Travel * _travelInformation) {
    this->travelInformation = _travelInformation;
}

bool TravelPoint::isInsidePolygon(std::vector<coordinate_t> polygon) const {

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

bool TravelPoint::isInsideRectangle(std::pair<float, float> min, std::pair<float, float> max) const {
    return (min.first <= this->coordinate.first and this->coordinate.first <= max.first
    and min.second <= this->coordinate.second and this->coordinate.second <= max.second);
}
