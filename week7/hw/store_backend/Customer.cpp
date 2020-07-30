//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                  CLASS ATTRIBUTES Homework : SET ONCE                    //
//                               Customer.cpp                               //
//                                                                          //
// Written By : Rong Xu                 Environment : Mac OS X 10.15.5      //
// Date ......: 2020/07/04              Compiler ...: Sublime Text          //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#include "Customer.h"
#include "Product.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////
//                   Student Class Member Definitions                       //
//////////////////////////////////////////////////////////////////////////////
Customer::Customer(int customerID, std::string customerName, bool credit) {
	this -> customerID = customerID;

	if (customerName != "")
		this -> customerName = customerName; 
	else 
		throw std::runtime_error("");
	this -> credit = credit;
	this -> balance = 0.0;
}

int Customer::getID() const {
	return this -> customerID;
}

std::string Customer::getName() const {
	return this -> customerName;
}

void Customer::setName(std::string newName) {
	if (newName != "")
		this -> customerName = newName; 
	else 
		throw std::runtime_error("Name cannot be empty.");
}

bool Customer::getCredit() const {
	return this -> credit;
}

void Customer::setCredit(bool hasCredit) {
	this -> credit = hasCredit;
}

double Customer::getBalance() const {
	return this -> balance;
}

void Customer::processPayment(double amount) {
	if (amount < 0)
		throw std::runtime_error("Amount cannot be negative.");
	else
		this -> balance += amount;
}

void Customer::processPurchase(double amount, Product product) {
	if (this -> credit == true) {
		this -> balance -= amount;
		this -> productsPurchased.push_back(Product(product));
	} else {
		if (balance < amount)
			throw runtime_error("Amount cannot be negative.");
		else
			this -> balance -= amount;
	}
}

std::string Customer::getProductsPurchased() const {
	ostringstream os;
	for (int i = 0; i < productsPurchased.size(); ++i) {
		os << "Product Name: " << productsPurchased.at(i).getName() << endl;
		os << "Product ID: " << productsPurchased.at(i).getID() << endl;
		os << endl;
	}
	return os.str();
}

std::ostream& operator<< (std::ostream& os, const Customer& c) {
	os << "Customer Name: " << c.getName() << endl;
	os << "Customer ID: " << c.getID() << endl;
	os << "Has Credit: ";
	if(c.getCredit() == 0)
		os << "false" << endl;
	else
		os << "true" << endl;
	os << "Balance: " << c.getBalance() << endl;
	os << "Products Purchased --" << endl << endl;
	os << c.getProductsPurchased();
	return os;
}
