//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                  CLASS ATTRIBUTES Homework : SET ONCE                    //
//                                Product.h                                 //
//                                                                          //
// Written By : Rong Xu                 Environment : Mac OS X 10.15.5      //
// Date ......: 2020/07/04              Compiler ...: Sublime Text          //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#ifndef PRODUCT_H
#define PRODUCT_H

//////////////////////////////////////////////////////////////////////////////
//                                  Includes                                //
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

//////////////////////////////////////////////////////////////////////////////
//                         Student Class Definition                         //
//////////////////////////////////////////////////////////////////////////////
class Product {
	int productID;
	std::string productName;
	std::string description;
	int inventory;
	int numSold;
	double totalPaid;

public:
	Product(int productID, std::string productName);
	int getID() const;
	std::string getName() const;
	void setName(std::string productName);
	std::string getDescription() const;
	void setDescription(std::string description);
	int getNumberSold() const;
	double getTotalPaid() const;
	int getInventoryCount() const;
	double getPrice() const;
	void addShipment(int shipmentQuantity, double shipmentCost);
	void reduceInventory(int shipmentQuantity);
};

std::ostream& operator<<(std::ostream& os, const Product& p);

#endif