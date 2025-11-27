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

public:
    Person();
    Person(const string &name, const string &lastName);

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

     void setSalary(double s);
     double getSalary();

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
class Customer:public Person
{
    // class responsibable for solving dilema of deleting worker but not
    // workers account.
    double moneyAtHand;
    int customerId;
    public:
    Customer(string name,string lastName);
    ~Customer();
    int giveId();
    void getId(int id);
    void depositFundsToBank(DivisonOfBank *unit);
    void withdrawMoneyFromBank(DivisonOfBank *unit);
    void getMoney(double amount);
};
#endif