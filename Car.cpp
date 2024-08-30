#include "Car.h"

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const
{
    std::time_t currentTime = std::time(nullptr);
    int duration = std::difftime(currentTime, timeOfEntry);
    return duration * 0.9; // 10% reduction
}