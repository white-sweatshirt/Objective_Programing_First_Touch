#include "car.h"
#include "engine.h"

int main()
{
    PersonalCar *privateCar1 = new PersonalCar();
    DeliveryCar *publicCar1 = new DeliveryCar(10);
    Engine *engine = new Engine();

    Velichcale *velichcale=privateCar1;
    Car *car=new Car("Ford",10,1);
    

    return 0;
}