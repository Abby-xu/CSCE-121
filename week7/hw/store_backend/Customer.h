//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                  CLASS ATTRIBUTES Homework : SET ONCE                    //
//                                Customer.h                                //
//                                                                          //
// Written By : Rong Xu                 Environment : Mac OS X 10.15.5      //
// Date ......: 2020/07/04              Compiler ...: Sublime Text          //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#ifndef CUSTOMER_H
#define CUSTOMER_H

//////////////////////////////////////////////////////////////////////////////
//                                  Includes                                //
//////////////////////////////////////////////////////////////////////////////
#include "Product.h"

//////////////////////////////////////////////////////////////////////////////
//                         Student Class Definition                         //
//////////////////////////////////////////////////////////////////////////////
class Customer {
	int customerID;
	std::string customerName;
	bool credit;
	double balance;
	std::vector<Product> productsPurchased;

public:
	Customer(int customerID, std::string customerName, bool credit = false);
	int getID() const;
	std::string getName() const;
	void setName(std::string newName);
	bool getCredit() const;
	void setCredit(bool hasCredit);
	double getBalance() const;
	void processPayment(double amount);
	void processPurchase(double amount, Product product);
	std::string getProductsPurchased() const;
};

std::ostream& operator<<(std::ostream &os, const Customer& c);

#endif