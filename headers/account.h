#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "people.h"
class Account
{
    private:
    double cashOnAccount;
    Person * owner;
    public:
    double withdrawAllMoneyFromAccount();
    double withdrawCashFromAccount(double amonuntToWithdraw);
    void depositMoneyInAccount(double money);
    Account::Account(Person *owner,double cash);
    Account::~Account();
};
#endif