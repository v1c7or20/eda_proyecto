//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_BARRIO_H
#define EDA_PROYECTO_BARRIO_H

#include <vector>
#include <string>
#include "algorithm"

class Barrio {
public:
    Barrio(const std::vector<std::pair<double, double>> &poligono, std::string nombre);

    const std::vector<std::pair<double, double>> &getPoligono() const;

    const std::pair<double, double> &getCoordenadaMinima() const;

    const std::pair<double, double> &getCoordenadaMaxima() const;

    const std::string &getNombre() const;

private:
    std::vector<std::pair<double,double>> poligono;

    std::pair<double,double> coordenada_minima;

    std::pair<double,double> coordenada_maxima;

    std::string nombre;
};


#endif //EDA_PROYECTO_BARRIO_H
