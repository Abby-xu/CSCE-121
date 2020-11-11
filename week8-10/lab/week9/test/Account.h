#ifndef ACCOUNT_H
#define ACCOUNT_H

/*
Simple bank account class

This file contains the class definition and the
declarations of its member functions.
*/

class Account {

private:
    // data members
    double balance;

protected:
    int test;
public:
    // constructor
    Account(double balance = 0);

    // accessors and mutators
    double getBalance() const;
    void setBalance(double newbalance);
};
#endif
