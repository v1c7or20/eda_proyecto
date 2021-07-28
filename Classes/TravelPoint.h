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
    Point<double,2> point;
    Neighborhood *neighborhood;
    bool startingPoint;
public:
    TravelPoint(coordinate_t coordinate, bool start);

    TravelPoint(const TravelPoint &obj);

    TravelPoint();

    bool isInsidePolygon(std::vector<coordinate_t> polygon) const;

    bool isInsideRectangle(std::pair<float,float>min, std::pair<float,float>max) const;

    const Point<double, 2> &getPoint() const;

    Neighborhood *getNeighborhood() const;

    void setNext(TravelPoint *next);

    bool isStartingPoint() const;

    void setNeighborhood(Neighborhood *neighborhood);

};

#endif //EDA_PROYECTO_TRAVELPOINT_H
