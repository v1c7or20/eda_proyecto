//
// Created by msi on 8/07/2021.
//

#include "punto_parser.h"


const std::vector<punto> &punto_parser::getPuntos() const {
    return puntos;
}

punto_parser::punto_parser(const std::string &file) : file(file) {
    std::ifstream reader(file);
    std::string vendor_id, date_pick, drop, flag, rate;
    double longitud_inicio, latitud_inicio, longitud_destino, latitud_destino;
    std::string count, distance, fare, extra,MTA,TIP;
    while (getline(reader, vendor_id, ',')) {

        getline(reader, date_pick, ',') ;
        getline(reader, drop, ',') ;
        getline(reader, flag, ',') ;
        getline(reader, rate, ',') ;
        /*getline(reader, longitud_inicio, ',') ;
        getline(reader, latitud_inicio, ',') ;
        getline(reader, longitud_destino, ',') ;
        getline(reader, latitud_destino, ',') ;
        getline(reader, count, ',') ;
        getline(reader, distance, ',') ;

        getline(reader, genero);*/
    }
}
