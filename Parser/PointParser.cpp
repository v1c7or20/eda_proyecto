//
// Created by msi on 8/07/2021.
//

#include "PointParser.h"

PointParser::PointParser(std::string filename) : filename(filename) {
    std::ifstream reader;
    reader.open(this->filename,std::ios::in);
    std::string linea;
    std::getline(reader, linea);
    while ( std::getline(reader, linea)) {

        std::stringstream registro(linea);
        std::string dato;

        Point * newPointStart = new Point;
        Point * newPointEnd = new Point;

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
                    newPointStart->setCoordinate({startX, startY});
                    newPointStart->setStart(true);
                    break;
                case 7: // Dropoff_longitude
                    endX = std::stod(dato);
                    break;
                case 8: // Dropoff_latitude
                    endY = std::stod(dato);
                    newPointEnd->setCoordinate({endX, endY});
                    newPointEnd->setStart(false);
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
        newPointStart->setNext(newPointEnd);
        newPointStart->setTravelInformation(newTravel);
        newPointEnd->setNext(newPointStart);
        newPointEnd->setTravelInformation(newTravel);
        points.push_back(newPointEnd);
        points.push_back(newPointStart);
    }
}
std::vector<Point *> &PointParser::getPoints(){
    return points;
}
