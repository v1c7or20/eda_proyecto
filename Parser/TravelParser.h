//
// Created by msi on 8/07/2021.
//

#ifndef EDA_PROYECTO_POINT_PARSER_H
#define EDA_PROYECTO_POINT_PARSER_H

#include "../Classes/Travel.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class TravelParser {
private:
    std::string filename;
    std::vector<Travel *> travels;
public:
    TravelParser(std::string filename);
    std::vector<Travel *> & getTravels();
};


#endif //EDA_PROYECTO_POINT_PARSER_H
