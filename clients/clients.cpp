#include "clients.h"
void Person::introduceYourself()
{
    cout << "nazywam sie :" << this->name << endl;
    cout << "mam " << this->age << " lat" << endl;
    cout << "mam :" << endl;
    this->pet->giveName();
}
void Customer::getLoan(double amount)
{
    this->cashAtHand += amount;
}
double Customer::giveMoneyForTreatment(double costOfTreatment)
{
    if (this->cashAtHand < costOfTreatment)
    {
        cout << "ide do bakomatu!";
        getLoan(costOfTreatment - cashAtHand);
        cashAtHand -= costOfTreatment;
    }
    cashAtHand -= costOfTreatment;

    return costOfTreatment;
}
void Animal::giveName()
{
    cout << "ma na imie : " << name;
}
int Animal::beHealed()
{
    int ilnesCured = 0;
    ilnesCured += stomAche ? 1 : 0;
    stomAche = 1;
    return ilnesCured;
}
void Dog::giveName()
{
    cout<<"pies ma na imie: "<<name;
}