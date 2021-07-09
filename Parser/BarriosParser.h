//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_BARRIOS_PARSER_H
#define EDA_PROYECTO_BARRIOS_PARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "../DataClasses/Barrio.h"



class BarriosParser {
public:
    BarriosParser(const std::string &file);

    const std::vector<Barrio> &getBarrios() const;

private:
    std::string file;
    std::vector<Barrio> barrios;
};


#endif //EDA_PROYECTO_BARRIOS_PARSER_H
