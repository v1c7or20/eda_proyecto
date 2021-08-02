//
// Created by msi on 6/07/2021.
//

#include "Neighborhood.h"
#include <algorithm>

Neighborhood::Neighborhood(std::vector<point_t>& polygon, std::string name) : polygon(polygon), name(name) {
    assert(polygon.size() != 0);
    point_t min = polygon[0];
    point_t max = polygon[0];
    for(std::size_t i = 1; i < polygon.size(); ++i) {
        min.set(0, std::min(min[0], polygon[i][0]));
        min.set(1, std::min(min[1], polygon[i][1]));
        max.set(0, std::max(max[0], polygon[i][0]));
        max.set(1, std::max(max[1], polygon[i][1]));
    }
    this->mbr = rectangle_t(min, max);
}

Neighborhood::Neighborhood(std::vector<point_t>& polygon, std::string name, rectangle_t mbr) : polygon(polygon), name(name), mbr(mbr) {
    
}

std::vector<Point<double, 2>> Neighborhood::getPolygon(){
    return polygon;
}

Rectangle<Point<double, 2>> Neighborhood::getMBR(){
    return this->mbr;
}

std::string Neighborhood::getName(){
    return name;
}