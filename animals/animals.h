#ifndef ANIMALS_H
#define ANIMALS_H
#include "people.h"
using namespace std;

class DivisonOfBank
{
public:
    DivisonOfBank(int divisonNumber, string nameBoss, string cityName, double startingFunds, int numberStaff, double totalSalary);
    ~DivisonOfBank();

    void changeNumberOfDivsion(int newNumber);
    void changeBoss(string nameOfNewBoss);
    void layOff(int numberToLayOff);
    void hirePeople(int numberToHire);
    void depositFunds(double funds);
    void withdrawFunds(double funds);

    void showAllInfo();
};

#endif