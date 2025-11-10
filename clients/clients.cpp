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
