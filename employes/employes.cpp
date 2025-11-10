#include "employes.h"
Vet::Vet(string name, int age, string degree)
{
    this->name = name;
    this->degree = degree;
    this->moneyAtHand = 0.0;
}
void Vet::introduceYourself()
{
    cout << "nazywam sie :" << this->name << endl;
    cout << "mam " << this->age << " lat" << endl;
    cout << "mam dyplom: " << degree;
}
double Vet::serveCustomer(Animal *petient)
{
    double illnesHealed = petient->beHealed();
    double constexpr vetFee = 200, baseFee = 50;
    cout << "pana: ";
    petient->giveName();
    cout << "jest juz zdrowa !" << endl;
    if (illnesHealed == 0)
        cout << "byla juz wczesniej zdrowa!\n ale i tak wizyta kosztuje: " << baseFee << endl;
    else
        cout << " calosc kosztowala : " << vetFee * (double)illnesHealed + baseFee;
    return vetFee * (double)illnesHealed + baseFee;
}
void Vet::getMonyForTreatment(double moneyForTreatment)
{
    this->moneyAtHand += moneyForTreatment;
}
void Vet::sayHowMuchHaveYouMade()
{
    cout << "dzis zarobilem: " << this->moneyAtHand << endl;
}