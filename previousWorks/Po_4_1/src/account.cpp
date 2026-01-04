#include "account.h"

Account::Account(int id, double cash)
{
    this->idOfOwner = id;
    this->cashOnAccount = cash;
}

Account::~Account()
{}

double Account::withdrawAllMoneyFromAccount()
{
    double allCash = this->cashOnAccount;
    this->cashOnAccount = 0.0;
    return cashOnAccount;
}
int Account::giveId()
{
    return this->idOfOwner;
}
double Account::withdrawCashFromAccount(double amonuntToWithdraw)
{
    double cash;
    if(amonuntToWithdraw<0)
    {
        return 0.0;
    }
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
