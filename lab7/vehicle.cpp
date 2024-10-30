//
// Created by User on 10.04.2024.
//

#include "vehicle.h"

#include <iostream>

Vehicle::Vehicle(const std::string& regNum) : registrationNumber(regNum) {}

Vehicle::~Vehicle() {}

const std::string& Vehicle::getRegistrationNumber() const {
    return registrationNumber;
}

Car::Car(const std::string& regNum, const std::string& body)
        : Vehicle(regNum), bodyStyle(body) {}

const std::string& Car::getBodyStyle() const {
    return bodyStyle;
}

void Car::setBodyStyle(const std::string& body) {
    bodyStyle = body;
}

void Car::display() const {
    std::cout << "Car Registration Number: " << registrationNumber << std::endl;
    std::cout << "Body Style: " << bodyStyle << std::endl;
}

Truck::Truck(const std::string& regNum, double payload)
        : Vehicle(regNum), payloadCapacity(payload) {}

double Truck::getPayloadCapacity() const {
    return payloadCapacity;
}

void Truck::setPayloadCapacity(double payload) {
    payloadCapacity = payload;
}

void Truck::display() const {
    std::cout << "Truck Registration Number: " << registrationNumber << std::endl;
    std::cout << "Payload Capacity: " << payloadCapacity << " tons" << std::endl;
}

Garage::Garage() : numVehicles(0) {
    for (int i = 0; i < MAX_VEHICLES; ++i) {
        vehicles[i] = nullptr;
    }
}

Garage::~Garage() {
    for (int i = 0; i < numVehicles; ++i) {
        delete vehicles[i];
    }
}

void Garage::addVehicle(Vehicle* vehicle) {
    if (numVehicles < MAX_VEHICLES) {
        vehicles[numVehicles++] = vehicle;
    } else {
        std::cerr << "Cannot add vehicle. Garage is full." << std::endl;
    }
}

void Garage::display() const {
    std::cout << "Vehicles in the garage:\n";
    for (int i = 0; i < numVehicles; ++i) {
        vehicles[i]->display();
        std::cout << std::endl;
    }
}
