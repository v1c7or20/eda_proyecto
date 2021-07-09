//
// Created by msi on 6/07/2021.
//

#include "Punto.h"

Punto::Punto(std::pair<double, double> &coordenada, bool esInicio, long long int punteroViaje) : coordenada(
        coordenada), es_inicio(esInicio), puntero_viaje(punteroViaje) {}

const std::pair<double, double> &Punto::getCoordenada() const {
    return coordenada;
}

bool Punto::isEsInicio() const {
    return es_inicio;
}

long long int Punto::getPunteroViaje() const {
    return puntero_viaje;
}
