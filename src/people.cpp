#include "people.h"
#include "DivisonOfBank.h"
using namespace std;

/* Person */
Person::Person(const string &name, const string &lastName) : name(name), lastName(lastName)
{
}
Person::Person()
{
}
Person::~Person()
{
}
void Person::introduceYourself()
{
    cout << "Name: " << name << " " << lastName << endl;
}
void Person::depotMoneuToBank(DivisonOfBank* unit)
{
    unit->depositFunds(this->moneyAtHand);
    this->moneyAtHand=0;
}
void Person::withdrawMoneyFromBank(DivisonOfBank * unit)
{
    // to be changed as bank should remeber how much it owns to
    // any customer.
    this->moneyAtHand=unit->withdrawFunds(1000);
}
/* Worker */
Worker::Worker()
{
}
Worker::Worker( string name, string lastName, double salary)
    : Person(name, lastName), salary(salary)
{}
Worker::~Worker()
{
}
void Worker::setSalary(double s)
{
    salary = s;
}
double Worker::getSalary()
{
    return salary;
}

void Worker::introduceYourself()
{
    cout << " jestem " << this->name << " mam na nazwisko: " << this->lastName << endl;
    cout << "zarabiam " << this->salary << endl;
}

Boss::Boss(string name, string lastName, double salary, string yacht)
    : Person(name, lastName), salary(salary), nameOfYacht(yacht)
{
}

void Boss::setSalary(double s)
{
    salary = s;
}
double Boss::getSalary()
{
    return salary;
}

void Boss::setYacht(string yacht)
{
    nameOfYacht = yacht;
}
string Boss::getYacht()
{
    return nameOfYacht;
}

void Boss::introduceYourself()
{
    cout << " jestem " << this->name << " mam na nazwisko: " << this->lastName << endl;
    cout << "zarabiam " << this->salary << endl;
    cout << "posiadam jacht: " << this->nameOfYacht << endl;
}