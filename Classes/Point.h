//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_POINT_H
#define EDA_PROYECTO_POINT_H

#include <vector>
#include "GlobalConstants.h"
#include "Travel.h"


class Point{
private:
    coordinate_t coordinate;
    bool start{};
    Point * next{};
    Travel * travelInformation{};

public:
    Point(coordinate_t coordinate, bool start, address_t travelInformation);

    Point();

    coordinate_t getCoordinate();
    bool isStart() const;
    Travel * getTravelInformation();

    void setCoordinate(const coordinate_t &coordinate);

    void setStart(bool start);

    void setTravelInformation(Travel * travelInformation);

    void setNext(Point *next);

    bool isInsidePolygon(std::vector<coordinate_t> polygon) const;

    bool isInsideRectangle(std::pair<float,float>min, std::pair<float,float>max) const:
};

#endif //EDA_PROYECTO_POINT_H