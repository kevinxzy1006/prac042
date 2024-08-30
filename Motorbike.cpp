#include "Motorbike.h"

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const
{
    std::time_t currentTime = std::time(nullptr);
    int duration = std::difftime(currentTime, timeOfEntry);
    return duration * 0.85; // 15% reduction
}