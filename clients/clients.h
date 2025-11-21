#ifndef ANIMALS_H
#define ANIMALS_H

#include "person.h"
#include "paitients.h"
#include "employes.h"
#include <vector>
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
    vector <Animal *> pets; // ma swoje zwierzatko
public:
    void askForHelpWithAnimal(Vet *doctor);
    double payFromHand(double costOfTreatment);
    void getLoan(double amount);
    void introduceYourself();
    
    void addAnimal(Animal * newpets);
    Customer(Animal *pets, double cash, string customerName, int age);
    ~Customer();
};

#endif