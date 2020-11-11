/*
    This file contains the member function
    implementations for the Account class
*/

#include "Account.h"

Account::Account(double balance) : balance(balance)
{
}

double Account::getBalance() const
{
    return this->balance;
}

void Account::setBalance(double newbalance)
{
    this->balance = newbalance;
}
