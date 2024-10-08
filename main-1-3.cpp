#include <iostream>
#include "ParkingLot.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include <chrono> // For std::chrono::seconds
#include <thread> // For std::this_thread::sleep_for

int main()
{
    ParkingLot parkingLot(10);

    // Park vehicles
    for (int i = 0; i < 5; ++i)
    { // Park 5 Cars
        Car *car = new Car(i + 1);
        parkingLot.parkVehicle(car);
    }
    for (int i = 0; i < 3; ++i)
    { // Park 3 Buses
        Bus *bus = new Bus(i + 6);
        parkingLot.parkVehicle(bus);
    }
    for (int i = 0; i < 2; ++i)
    { // Park 2 Motorbikes
        Motorbike *motorbike = new Motorbike(i + 9);
        parkingLot.parkVehicle(motorbike);
    }

    // Wait for some time to simulate parking
    // Note: For demonstration purposes, we'll simulate a delay here.
    // In real-world applications, you would not have this kind of simulation.
    std::this_thread::sleep_for(std::chrono::seconds(20));

    int overstayingCount = parkingLot.countOverstayingVehicles(15); // 15 seconds
    std::cout << "Number of vehicles overstaying: " << overstayingCount << std::endl;

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
