#include "Bus.h"

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const
{
    std::time_t currentTime = std::time(nullptr);
    int duration = std::difftime(currentTime, timeOfEntry);
    return duration * 0.75; // 25% reduction
}