//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_NEIGHBORHOOD_PARSER_H
#define EDA_PROYECTO_NEIGHBORHOOD_PARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include "../Basic/Neighborhood.h"
#include "../Spatial/Rectangle.h"
#include <nlohmann/json.hpp>

class NeighborhoodParser {
private:
    using point_t = Point<double, 2>;
    using rectangle_t = Rectangle<point_t>;
public:
    NeighborhoodParser(std::string filename);
    std::vector<Neighborhood*> &getNeighborhoods();
private:
    std::string filename;
    std::vector<Neighborhood*> neighborhoods;
};


#endif //EDA_PROYECTO_NEIGHBORHOOD_PARSER_H
