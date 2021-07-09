//
// Created by msi on 6/07/2021.
//

#include "Barrio.h"

Barrio::Barrio(const std::vector<std::pair<double, double>> &poligono, std::string nombre) : poligono(poligono), nombre(nombre) {
    coordenada_maxima = {-1e8,-1e8};
    coordenada_minima = {1e8,1e8};
    for ( auto & coordenada : poligono) {
        coordenada_minima.first = std::min(coordenada.first, coordenada_minima.first);
        coordenada_minima.second = std::min(coordenada.second, coordenada_minima.second);
        coordenada_maxima.first = std::max(coordenada.first, coordenada_maxima.first);
        coordenada_maxima.second = std::max(coordenada.second, coordenada_maxima.second);
    }
}

const std::vector<std::pair<double, double>> &Barrio::getPoligono() const {
    return poligono;
}

const std::pair<double, double> &Barrio::getCoordenadaMinima() const {
    return coordenada_minima;
}

const std::pair<double, double> &Barrio::getCoordenadaMaxima() const {
    return coordenada_maxima;
}

const std::string &Barrio::getNombre() const {
    return nombre;
}
