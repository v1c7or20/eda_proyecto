//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_TRAVELPOINT_H
#define EDA_PROYECTO_TRAVELPOINT_H

#include <vector>
#include "GlobalConstants.h"
#include "Travel.h"


class TravelPoint{
private:
    coordinate_t coordinate;
    bool start{};
    TravelPoint * next{};
    Travel * travelInformation{};

public:
    TravelPoint(coordinate_t coordinate, bool start, address_t travelInformation);

    TravelPoint();

    coordinate_t getCoordinate();
    bool isStart() const;
    Travel * getTravelInformation();

    void setCoordinate(const coordinate_t &coordinate);

    void setStart(bool start);

    void setTravelInformation(Travel * travelInformation);

    void setNext(TravelPoint *next);

    bool isInsidePolygon(std::vector<coordinate_t> polygon) const;

    //bool isInsideRectangle(std::pair<float,float>min, std::pair<float,float>max) const:
};

#endif //EDA_PROYECTO_TRAVELPOINT_H
