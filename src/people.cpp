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
double Customer::giveMoneyFromHand()
{
    double temp = this->moneyAtHand;
    this->moneyAtHand = 0;
    return temp;
}
Customer::Customer(string name, string lastName, double startingCash) : Person(name, lastName)
{
    this->customerId = 0;
    this->moneyAtHand = startingCash;
}
Customer::~Customer()
{
}
int Customer::giveId()
{
    return this->customerId;
}
void Customer::getId(int id)
{
    this->customerId = id;
}
void Customer::getMoney(double amount)
{
    if (amount > 0)
        this->moneyAtHand += amount;
    else
        cerr << "probwano dac ujemna liczbe! \n";
}
/* Worker */
Worker::Worker()
{
}
Worker::Worker(string name, string lastName, double salary)
    : Person(name, lastName), salary(salary)
{
}
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