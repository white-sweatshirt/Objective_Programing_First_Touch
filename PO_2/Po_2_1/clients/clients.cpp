#include "clients.h"
Customer::Customer(Animal *pet, double cash, string customerName, int age)
{
    // pointer to animal is meant to intilized as there can be diffrent animals pointed by this pointer
    this->name = customerName;
    this->pet = pet;
    this->moneyAtHand = cash;
    this->age = age;
}
Customer::~Customer()
{
    delete pet;
}
void Customer::introduceYourself()
{
    cout << "nazywam sie :" << this->name << endl;
    cout << "mam " << this->age << " lat" << endl;
    cout << "mam ";
    this->pet->giveName();
    cout << "i potrzebuje pomocy zwiazanej z jego leczniem" << endl;
}
void Customer::getLoan(double amount)
{
    this->moneyAtHand += amount;
}
double Customer::payFromHand(double costOfTreatment)
{
    if (this->moneyAtHand < costOfTreatment)
    {
        cout << "-ide do bakomatu!" << endl;
        getLoan(costOfTreatment - moneyAtHand);
    }
    else
        cout << "-mam przy sobie!" << endl;
    moneyAtHand -= costOfTreatment;

    return costOfTreatment;
}
void Customer::askForHelpWithAnimal(Vet *doctor)
{
    this->introduceYourself();
    double toPay = 0;
    toPay = doctor->serveCustomer(this->pet);
    payFromHand(toPay);
    doctor->getMonyForTreatment(toPay);
}