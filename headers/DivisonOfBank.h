#ifndef DIVISON_OF_BANK_H
#define DIVISON_OF_BANK_H

#include "people.h"
#include "account.h"
#include <vector>
#include <list>

using namespace std;


class Bank
{
protected:
    string name;
    // pointer to boss for the bank
    Boss *boss;
    int totalEmployers;
public:
     virtual void showAllInfo();
};

class DivisonOfBank : public Bank
{
private:
    double calculateAvarageSalary();
    int numberOfDivison;
    string cityName;
    double localFunds;
    // place for workers (vector of Worker)
    vector<Worker *> workers;
    list <Account *> clientsAccounts;
    int createAccount();
    // pointer to boss for this division
public:
    DivisonOfBank(int divisonNumber, Boss *newBoss, string cityName, double startingFunds);
    ~DivisonOfBank();

    void changeBoss(Boss *newBOss);
    void layOffAll();
    void hirePerson(Worker *newWorker);
    void depositFunds(double funds,Customer *customer);
    void withdrawFunds(double funds,Customer * customer);

    void showAllInfo();
};

#endif