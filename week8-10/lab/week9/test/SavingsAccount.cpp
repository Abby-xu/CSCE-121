/*
    This file should contain the member function
    implementations for the SavingsAccount class
*/

#include "SavingsAccount.h"
//SavingsAccount::SavingsAccount():Account(),interest_rate(){}
SavingsAccount::SavingsAccount(double interest_rate): 
Account(), interest_rate(interest_rate) { }
// FIXME: add the constructors (two if you use a default parameter, three otherwise)
SavingsAccount::SavingsAccount(double balance, double interest_rate): 
Account(balance), interest_rate(interest_rate) {
    }


// FIXME: add definition for getInterestRate()
double SavingsAccount::getInterestRate()const{
  return interest_rate;
}

// FIXME: add definition for setInterestRate(double newRate)
void SavingsAccount::setInterestRate(double newRate){
  this -> interest_rate = newRate;
}
