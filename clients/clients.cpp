#include "clients.h"
void Customer::introduceYourself()
{
    cout << "nazywam sie :" << this->name << endl;
    cout << "mam " << this->age << " lat" << endl;
    cout<<"mam: ";
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
    cout << "zwierzatko ma na imie : " << name;
}
int Animal::beHealed()
{
    int illnessCured = 0;
    illnessCured += stomAche ? 1 : 0;
    stomAche = 1;
    return illnessCured;
}
void Dog::giveName()
{
    cout << "pies ma na imie: " << name;
}
int Dog::beHealed()
{
    int illnessHealed = 0;
    if (this->hasCold)
        illnessHealed++;
    if (this->illPawn)
        illnessHealed++;
    if (this->stomAche)
        illnessHealed++;
    return illnessHealed;
}
void Dog::giveVoice()
{
    cout<<"Wof Wof";
}