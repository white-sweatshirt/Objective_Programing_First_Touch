#include "car.h"
#include "engine.h"
#include "tractor.h"
int main()
{
    PersonalCar *personalCar = new PersonalCar();
    DeliveryCar *deliverrCar = new DeliveryCar(10);

    Velichcale *velichcale = personalCar;
    Car *car = new Car("Ford", 10, 1);
    Engine *engine = new Engine();

    car->openDoor();
    car->showCurrentDoorStatus();
    engine->startEngine();
    car->closeDoor();
    car->showCurrentDoorStatus();
    velichcale->changeDirection("prawo");
    velichcale->sayDirection();
    deliverrCar->stopYourself();
    deliverrCar->turnOffEngine();
    Velichcale *velichcale2 = personalCar;
    Car *car2 = personalCar;
    // is imposible here as personal car is composed from engines
    // and it doesnot inherit it
    // EngineElectrical *engineElectrical=PersonalCar;
    // EngineCombustion *engineCombustion=PersonalCar;
    
    personalCar->startDiselEngine();
    personalCar->startElectricEngine();
    car2->openDoor();
    personalCar->closeDoor();
    velichcale2->drive();
    velichcale2->sayDirection();
    personalCar->changeDirection("lewo");
    personalCar->stopYourself();

    return 0;
}