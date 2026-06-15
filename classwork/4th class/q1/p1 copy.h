#include "Vehicle.h"

// Your code here
/*
class Vehicle {
    protected:
        string name;
    public:
        Vehicle(string name): name(name) {};
        virtual void drive() = 0;
};
*/



class Car: virtual public Vehicle{
    public:
        Car(string name):Vehicle(name){}
        void drive() override {
            cout << name << " drive on road" << endl;
        }
};

class Boat: virtual public Vehicle{
    public:
        Boat(string name):Vehicle(name){}
        void drive() override {
            cout << name << " drive on river" << endl;
        }
};

class AmphibianCar:public Car,public Boat{
    public:
        AmphibianCar(string name):Car(name),Boat(name),Vehicle(name){}
        void drive() override {
                cout << name << " drive on road or river" << endl;
        }
};