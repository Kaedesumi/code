#include "Vehicle.h"

// Your code here

class Car : virtual public Vehicle {
public:
    Car(string name) : Vehicle(name) {}

    void drive() override {
        cout << name << " drive on road" << endl;
    }
};


class Boat : virtual public Vehicle {
public:
    Boat(string name) : Vehicle(name) {}

    void drive() override {
        cout << name << " drive on river" << endl;
    }
};



class AmphibianCar : public Car, public Boat {
public:
    AmphibianCar(string name)
        : Vehicle(name), Car(name), Boat(name) {}

    void drive() override {
        cout << name << " drive on road or river" << endl;
    }
};