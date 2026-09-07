#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void startEngine() = 0;
    virtual void drive() = 0;

    virtual ~Vehicle() {}
};

class Car : public Vehicle
{
public:
    void startEngine() override
    {
        cout << "Car engine started." << endl;
    }

    void drive() override
    {
        cout << "Car is driving." << endl;
    }
};

class Bike : public Vehicle
{
public:
    void startEngine() override
    {
        cout << "Bike engine started." << endl;
    }

    void drive() override
    {
        cout << "Bike is driving." << endl;
    }
};

int main()
{
    Vehicle* vehicles[2];

    Car car;
    Bike bike;

    vehicles[0] = &car;
    vehicles[1] = &bike;

    for (int i = 0; i < 2; i++)
    {
        vehicles[i]->startEngine();
        vehicles[i]->drive();
        cout << endl;
    }

    return 0;
}
