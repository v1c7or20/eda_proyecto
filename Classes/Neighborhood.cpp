//
// Created by msi on 6/07/2021.
//

#include "Neighborhood.h"
#include <algorithm>

Neighborhood::Neighborhood(std::vector<coordinate_t>& polygon, std::string name) : polygon(polygon), name(name) {
    minimumCoordinate = {1e8, 1e8};
    maximumCoordinate = {-1e8, -1e8};
    for(auto& coordinate : polygon) {
        minimumCoordinate.first = std::min(coordinate.first, minimumCoordinate.first);
        minimumCoordinate.second = std::min(coordinate.second, minimumCoordinate.second);
        maximumCoordinate.first = std::max(coordinate.first, maximumCoordinate.first);
        maximumCoordinate.second = std::max(coordinate.second, maximumCoordinate.second);
    }
}

std::vector<coordinate_t> Neighborhood::getPolygon(){
    return polygon;
}

coordinate_t Neighborhood::getMinimumCoordinate(){
    return minimumCoordinate;
}

coordinate_t Neighborhood::getMaximumCoordinate(){
    return maximumCoordinate;
}

std::string Neighborhood::getName(){
    return name;
}
