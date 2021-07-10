//
// Created by msi on 8/07/2021.
//

#ifndef EDA_PROYECTO_POINT_PARSER_H
#define EDA_PROYECTO_POINT_PARSER_H

#include "../Classes/Point.h"

#include <string>
#include <vector>
#include <fstream>

class PointParser {
private:
    std::string filename;
    std::vector<Point> points;
public:
    PointParser(std::string filename);
    std::vector<Point> &getPoints();
};


#endif //EDA_PROYECTO_POINT_PARSER_H
