#ifndef EDA_PROYECTO_TRAVEL_H
#define EDA_PROYECTO_TRAVEL_H

#include <string>
#include "TravelPoint.h"

class Travel{
public:
    Travel();
    Travel(const std::string& pickupDate, const std::string& dropoffDate, int passengerCount,
            double tripDistance, double fareAmount, 
            const TravelPoint& startingPoint, const TravelPoint& ArrivalPoint);
    Travel(const Travel &obj);
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
    TravelPoint &getStartingPoint();
    TravelPoint &getArrivalPoint();
    void setStartingPint(const TravelPoint &startingPint);
    void setArrivalPoint(const TravelPoint &arrivalPoint);

private:
    std::string pickupDate;
    std::string dropoffDate;
    int passengerCount;
    double tripDistance;
    double fareAmount;
    TravelPoint StartingPoint;
    TravelPoint ArrivalPoint;
};


#endif //EDA_PROYECTO_TRAVEL_H
