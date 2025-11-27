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
    this->totalEmployers = 0;
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
    for (auto w : workers)
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
int DivisonOfBank::createAccount()
{
    int static id = 0;
    return id++;
}
int DivisonOfBank::depositFunds(double funds, int id)
{
    // returns id of user
    bool wasThereTransaction = 0;
    if (isItPositive(funds))
    {
        if (id == 0)
            id = createAccount();
        for (auto w : clientsAccounts)
        {
            if (w->giveId() == id)
            {
                w->depositMoneyInAccount(funds);
                wasThereTransaction = 1;
                break;
            }
        }
        if (!wasThereTransaction)
            clientsAccounts.push_back(new Account(id, funds));
        this->localFunds += funds;
    }
    else
        cerr << "uzyj funkcji withdrawFunds(double funds) aby wycofac fundusze" << endl;
    return id;
}
double DivisonOfBank::withdrawFunds(double funds, int id)
{
    for (auto w : clientsAccounts)
    {
        if (w->giveId() == id)
        {
            this->localFunds -= w->withdrawCashFromAccount(funds);
            return w->withdrawCashFromAccount(funds);
        }
    }
    return 0.0;
}

double DivisonOfBank::calculateAvarageSalary()
{
    if (workers.empty())
        return 0.0;
    double sum = 0.0;
    for (auto w : workers)
        sum += w->getSalary();
    sum += boss->getSalary();
    return sum / (double)(workers.size());
}

void DivisonOfBank::showAllInfo()
{
    if (this->boss)
    {
        this->boss->introduceYourself();
        cout << "jestem szefem banku " << endl;
    }
    else
    {
        cout << "Brak szefa dla tego oddzialu." << endl;
    }

    cout << "nr. odzialu: " << this->numberOfDivison << endl;
    cout << "miejscowosc w ktorej jest odzial: " << this->cityName << endl;
    cout << "ilosc osob zatrudnionych to: " << workers.size() << endl;
    cout << "calkowite fundusze znajdujace sie w odziale: " << this->localFunds << endl;
    cout << "srednia pensja  to: " << calculateAvarageSalary() << endl;

    // iterate through all employees and call their introduceYourself()
    for (auto w : workers)
    {
        w->introduceYourself();
    }
    for (auto w : clientsAccounts)
    {
        cout << "klient o id powierzyl nam" << w->cashOnAccount << endl;
    }
}

DivisonOfBank::~DivisonOfBank()
{
    // clear employee records and free boss pointer if allocated externally
    delete this->boss;
    this->boss = NULL;
    for (auto p : workers)
        delete p;
    for (auto w : clientsAccounts)
        delete w;
    clientsAccounts.clear();
    workers.clear();
}