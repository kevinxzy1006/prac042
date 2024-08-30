#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Vehicle.h"
#include <vector>

class ParkingLot
{
private:
    int maxCapacity;
    int currentCount;
    std::vector<Vehicle *> vehicles;

public:
    ParkingLot(int capacity);
    int getMaxCapacity();
    int getCount() const;
    bool parkVehicle(Vehicle *vehicle);
    bool unparkVehicle(int id);
    int countOverstayingVehicles(int maxParkingDuration) const;
};

#endif // PARKINGLOT_H