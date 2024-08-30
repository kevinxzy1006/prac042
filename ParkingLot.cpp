#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int capacity) : maxCapacity(capacity), currentCount(0) {}

int ParkingLot::getCount() const
{
    return currentCount;
}

int ParkingLot::getMaxCapacity()
{
    return maxCapacity;
}

bool ParkingLot::parkVehicle(Vehicle *vehicle)
{
    if (currentCount < maxCapacity)
    {
        vehicles.push_back(vehicle);
        currentCount++;
        return true;
    }
    std::cout << "The lot is full" << std::endl;
    return false;
}

bool ParkingLot::unparkVehicle(int id)
{
    for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
    {
        if ((*it)->getID() == id)
        {
            vehicles.erase(it);
            currentCount--;
            return true;
        }
    }
    std::cout << "Vehicle not in the lot" << std::endl;
    return false;
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const
{
    int count = 0;
    for (const auto &vehicle : vehicles)
    {
        std::time_t currentTime = std::time(nullptr);
        int duration = std::difftime(currentTime, vehicle->timeOfEntry);
        if (duration > maxParkingDuration)
        {
            count++;
        }
    }
    return count;
}