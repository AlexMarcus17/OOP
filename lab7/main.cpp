#include <iostream>
#include "Vehicle.h"
using namespace std;
int main() {
Car car1("ABC123", "Sedan");
Truck truck1("XYZ789", 10.5);
Garage garage;
garage.addVehicle(&car1);
garage.addVehicle(&truck1);
garage.display();
return 0;
}