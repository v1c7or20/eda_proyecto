//
// Created by msi on 6/07/2021.
//

#include "barrios_parser.h"
#define DEBUG_BASIC false


using json = nlohmann::json;

barrios_parser::barrios_parser(const std::string &file) : file(file) {
    std::ifstream reader(file);
    json data;
    reader>>data;
    for (json::iterator it = data.begin(); it != data.end(); ++it) {

        if(DEBUG_BASIC){
            std::cout<<"\n";
        }

        auto coordinates = it->at("geometry").at("coordinates");
        std::vector<std::pair<double,double>> coordinates_vector;
        std::string name = it->at("neighborhood");
        for (json::iterator coord = coordinates.begin(); coord != coordinates.end() ; coord++) {
            std::pair<double,double> coordinate = {coord->at(0), coord->at(1)};
            coordinates_vector.push_back(coordinate);
            if (DEBUG_BASIC){
                std::cout<<coord->at(1)<<" ";
            }
        }
        barrio nuevo_barrio(coordinates_vector, name);
        barrios.push_back(nuevo_barrio);
    }

}


const std::vector<barrio> &barrios_parser::getBarrios() const {
    return barrios;
}
