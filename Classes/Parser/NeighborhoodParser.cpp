//
// Created by msi on 6/07/2021.
//

#include "NeighborhoodParser.h"

#define DEBUG_BASIC false


using json = nlohmann::json;

NeighborhoodParser::NeighborhoodParser(std::string filename) : filename(filename) {
    std::ifstream reader(filename);
    if(!reader.is_open()){
        throw std::invalid_argument( "File not found" );
    }
    json data;
    reader >> data;
    for (json::iterator it = data.begin(); it != data.end(); ++it) {

        if(DEBUG_BASIC){
            std::cout<<"\n";
        }

        auto coordinates = it->at("geometry").at("coordinates");
        std::vector<point_t> coordinates_vector(coordinates.size());
        std::string name = it->at("neighborhood");
        std:size_t i = 0;
        for (json::iterator coord = coordinates.begin(); coord != coordinates.end() ; coord++) {
            coordinates_vector[i] = point_t({coord->at(0), coord->at(1)});;
            if (DEBUG_BASIC){
                std::cout<<coord->at(1)<<" ";
            }
            ++i;
        }
        Neighborhood* newNeighborhood = new Neighborhood(coordinates_vector, name);
        neighborhoods.push_back(newNeighborhood);
    }
}

std::vector<Neighborhood*> &NeighborhoodParser::getNeighborhoods(){
    return neighborhoods;
}
