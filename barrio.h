//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_BARRIO_H
#define EDA_PROYECTO_BARRIO_H

#include <vector>
#include "algorithm"

class barrio {
public:
    barrio(const std::vector<std::pair<double, double>> &poligono);

    const std::vector<std::pair<double, double>> &getPoligono() const;

    const std::pair<double, double> &getCoordenadaMinima() const;

    const std::pair<double, double> &getCoordenadaMaxima() const;

private:
    std::vector<std::pair<double,double>> poligono;

    std::pair<double,double> coordenada_minima;

    std::pair<double,double> coordenada_maxima;
};


#endif //EDA_PROYECTO_BARRIO_H
