//
// Created by msi on 6/07/2021.
//

#ifndef EDA_PROYECTO_TRAVEL_H
#define EDA_PROYECTO_TRAVEL_H


#include <string>

class Travel{
public:
    const std::string &getPickupDate() const;

    const std::string &getDropoffDate() const;

    int getPassengerCount() const;

    double getTripDistance() const;

    double getFareAmount() const;

    void setPickupDate(const std::string &pickupDate);

    void setDropoffDate(const std::string &dropoffDate);

    void setPassengerCount(int passengerCount);

    void setTripDistance(double tripDistance);

    void setFareAmount(double fareAmount);

private:
    std::string pickupDate;
    std::string dropoffDate;
    int passengerCount;
    double tripDistance;
    double fareAmount;

};


#endif //EDA_PROYECTO_TRAVEL_H
