#ifndef CAR_H
#define CAR_H
#include "engine.h"
class Velichcale
{
public:
    void drive();
    void stopYourself();
    void changeDirection();
};
class Car : public Velichcale
{
protected:
    int numberOfFotels;
    int bootCapacity;
    string name;
    /* data */
public:
    Car(string name, int numberOfFotels, int bootCapacity);
    void openDoor();
    void closeDoor();
};
class PersonalCar : virtual public Car
{
public:
    PersonalCar();
    void closeSeatBells();
};
#endif