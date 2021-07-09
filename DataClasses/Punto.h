//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_PUNTO_H
#define EDA_PROYECTO_PUNTO_H

#include <iostream>
#include <unordered_map>

class Punto {
public:
    Punto(std::pair<double, double> &coordenada, bool esInicio, long long int punteroViaje);

    const std::pair<double, double> &getCoordenada() const;

    bool isEsInicio() const;

    long long int getPunteroViaje() const;

private:
    std::pair<double,double> coordenada;

    bool es_inicio;

    long long puntero_viaje;

};

#endif //EDA_PROYECTO_PUNTO_H
