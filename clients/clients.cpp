#include "clients.h"
template <class t>
void deleteInbuiltPointersInConteriners(t containerToDelete)
{
    for(auto toDelete: containerToDelete)
        delete toDelete;
    containerToDelete.clear();
}
void Customer::askForHelpWithAnimal(Vet *doctor)
{
    this->introduceYourself();
    double toPay = 0;
    for (int i = 0; i < pets.size(); i++)
        toPay = doctor->serveCustomer(this->pets[i]);
    payFromHand(toPay);
    doctor->getMonyForTreatment(toPay);
}
Customer::Customer(Animal *pets, double cash, string customerName, int age)
{
    // pointer to animal is meant to intilized as there can be diffrent animals pointed by this pointer
    this->name = customerName;
    this->pets.push_back(pets);
    this->moneyAtHand = cash;
    this->age = age;
}
Customer::~Customer()
{
    deleteInbuiltPointersInConteriners(this->pets);
    pets.clear();
}
void Customer::introduceYourself()
{
    cout << "nazywam sie :" << this->name << endl;
    cout << "mam " << this->age << " lat" << endl;
    cout << "mam nastepujace zwierzatka:";
    for (int i = 0; i < pets.size(); i++)
        (pets[i])->giveName();
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
        cout << "ide do bakomatu!" << endl;
        getLoan(costOfTreatment - moneyAtHand);
    }
    else
        cout << "mam przy sobie!" << endl;
    moneyAtHand -= costOfTreatment;

    return costOfTreatment;
}
void Customer::addAnimal(Animal *newpets)
{
    this->pets.push_back(newpets);
}