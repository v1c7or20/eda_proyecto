//
// Created by msi on 8/07/2021.
//

#include "TravelParser.h"
#include <map>
#include <functional>
#include <utility>
TravelParser::TravelParser(std::string filename) : filename(filename) {
    std::ifstream reader;
    reader.open(this->filename,std::ios::in);
    if(!reader.is_open()){
        throw std::invalid_argument( "File not found" );
    }

    std::string linea;
    std::getline(reader, linea);
    while (std::getline(reader, linea)) {
        std::stringstream registro(linea);
        std::string element;
        std::vector<std::string> data(9);
        std::size_t i = 0;
        for (int columna = 0; std::getline(registro, element, ','); ++columna) {
            if(columna > 11)
                break;
            if(1 <= columna && columna <= 2 || 5 <= columna){
                data[i] = element;
                ++i;
            }
        }
        double startX = std::stod(data[2]);
        double startY = std::stod(data[3]);
        double endX = std::stod(data[4]);
        double endY = std::stod(data[5]);
        Travel * newTravel = new Travel(data[0], data[1], std::stoi(data[6]), 
                                std::stod(data[7]), std::stod(data[8]), 
                                TravelPoint(point_t({startX, startY}), true), 
                                TravelPoint(point_t({endX, endY}), false));
        travels.push_back(newTravel);
    }
    if (travels.size() == 0) {
      throw std::invalid_argument( "File empty" );
    }
}
std::vector<Travel *> & TravelParser::getTravels(){
    return travels;
}
