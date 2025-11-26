#include "account.h"

Account::Account(Person *owner, double cash)
{
    this->owner = owner;
    this->cashOnAccount = cash;
}

Account::~Account()
{
    // done in order not delete owner , a person still exits after
    // clousure of account all be it bank ...
    this->owner = NULL;
}

double Account::withdrawAllMoneyFromAccount()
{
    double allCash = this->cashOnAccount;
    this->cashOnAccount = 0.0;
    return cashOnAccount;
}

double Account::withdrawCashFromAccount(double amonuntToWithdraw)
{
    double cash;
    cash = (amonuntToWithdraw < this->cashOnAccount) ? amonuntToWithdraw : cashOnAccount;
    this->cashOnAccount -= cash;
    return cash;
}

void Account::depositMoneyInAccount(double money)
{
    if (money > 0)
        this->cashOnAccount += money;
    else
        cerr << "probowano dodac ujemna ilosc pieniedzy!";
}
