#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
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
	std::stringstream ss;
	// Implement this function
	Node* curr = head;
	while(curr != nullptr) {
		ss << curr -> data.id << " " << curr -> data.year << " " << curr -> data.month << " " << curr -> data.temperature << endl;
		curr = curr -> next;
	}

	return ss.str();
}

double LinkedList::findAVG(string location, int upYr, int dwnYr){

	double sum = 0.0;
	int count = 0;
	for (Node* curr = head; curr != nullptr; curr = curr -> next) {
		if((curr -> data.id == location) && (curr -> data.year <= dwnYr) && (curr -> data.year >= upYr)) {
			sum += curr -> data.temperature;
			count ++;
		}
	}

	if (count == 0)
		return -99.99;
	return (sum / count);
}

double LinkedList::findMode(std::string location, int upYr, int dwnYr){

	vector<double> nums;
	for (Node* curr = head; curr != nullptr; curr = curr -> next) {
		if((curr -> data.id == location) && (curr -> data.year <= dwnYr) && (curr -> data.year >= upYr)) {
			if ((curr -> data.temperature - int(curr -> data.temperature)) == 0.5)
				nums.push_back(int(curr -> data.temperature));
			else 
				nums.push_back(round(curr -> data.temperature));
		}
	}

    if(nums.size() == 0)
    	return -99.99;

    bool swapp = true;
    while(swapp){
        //cout << "hello" << endl;
        swapp = false;
        //cout << nums.size() << endl;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums.at(i)> nums.at(i + 1) ){
                nums.at(i) += nums.at(i + 1);
                nums.at(i + 1) = nums.at(i) - nums.at(i + 1);
                nums.at(i) -= nums.at(i + 1);
                swapp = true;
            }
        }
    }

    int num;
    int currFre = 0, maxFre = 0;

	for (int i = 0; i < nums.size(); i++) {
		currFre ++;
		if (i == (nums.size() - 1) || nums.at(i) != nums.at(i + 1)) {
			if (currFre >= maxFre) {
				cout << "before num: " << num << " fre: " << maxFre << endl;
				maxFre = currFre;
				num = nums.at(i);
				cout << "curr nums: " << nums.at(i) << "fre: " << maxFre << endl;
			}
			currFre = 0;
		}
	}
	
	return num;
}


ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
