//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                  CLASS ATTRIBUTES Homework : SET ONCE                    //
//                                Store.cpp                                 //
//                                                                          //
// Written By : Rong Xu                 Environment : Mac OS X 10.15.5      //
// Date ......: 2020/07/04              Compiler ...: Sublime Text          //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#include "Store.h"
#include "Customer.h"
#include "Product.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////
//                   Student Class Member Definitions                       //
//////////////////////////////////////////////////////////////////////////////
Store::Store(): 
	name("") 
{}

Store::Store(std::string name) {
	this -> name = name;
}

std::string Store::getName() {
	return this -> name;
}

void Store::setName(std::string newName) {
	this -> name = newName;
}

void Store::addProduct(int productID, std::string productName) {
	for (int i = 0; i < this -> products.size(); ++i) {
		if (this -> products.at(i).getID() == productID)
			throw runtime_error("This productID already belongs to another product.");
	}
	this -> products.push_back(Product(productID, productName));
}

Product& Store::getProduct(int productID) {
	for (int i = 0; i < products.size(); i++) {
		if (this -> products.at(i).getID() == productID)
			return products.at(i);
	}
	throw runtime_error("The product does not exist.");
}

void Store::addCustomer(int customerID, std::string customerName, bool credit) {
	for (int i = 0; i < this -> customers.size(); ++i) {
		if (this -> customers.at(i).getID() ==  customerID)
			throw runtime_error("This customerID already belongs to another customer.");
	}
	this -> customers.push_back(Customer(customerID, customerName, credit));
}

Customer& Store::getCustomer(int customerID) {
	for (int i = 0; i < customers.size(); i++) {
		if (this -> customers.at(i).getID() == customerID)
			return customers.at(i);
	}
	throw runtime_error("The customer does not exist.");
}

void Store::takeShipment(int productID, int quantity, double cost) {
	getProduct(productID).addShipment(quantity, cost);
}

void Store::takePayment(int customerID, double amount) {
	Customer& cust = getCustomer(customerID);
 	cust.processPayment(amount); 
}

void Store::sellProduct(int customerID, int productID, int quantity) {
	int remanin = getProduct(productID).getInventoryCount();
	if (getCustomer(customerID).getCredit() || getCustomer(customerID).getBalance() >= (getProduct(productID).getPrice() * quantity)) {
		if (remanin < quantity)
			throw runtime_error("The sale is not allowed because it's not enough.");
		else {
			getProduct(productID).reduceInventory(quantity);
			getCustomer(customerID).processPurchase(getProduct(productID).getPrice() * quantity, getProduct(productID));
		}
	}
}

std::string Store::listProducts() const {
	ostringstream os;
	// os << "Products in " << name << ": " << endl;
	if (products.size() == 0)
		os << "";
	else {
		for (int i = 0; i < products.size(); ++i) {
			os << products.at(i)<< endl;;
		}
	}
	return os.str();
}

std::string Store::listCustomers() const {
	ostringstream os;
	// os << "Customers in " << name << ": " << endl;
	if (customers.size() == 0)
		os << "";
	else {
		for (int i = 0; i < customers.size(); ++i) {
			os << customers.at(i) << endl;
		}
	}
	return os.str();
}
