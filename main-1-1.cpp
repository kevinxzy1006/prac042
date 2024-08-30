#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main()
{
    int numVehicles;
    std::cout << "Enter the number of vehicles: ";
    std::cin >> numVehicles;

    Vehicle *vehicles[numVehicles];

    for (int i = 0; i < numVehicles; ++i)
    {
        char type;
        std::cout << "Enter the type of vehicle (C for Car, B for Bus, M for Motorbike): ";
        std::cin >> type;

        int id;
        std::cout << "Enter the ID of the vehicle: ";
        std::cin >> id;

        switch (type)
        {
        case 'C':
            vehicles[i] = new Car(id);
            break;
        case 'B':
            vehicles[i] = new Bus(id);
            break;
        case 'M':
            vehicles[i] = new Motorbike(id);
            break;
        default:
            std::cout << "Invalid type." << std::endl;
            --i; // Retry for this index
            break;
        }
    }

    std::cout << "\nParking Durations:" << std::endl;
    for (int i = 0; i < numVehicles; ++i)
    {
        std::cout << "Vehicle ID " << vehicles[i]->getID() << ": "
                  << ((Car *)vehicles[i])->getParkingDuration() << " seconds" << std::endl;
    }

    // Clean up memory
    for (int i = 0; i < numVehicles; ++i)
    {
        delete vehicles[i];
    }

    return 0;
}