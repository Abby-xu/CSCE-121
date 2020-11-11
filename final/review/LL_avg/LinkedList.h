#ifndef LINKEDLIST
#define LINKEDLIST

#include "Node.h"

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	// Default constructor
	LinkedList();

	// Destructor
	~LinkedList();

	bool is_empty() const;

	// Insert a record to the linked list
	void insert_front(int value);

	void insert_back(int value);

	bool insert_after(int after_val, int insert_val);

	// Clear the content of this linked list
	void clear();

	// The functions below are written already. Do not modify them.
	std::string print() const;

	Node* getHead() const;

	//find the average of the ll and return the string of result
	double findAVG(std::string location, int upYr, int dwnYr);
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
#endif
