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
void Velichcale::sayDirection()
{
    cout << "obecnie kieruje sie : " << this->direction << endl;
}
Car::Car()
{
}
Car::Car(string name, int numberOfFotels, int bootCapacity)
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
void Car::showCurrentDoorStatus()
{
    cout << "obecnie mam drzwi " << (this->doorOpen ? "otwarte" : "zamkniete") << endl;
}
DeliveryCar::DeliveryCar(int load) : Car(), EngineCombustion(10, 31)
{
}
void DeliveryCar::enload(int load)
{
    this->currentLoad += load;
}
PersonalCar::~PersonalCar(): ~carEngine2(),~carElectrical()
{

}
PersonalCar::PersonalCar() : Car(), carElectrical(10, 41), carEngine2(13, 31)
{
    closeSeatBells();
}
void PersonalCar::closeSeatBells()
{
    this->seatBeelsPutOn = 1;
}
void PersonalCar::startDiselEngine()
{
    this->carElectrical.startEngine();
}
void PersonalCar::startElectricEngine()
{
    this->carEngine2.startEngine();
}
