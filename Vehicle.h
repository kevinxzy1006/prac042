#ifndef VEHICLE_H
#define VEHICLE_H

#include <ctime>

class Vehicle
{
protected:
    int ID;

public:
    std::time_t timeOfEntry;
    Vehicle(int id);
    int getID() const;
};

#endif // VEHICLE_H