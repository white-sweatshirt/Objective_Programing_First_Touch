#ifndef CAR_H
#define CAR_H
#include "engine.h"
class Velichcale
{
protected:
    string direction;

public:
    void virtual drive();
    void virtual stopYourself();
    void virtual changeDirection(string direction);
};
class Car : public Velichcale
{
protected:
    int numberOfFotels;
    int bootCapacity; // bagznik
    string name;
    bool doorOpen;

    /* data */
public:
    Car();
    Car(string name, int numberOfFotels, int bootCapacity);
    virtual void openDoor();
    virtual void closeDoor();
};
class DeliveryCar : public Car, public EngineCombustion
{
protected:
    int currentLoad;

public:
    DeliveryCar(int load);
    void enload(int load);
};
class PersonalCar : virtual public Car
{
private:
    bool seatBeelsPutOn;
    EngineElectrical carElectrical;
    EngineCombustion carEngine2;

public:
    PersonalCar();
    void closeSeatBells();
};
#endif