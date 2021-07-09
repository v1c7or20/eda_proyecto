//
// Created by msi on 6/07/2021.
//

#include "punto.h"

punto::punto(std::pair<double, double> &coordenada, bool esInicio, long long int punteroViaje) : coordenada(
        coordenada), es_inicio(esInicio), puntero_viaje(punteroViaje) {}

const std::pair<double, double> &punto::getCoordenada() const {
    return coordenada;
}

bool punto::isEsInicio() const {
    return es_inicio;
}

long long int punto::getPunteroViaje() const {
    return puntero_viaje;
}
