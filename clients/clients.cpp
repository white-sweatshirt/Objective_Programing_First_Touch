#include "clients.h"
template <class t>
void deleteInbuiltPointersInConteriners(t containerToDelete)
{
    for (auto toDelete : containerToDelete)
        delete toDelete;
    containerToDelete.clear();
}

void Customer::addAnimal(Animal *newpets)
{
    this->pets.push_back(newpets);
}

void Customer::removeAnimal(string nameToRemove)
{

    int i = 0;
    auto pointerToFirst = pets.begin();
    for (auto inspectedAnimal : pets)
    {

        if (inspectedAnimal->giveName() == nameToRemove)
        {
            delete inspectedAnimal;
            pets.remove(inspectedAnimal);
            return;
        }
        i++;
    }
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
    pets.erase(pets.begin(), pets.end());
}

void Customer::introduceYourself()
{
    cout << "nazywam sie :" << this->name << endl;
    cout << "mam " << this->age << " lat" << endl;
    cout << "mam nastepujace zwierzatka:";
    for (auto chosenPet : pets)
        (chosenPet)->sayName();
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

void Customer::askForHelpWithAnimals(Vet *doctor)
{
    this->introduceYourself();
    double toPay = 0;
    for (auto chosenPet : pets)
        toPay += doctor->serveCustomer(chosenPet);
    cout << "musze zaplacic: " << toPay << endl;
    payFromHand(toPay);
    doctor->getMonyForTreatment(toPay);
}