//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_TRAVELPOINT_H
#define EDA_PROYECTO_TRAVELPOINT_H

#include <vector>
#include "GlobalConstants.h"
#include "Spatial/Point.h"
#include "Neighborhood.h"

class TravelPoint{
private:
    using point_t = Point<double, 2>; 
public:
    TravelPoint();
    TravelPoint(point_t coordinate, bool start);
    TravelPoint(const TravelPoint &obj);
    bool isInsidePolygon(std::vector<point_t> polygon) const;
    bool isInsideRectangle(point_t min, point_t max) const;
    const Point<double, 2> &getPoint() const;
    Neighborhood *getNeighborhood() const;
    void setNext(TravelPoint *next);
    bool isStartingPoint() const;
    void setNeighborhood(Neighborhood *neighborhood);
    TravelPoint& operator=(const TravelPoint& travelPoint);
private:
    point_t point;
    Neighborhood *neighborhood;
    bool startingPoint;
};

#endif //EDA_PROYECTO_TRAVELPOINT_H
