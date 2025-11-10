#ifndef ANIMALS_H
#define ANIMALS_H

#include "person.h"
#include "paitients.h"
#include "employes.h"

class Customer : public Person
{ /*
     double moneyAtHand;
     string name;
     int age;
 inherited
     */
private:
    Animal *pet; // ma swoje zwierzatko
public:
    void askForHelpWithAnimal(Vet *doctor);
    double payFromHand(double costOfTreatment);
    void getLoan(double amount);
    void introduceYourself();
    Customer(Animal *pet, double cash, string customerName, int age);
    ~Customer();
};

#endif