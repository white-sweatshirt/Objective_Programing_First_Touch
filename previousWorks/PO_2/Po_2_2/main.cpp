#include "car.h"

void checkWheterYouCanDrive(Driver *ala, Mechanic *flitz, Car *car)
{
    cout << car->giveName() << "poziom paliwa: " << car->giveFuelLevel() << " stant techniczny: " << car->giveTechnicalState() << endl;
    if (!ala->canIDrive(car))
    {
        cout << car->giveName() << "wyslany do naprawy" << endl;
        flitz->repair(car);
        cout << car->giveName() << "po naprawie: " << endl;
        cout << "poziom paliwa: " << car->giveFuelLevel() << " stant techniczny: " << car->giveTechnicalState() << endl;
    }
    else
        cout << car->giveName() << " sprawyny mozna jechac " << endl;
}
int main()
{
    Driver *ala = new Driver("ala");
    Car *car1 = new Car(9, false, "Opel Astra");
    Car *car2 = new Car(30, true, "F1");
    Mechanic *flitz = new Mechanic("Fryderyk");
    checkWheterYouCanDrive(ala, flitz, car1);
    checkWheterYouCanDrive(ala, flitz, car2);

    return 0;
}