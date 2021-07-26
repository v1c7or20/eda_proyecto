//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_NEIGHBORHOOD_H
#define EDA_PROYECTO_NEIGHBORHOOD_H

#include "GlobalConstants.h"
#include <vector>

class Neighborhood{
private:
    std::vector<coordinate_t> polygon;
    coordinate_t minimumCoordinate;
    coordinate_t maximumCoordinate;
    std::string name;
public:
    Neighborhood(std::vector<coordinate_t>& polygon, std::string name);
    std::vector<coordinate_t> getPolygon();
    coordinate_t getMinimumCoordinate();
    coordinate_t getMaximumCoordinate();
    std::string getName();
};


#endif //EDA_PROYECTO_NEIGHBORHOOD_H