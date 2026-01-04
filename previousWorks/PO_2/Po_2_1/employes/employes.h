#ifndef PEOPLE_H
#define PEOPLE_H
// de facto people in my vetinary
#include "paitients.h"
#include "person.h"

class Vet : public Person
{
    // inherited :string name ,int age, string degree
    // degree i.e master , doctor
    string degree;
public:
    Vet(string name, int age, string degree);
    void introduceYourself();
    double serveCustomer(Animal *paitinet); // as group function for healing and for giving recipe
    void getMonyForTreatment(double cashFromPaitient);
    void sayHowMuchHaveYouMade();
};
#endif