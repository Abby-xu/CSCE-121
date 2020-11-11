/*
    This file should contain the member function
    implementations for the SavingsAccount class
*/

#include "SavingsAccount.h"

// FIXME: add the constructors (two if you use a default parameter, three otherwise)
SavingsAccount::SavingsAccount(): 
		Account(), interest_rate(0.001) { }

SavingsAccount::SavingsAccount(double interest_rate): 
		Account(), interest_rate(interest_rate) { }

SavingsAccount::SavingsAccount (double balance, double interest_rate):
		Account(balance), interest_rate(interest_rate) { }

// FIXME: add definition for getInterestRate()
double SavingsAccount::getInterestRate() {
	return interest_rate;
}

// FIXME: add definition for setInterestRate(double newRate)
void SavingsAccount::setInterestRate(double newRate) {
	this -> interest_rate = newRate;
}