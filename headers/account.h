#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "people.h"
class Account
{
    private:
    double cashOnAccount;
    Person * owner;
    public:
    double withdrawCashFromAccount();
    void depositMoneyInAccount(double money);
};
#endif