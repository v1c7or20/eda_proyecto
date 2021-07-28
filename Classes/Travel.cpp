//
// Created by msi on 6/07/2021.
//

#include "Travel.h"

const std::string &Travel::getPickupDate() const {
    return pickupDate;
}

const std::string &Travel::getDropoffDate() const {
    return dropoffDate;
}

int Travel::getPassengerCount() const {
    return passengerCount;
}

double Travel::getTripDistance() const {
    return tripDistance;
}

double Travel::getFareAmount() const {
    return fareAmount;
}

void Travel::setPickupDate(const std::string &pickupDate) {
    Travel::pickupDate = pickupDate;
}

void Travel::setDropoffDate(const std::string &dropoffDate) {
    Travel::dropoffDate = dropoffDate;
}

void Travel::setPassengerCount(int passengerCount) {
    Travel::passengerCount = passengerCount;
}

void Travel::setTripDistance(double tripDistance) {
    Travel::tripDistance = tripDistance;
}

void Travel::setFareAmount(double fareAmount) {
    Travel::fareAmount = fareAmount;
}

TravelPoint &Travel::getStartingPoint() {
    return StartingPoint;
}

TravelPoint &Travel::getArrivalPoint() {
    return ArrivalPoint;
}

void Travel::setStartingPint(const TravelPoint &startingPint) {
    StartingPoint = startingPint;
}

void Travel::setArrivalPoint(const TravelPoint &arrivalPoint) {
    ArrivalPoint = arrivalPoint;
}

Travel::Travel(const Travel &obj) {
    pickupDate = obj.pickupDate;
    dropoffDate = obj.dropoffDate;
    passengerCount = obj.passengerCount;
    tripDistance = obj.tripDistance;
    fareAmount = obj.fareAmount;
    StartingPoint = obj.StartingPoint;
    ArrivalPoint = obj.ArrivalPoint;
}

Travel::Travel() = default;
