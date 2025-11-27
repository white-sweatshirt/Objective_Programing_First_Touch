#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "people.h"
class Account
{
    private:
    double cashOnAccount;
    int idOfOwner;
    public:
    double withdrawAllMoneyFromAccount();
    double withdrawCashFromAccount(double amonuntToWithdraw);
    void depositMoneyInAccount(double money);
    void getId(int id);
    Account::Account(int id,double cash);
    Account::~Account();
};
#endif