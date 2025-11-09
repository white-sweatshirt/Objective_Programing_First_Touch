#include "clients.h"
void Person::introduceYourself()
{
    cout << "mam na imie :" << this->name<<endl;
    cout << "mam " << this->name<<" lat"<<endl;
    cout << "mam ";
    this->pet->beNamed();
}
