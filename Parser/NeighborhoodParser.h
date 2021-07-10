//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_NEIGHBORHOOD_PARSER_H
#define EDA_PROYECTO_NEIGHBORHOOD_PARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include "../Classes/Neighborhood.h"
#include <nlohmann/json.hpp>

class NeighborhoodParser {
private:
    std::string filename;
    std::vector<Neighborhood> neighborhoods;
public:
    NeighborhoodParser(std::string filename);
    std::vector<Neighborhood> &getNeighborhoods();
};


#endif //EDA_PROYECTO_NEIGHBORHOOD_PARSER_H
