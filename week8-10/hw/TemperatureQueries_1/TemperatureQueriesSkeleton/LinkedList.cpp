#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	// Implement this function
}

LinkedList::~LinkedList() {
	// Implement this function
	clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	// Implement this function
	head = tail = nullptr;
	for (Node* curr = source.head; curr != nullptr; curr = curr -> next) {
		TemperatureData& data = curr -> data;
		insert(data.id, data.year, data.month, data.temperature);
	}
	cout << endl;
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	clear();
	
	for (Node* curr = source.head; curr != nullptr; curr = curr -> next) {
		TemperatureData& data = curr -> data;
		insert(data.id, data.year, data.month, data.temperature);
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	if (temperature == -99.99)
		return;
	else {
		Node* n = new Node(location, year, month, temperature);
		if (head == nullptr && tail == nullptr) { //empty
			head = n;
			tail = n;
		} else {
			Node* temp = head;
			Node* pretemp = nullptr;
			while (temp != nullptr) {
				if (*temp < *n) {
					pretemp = temp;
					temp = temp -> next;
				} else{
					if(pretemp == nullptr) {  //first
						pretemp = n;
						head = n;
					} else  //middle
						pretemp -> next = n;
					n -> next = temp;
					return;
				}
			}		//last	
			pretemp -> next = n;
			tail = n;
		}
	}
}

void LinkedList::clear() {
	// Implement this function
	while (head != nullptr) {
		Node* temp = head -> next;
		delete head;
		head = temp;
	}
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
    return head;
}

string LinkedList::print() const {
	string outputString;
	std::stringstream ss;
	// Implement this function
	Node* curr = head;
	while(curr != nullptr) {
		ss << curr -> data.id << " " << curr -> data.year << " " << curr -> data.month << " " << curr -> data.temperature << endl;
		curr = curr -> next;
	}

	return ss.str();
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
