#include "DivisonOfBank.h"

template <class t>
bool isItPositive(t number)
{
    // assumes that well number is a number and not a text
    if (number < 0)
        return 0;
    else
        return 1;
}
void Bank::showAllInfo()
{
}
DivisonOfBank::DivisonOfBank(int divisonNumber, Boss *startingBoss, string cityName, double startingFunds)
{
    this->numberOfDivison = divisonNumber;
    this->localFunds = startingFunds;
    this->cityName = cityName;
    this->boss = startingBoss; // ensure safe initial state
}

void DivisonOfBank::changeBoss(Boss *newBoss)
{
    delete this->boss;
    this->boss = newBoss;
}

void DivisonOfBank::layOffAll()
{
    // workers who cease to existe are deleted from dataBase
    // what if destroy workres and theirs account remeain ?
    for(auto w:workers)
        delete w;
    workers.clear();
}
void DivisonOfBank::hirePerson(Worker *newWorker)
{
    if (newWorker != NULL)
        this->workers.push_back(newWorker);
    else
        cerr << "brak pracownika do najecia! \n";
}
void DivisonOfBank::depositFunds(double funds)
{
    if (isItPositive(funds))
        this->localFunds += funds;
    else
        cerr << "uzyj funkcji withdrawFunds(double funds) aby wycofac fundusze" << endl;
}
double DivisonOfBank::withdrawFunds(double funds)
{
    if (isItPositive(funds))
        return this->localFunds -= funds;
    else
        cerr << "uzyj depositFunds(double funds) zdeponowac fundusze" << endl;
}

double DivisonOfBank::calculateAvarageSalary()
{
    if (workers.empty())
        return 0.0;
    double sum = 0.0;
    for (auto w : workers)
        sum += w->getSalary();
    sum+=boss->getSalary();
    return sum / (double)(workers.size());
}

void DivisonOfBank::showAllInfo()
{
    if (this->boss)
    {
        this->boss->introduceYourself();
        cout << "jestem szefem :" << endl;
    }
    else
    {
        cout << "Brak szefa dla tego oddzialu." << endl;
    }

    cout << "nr. odzialu to: " << this->numberOfDivison << endl;
    cout << "miejscowosc w ktorej jest odzial: " << this->cityName << endl;
    cout << "ilosc osob zatrudnionych to: " << workers.size() << endl;
    cout << "calkowite fundusze znajdujace sie w odziale: " << this->localFunds << endl;
    cout << "srednia pensja  to: " << calculateAvarageSalary() << endl;

    // iterate through all employees and call their introduceYourself()
    for (auto w : workers)
    {
        w->introduceYourself();
    }
}

DivisonOfBank::~DivisonOfBank()
{
    // clear employee records and free boss pointer if allocated externally
    delete this->boss;
    this->boss = NULL;
    for (auto p : workers)
        delete p;
    workers.clear();
}