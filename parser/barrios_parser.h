//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_BARRIOS_PARSER_H
#define EDA_PROYECTO_BARRIOS_PARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "../data_classes/barrio.h"



class barrios_parser {
public:
    barrios_parser(const std::string &file);

    const std::vector<barrio> &getBarrios() const;

private:
    std::string file;
    std::vector<barrio> barrios;
};


#endif //EDA_PROYECTO_BARRIOS_PARSER_H
