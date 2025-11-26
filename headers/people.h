#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class DivisonOfBank; // forward declaration

class Person
{
protected:
    string name;
    string lastName;
    double moneyAtHand;

public:
    Person();
    Person(const string &name, const string &lastName);
    void depotMoneuToBank(DivisonOfBank *unit);
    void withdrawMoneyFromBank(DivisonOfBank *unit);
    ~Person();

    void introduceYourself();
};

class Worker : public Person
{
private:
    double salary;

public:
    Worker();
    Worker(string name, string lastName, double salary);
    virtual ~Worker();

    virtual void setSalary(double s);
    virtual double getSalary();

    void introduceYourself();
};

// Added Boss class inheriting from Person
class Boss : public Person
{
private:
    double salary;
    string nameOfYacht;

public:
    Boss(string name, string lastName, double salary, string yacht);

    void setSalary(double s);
    double getSalary();

    void setYacht(string yacht);
    string getYacht();

    void introduceYourself();
};

#endif