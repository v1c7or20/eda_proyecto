//
// Created by msi on 6/07/2021.
//

#include "NeighborhoodParser.h"

#define DEBUG_BASIC false


using json = nlohmann::json;

NeighborhoodParser::NeighborhoodParser(std::string filename) : filename(filename) {
    std::ifstream reader(filename);
    json data;
    reader>>data;
    for (json::iterator it = data.begin(); it != data.end(); ++it) {

        if(DEBUG_BASIC){
            std::cout<<"\n";
        }

        auto coordinates = it->at("geometry").at("coordinates");
        std::vector<coordinate_t> coordinates_vector;
        std::string name = it->at("neighborhood");
        for (json::iterator coord = coordinates.begin(); coord != coordinates.end() ; coord++) {
            coordinate_t coordinate = {coord->at(0), coord->at(1)};
            coordinates_vector.push_back(coordinate);
            if (DEBUG_BASIC){
                std::cout<<coord->at(1)<<" ";
            }
        }
        Neighborhood newNeighborhood(coordinates_vector, name);
        neighborhoods.push_back(newNeighborhood);
    }
}


std::vector<Neighborhood> &NeighborhoodParser::getNeighborhoods(){
    return neighborhoods;
}
