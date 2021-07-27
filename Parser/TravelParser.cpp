//
// Created by msi on 8/07/2021.
//

#include "TravelParser.h"

TravelParser::TravelParser(std::string filename) : filename(filename) {
    std::ifstream reader;
    reader.open(this->filename,std::ios::in);
    std::string linea;
    std::getline(reader, linea);
    while ( std::getline(reader, linea)) {

        std::stringstream registro(linea);
        std::string dato;

        double startX, startY, endX, endY;

        Travel * newTravel = new Travel;

        for (int columna = 0; std::getline(registro, dato, ','); ++columna) {
            switch (columna) {
                case 1: // lpep_pickup_datetime
                    newTravel->setPickupDate(dato);
                    break;
                case 2: // Lpep_dropoff_datetime
                    newTravel->setDropoffDate(dato);
                    break;
                case 4: // RateCodeID
                    break;
                case 5: // Pickup_longitude
                    startX = std::stod(dato);
                    break;
                case 6: // Pickup_latitude
                    startY = std::stod(dato);
                    newTravel->setStartingPint(TravelPoint({startX,startX},true) );
                    break;
                case 7: // Dropoff_longitude
                    endX = std::stod(dato);
                    break;
                case 8: // Dropoff_latitude
                    endY = std::stod(dato);
                    newTravel->setArrivalPoint(TravelPoint({endX, endY}, false));
                    break;
                case 9: // Passenger Count
                    newTravel->setPassengerCount(std::stoi(dato));
                    break;
                case 10: // Trip Distance
                    newTravel->setTripDistance(std::stod(dato));
                    break;
                case 11: // Fare Amount
                    newTravel->setFareAmount(std::stod(dato));
                    break;
                default:
                    break;
            }
        }
        travels.push_back(newTravel);
    }
    if ( travels.size() == 0 ) {
      throw std::invalid_argument( "File empty or not found" );
    }
}
std::vector<Travel *> & TravelParser::getTravels(){
    return travels;
}
