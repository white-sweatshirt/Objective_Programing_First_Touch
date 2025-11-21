#include "employes.h"
Vet::Vet(string name, int age, string degree)
{
    this->age = age;
    this->name = name;
    this->degree = degree;
    this->moneyAtHand = 0.0;
}
void Vet::introduceYourself()
{
    cout << "nazywam sie :" << this->name << endl;
    cout << "mam " << this->age << " lat" << endl;
    cout << "mam dyplom: " << degree << endl;
}

double Vet::serveCustomer(Animal *petient)
{
    double illnesHealed = petient->beHealed();
    double constexpr vetFee = 200, baseFee = 50;
    cout << "-pana: " << petient->giveName() << " zostal uleczony, kosztowalo to:" << vetFee * (double)illnesHealed + baseFee << endl;
    /*  if (illnesHealed == 0)
          cout << "byla juz wczesniej zdrowa!\n ale i tak wizyta kosztuje: " << baseFee << endl;
      else
          cout << "jest juz zdrowa !" << endl;
          */
    return vetFee * (double)illnesHealed + baseFee;
}
void Vet::getMonyForTreatment(double moneyForTreatment)
{
    this->moneyAtHand += moneyForTreatment;
}
void Vet::sayHowMuchHaveYouMade()
{
    cout << name << " dzis zarobil: " << this->moneyAtHand << endl;
}