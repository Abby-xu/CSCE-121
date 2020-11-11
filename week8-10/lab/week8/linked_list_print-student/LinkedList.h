#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
#include "Node.h"

class LinkedList {
	Node* head;
	Node* tail;
	std::string name;

public:
	LinkedList();
	LinkedList(std::string);

    /* not the real way to create a list, but it will give us something to
       use for testing parts until we learn how.
    */
	void make_test_list();

	std::string get_name() const;
	void set_name(std::string Newname);
	void print(char, std::ostream& os = std::cout);

};

std::ostream& operator<<(std::ostream& os, const Node& n); 

#endif