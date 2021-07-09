//
// Created by msi on 8/07/2021.
//

#ifndef EDA_PROYECTO_PUNTO_PARSER_H
#define EDA_PROYECTO_PUNTO_PARSER_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "../data_classes/punto.h"

class punto_parser {
public:
    punto_parser(const std::string &file);

    const std::vector<punto> &getPuntos() const;

private:
    std::string file;
    std::vector<punto> puntos;


};


#endif //EDA_PROYECTO_PUNTO_PARSER_H
