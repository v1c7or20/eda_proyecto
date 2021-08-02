//
// Created by msi on 8/07/2021.
//

#ifndef EDA_PROYECTO_POINT_PARSER_H
#define EDA_PROYECTO_POINT_PARSER_H

#include "../Basic/Travel.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class TravelParser {
private:
    using point_t = Point<double, 2>;
public:
    TravelParser(std::string filename);
    std::vector<Travel *> & getTravels();
private:
    std::string filename;
    std::vector<Travel *> travels;
};


#endif //EDA_PROYECTO_POINT_PARSER_H
