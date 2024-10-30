//
// Created by User on 10.04.2024.
//
#include "string"
#ifndef OOP7_VEHICLE_H
#define OOP7_VEHICLE_H
using namespace std;

class Vehicle {
protected:
    std::string registrationNumber;

public:
    Vehicle(const std::string& regNum);
    virtual ~Vehicle();

    virtual void display() const = 0;

    const std::string& getRegistrationNumber() const;
};

class Car : public Vehicle {
private:
    std::string bodyStyle;

public:
    Car(const std::string& regNum, const std::string& body);

    const std::string& getBodyStyle() const;
    void setBodyStyle(const std::string& body);

    virtual void display() const override;
};

class Truck : public Vehicle {
private:
    double payloadCapacity;

public:
    Truck(const std::string& regNum, double payload);

    double getPayloadCapacity() const;
    void setPayloadCapacity(double payload);

    virtual void display() const override;
};

class Garage {
private:
    static const int MAX_VEHICLES = 10; // Maximum number of vehicles
    Vehicle* vehicles[MAX_VEHICLES];
    int numVehicles;

public:
    Garage();
    ~Garage();

    void addVehicle(Vehicle* vehicle);
    void display() const;
};


#endif //OOP7_VEHICLE_H
