#include <iostream>
#include "ParkingLot.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main()
{
    ParkingLot parkingLot(10);

    while (parkingLot.getCount() < parkingLot.getMaxCapacity())
    {
        char type;
        std::cout << "Enter the type of vehicle to park (C for Car, B for Bus, M for Motorbike): ";
        std::cin >> type;

        int id;
        std::cout << "Enter the ID of the vehicle: ";
        std::cin >> id;

        Vehicle *vehicle = nullptr;
        switch (type)
        {
        case 'C':
            vehicle = new Car(id);
            break;
        case 'B':
            vehicle = new Bus(id);
            break;
        case 'M':
            vehicle = new Motorbike(id);
            break;
        default:
            std::cout << "Invalid type." << std::endl;
            continue;
        }

        if (!parkingLot.parkVehicle(vehicle))
        {
            break;
        }
    }

    std::cout << "The parking lot is full." << std::endl;

    // Clean up memory
    while (parkingLot.getCount() > 0)
    {
        int id;
        std::cout << "Enter the ID of the vehicle to unpark: ";
        std::cin >> id;
        parkingLot.unparkVehicle(id);
    }

    return 0;
}