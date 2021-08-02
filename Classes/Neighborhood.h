//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_NEIGHBORHOOD_H
#define EDA_PROYECTO_NEIGHBORHOOD_H

#include "GlobalConstants.h"
#include "Spatial/Point.h"
#include "Spatial/Rectangle.h"
#include <vector>

class Neighborhood{
private:
    using point_t = Point<double, 2>;
    using rectangle_t = Rectangle<point_t>;
public:
    Neighborhood(std::vector<point_t>& polygon, std::string name);
    Neighborhood(std::vector<point_t>& polygon, std::string name, rectangle_t mbr);
    std::vector<point_t> getPolygon();
    rectangle_t getMBR();
    std::string getName();
private:
    std::vector<point_t> polygon;
    rectangle_t mbr;
    std::string name;
};

#endif //EDA_PROYECTO_NEIGHBORHOOD_H