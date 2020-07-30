//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                  CLASS ATTRIBUTES Homework : SET ONCE                    //
//                               Product.cpp                                //
//                                                                          //
// Written By : Rong Xu                 Environment : Mac OS X 10.15.5      //
// Date ......: 2020/07/04              Compiler ...: Sublime Text          //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#include "Product.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////
//                   Student Class Member Definitions                       //
//////////////////////////////////////////////////////////////////////////////
Product::Product(int productID, std::string productName) {
	this -> productID = productID;
	if (productName != "")
		this -> productName = productName; 
	else 
		throw std::runtime_error("Product name cannot be empty.");
	inventory = 0;
	numSold = 0;
	totalPaid = 0.0;
	description = "";
}

int Product::getID() const {
	return this -> productID;
}

string Product::getName() const {
	return this -> productName; 
}

void Product::setName(std::string productName) {
	if (productName != "")
		this -> productName = productName; 
	else 
		throw std::runtime_error("Product name cannot be empty.");
}

string Product::getDescription() const {
	return this -> description; 
}

void Product::setDescription(std::string description) {
	this -> description = description;
}

int Product::getNumberSold() const {
	return this -> numSold;
}

double Product::getTotalPaid() const {
	return this -> totalPaid;
}

int Product::getInventoryCount() const {
	return this -> inventory;
}

double Product::getPrice() const {
	if ((inventory + numSold) == 0)
		throw std::runtime_error("can not calculate.");
	return (totalPaid / double(inventory + numSold)) * 1.25;
}

void Product::addShipment(int shipmentQuantity, double shipmentCost) {
	if (shipmentQuantity < 0 || shipmentCost < 0)
		throw std::runtime_error("Shipment quantity and shipment cost cannot be negative.");
	else {
		this -> inventory += shipmentQuantity;
		this -> totalPaid += shipmentCost;
	}
}

void Product::reduceInventory(int shipmentQuantity) {
	if (!(this -> inventory > shipmentQuantity && shipmentQuantity > 0)) 
		throw std::runtime_error("not enough inventory or purchase quantity is negative.");
	else {
		this -> inventory -= shipmentQuantity;
		this -> numSold += shipmentQuantity;
	}
}

std::ostream& operator<< (std::ostream& os, const Product& p) {
	os << "Product Name: " << p.getName() << endl;
	os << "Product ID: " << p.getID() << endl;
	os << "Description: " << p.getDescription() << endl;
	os << "Inventory: " << p.getInventoryCount() << endl;
	os << "Number Sold: " << p.getNumberSold() << endl;
	os << "Total Paid: " << p.getTotalPaid() << endl;
	if ((p.getInventoryCount() + p.getNumberSold()) == 0)
		os << "Price: " << "Unavailable" << endl;
	else
		os << "Price: " << p.getPrice() << endl;
	return os;
}