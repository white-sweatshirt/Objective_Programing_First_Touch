#ifndef DIVISON_OF_BANK_H
#define DIVISON_OF_BANK_H

#include "people.h"
#include <vector>

using namespace std;


class Bank
{
private:
    DivisonOfBank *listOfSubsidoriues;
    string name;

    // pointer to boss for the bank
    Boss *boss;

protected:
    int totalEmployers;

public:
    void showAllInfo();
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
    // pointer to boss for this division
    Boss *boss;

public:
    DivisonOfBank(int divisonNumber, Boss *newBoss, string cityName, double startingFunds, int numberStaff, double totalSalary);
    ~DivisonOfBank();

    void changeBoss(Boss *newBOss);
    void layOffAll(int numberToLayOff);
    void hirePerson(Worker *newWorker);
    void depositFunds(double funds);
    double withdrawFunds(double funds);

    void showAllInfo();
};

#endif