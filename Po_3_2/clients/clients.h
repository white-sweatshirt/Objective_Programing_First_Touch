#ifndef ANIMALS_H
#define ANIMALS_H

#include "person.h"
#include "paitients.h"
#include "employes.h"
#include <list>
template <class t>
void deleteInbuiltPointersInConteriners(t containerToDelete);
class Customer : public Person
{ /*
     double moneyAtHand;
     string name;
     int age;
 inherited
     */
private:
    list<Animal *> pets; // ma swoje zwierzatko

public:
    void askForHelpWithAnimals(Vet *doctor);
    double payFromHand(double costOfTreatment);
    void getLoan(double amount);
    void introduceYourself();

    void addAnimal(Animal *newpets);
    void removeAnimal(string nameOfAnimalToEthunize);

    Customer(Animal *pets, double cash, string customerName, int age);
    ~Customer();
};

#endif