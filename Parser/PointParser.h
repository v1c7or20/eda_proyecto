//
// Created by msi on 8/07/2021.
//

#ifndef EDA_PROYECTO_POINT_PARSER_H
#define EDA_PROYECTO_POINT_PARSER_H

#include "../Classes/TravelPoint.h"
#include "../Classes/Travel.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class PointParser {
private:
    std::string filename;
    std::vector<TravelPoint *> points;
public:
    PointParser(std::string filename);
    std::vector<TravelPoint *> &getPoints();
};


#endif //EDA_PROYECTO_POINT_PARSER_H
