#include "car.h"
void Velichcale::drive()
{
    this->direction = "prosto";
}
void Velichcale::stopYourself()
{
    this->direction = "stop";
}
void Velichcale::changeDirection(string direction)
{
    this->direction = direction;
}
Car::Car() : carElectrical(10,41), carEngine2(13,31)
{

}
Car::Car(string name, int numberOfFotels, int bootCapacity): carElectrical(10,41), carEngine2(13,31)
{
    this->name = name;
    this->numberOfFotels = numberOfFotels;
    this->bootCapacity = bootCapacity;
}
void Car::openDoor()
{
    this->doorOpen = true;
}
void Car::closeDoor()
{
    this->doorOpen = false;
}
DeliveryCar::DeliveryCar(int load) : Car(), currentLoad(load)
{
}
void DeliveryCar::enload(int load)
{
    this->currentLoad += load;
}
PersonalCar::PersonalCar() : Car()
{
    closeSeatBells();
}
void PersonalCar::closeSeatBells()
{
    this->seatBeelsPutOn = 1;
}
