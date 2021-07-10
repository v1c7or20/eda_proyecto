//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_POINT_H
#define EDA_PROYECTO_POINT_H

#include "GlobalConstants.h"

class Point{
private:
    coordinate_t coordinate;
    bool start;
    address_t travelInformation;

public:
    Point(coordinate_t coordinate, bool start, address_t travelInformation);
    
    coordinate_t getCoordinate();
    bool isStart();
    address_t getTravelInformation();
};

#endif //EDA_PROYECTO_POINT_H