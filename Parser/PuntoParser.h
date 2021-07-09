//
// Created by msi on 8/07/2021.
//

#ifndef EDA_PROYECTO_PUNTO_PARSER_H
#define EDA_PROYECTO_PUNTO_PARSER_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "../DataClasses/Punto.h"

class PuntoParser {
public:
    PuntoParser(const std::string &file);

    const std::vector<Punto> &getPuntos() const;

private:
    std::string file;
    std::vector<Punto> puntos;


};


#endif //EDA_PROYECTO_PUNTO_PARSER_H
