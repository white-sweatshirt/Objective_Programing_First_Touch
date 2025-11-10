#ifndef ANIMALS_H
#define ANIMALS_H
#include <iostream>
using namespace std;
#include "person.h"
#include "paitients.h"
#include "employes.h"
class Customer : public Person
{
private:
    Animal * pet;// ma swoje zwierzatko
    double cashAtHand;
public:
    void askForHelpWithAnimal(Vet *doctor);
    double giveMoneyForTreatment(double costOfTreatment);
    void getLoan(double amount);
    void introduceYourself();
};


#endif