//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                  CLASS ATTRIBUTES Homework : SET ONCE                    //
//                                 Store.h                                  //
//                                                                          //
// Written By : Rong Xu                 Environment : Mac OS X 10.15.5      //
// Date ......: 2020/07/04              Compiler ...: Sublime Text          //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#ifndef STORE_H
#define STORE_H

//////////////////////////////////////////////////////////////////////////////
//                                  Includes                                //
//////////////////////////////////////////////////////////////////////////////
#include "Product.h"
#include "Customer.h"
//////////////////////////////////////////////////////////////////////////////
//                         Student Class Definition                         //
//////////////////////////////////////////////////////////////////////////////
class Store {
	std::string name;
	std::vector<Product> products;
	std::vector<Customer> customers;

public:
	Store();
	Store(std::string name);
	std::string getName();
	void setName(std::string newName);
	void addProduct(int productID, std::string productName);
	Product& getProduct(int productID);
	void addCustomer(int customerID, std::string customerName, bool credit = false);
	Customer& getCustomer(int customerID);
	void takeShipment(int productID, int quantity, double cost);
	void takePayment(int customerID, double amount);
	void sellProduct(int customerID, int productID, int quantity);
	std::string listProducts() const;
	std::string listCustomers()const;
};
#endif