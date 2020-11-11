#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::LinkedList(string name) : head(nullptr), tail(nullptr), name(name) {}

void LinkedList::setName(string name) {
    this->name = name;
}

string LinkedList::getName() const {
    return name;
}

void LinkedList::print(char c, ostream& os) {
    Node* cur = head;
    if (head != nullptr) {
        while (cur != nullptr) {
            os << *cur;
            if (cur != tail)
                os << c;
            if (cur == tail)
                os << endl;
            cur = cur->next;
        }
    }
    else {
        os << "<Empty List>" << c;
    }
}

void LinkedList::print_head(char c, ostream& os) {
    if (head != nullptr) {
        os << head->value << c;
    }
    else {
        os << "<Empty List>" << c;
    }
}

void LinkedList::print_tail(char c, ostream& os) {
    if (head != nullptr) {
        os << tail->value << c;
    }
    else {
        os << "<Empty List>" << c;
    }
}

void LinkedList::makeTestList() {
    // not the real way to create a list, but it will give us something to
    //  use for testing parts until we learn how.
    Node* newNode = new Node(7);
    head = newNode;
    newNode = new Node(3);
    head->next = newNode;
    newNode = new Node(12);
    head->next->next = newNode;
    tail = newNode;
}

bool LinkedList::is_empty() {
	if (head == nullptr && tail == nullptr) 
		return true;
	else
		return false;
}

void LinkedList::insert_front(Node * n) {
    if (is_empty()) {
        head = n; tail = n;
    }
    else {
        n->next = head;
        head = n;
    }
}

void LinkedList::insert_back(Node * n) {
	if (is_empty()) {
		head = n; tail = n;
	}
	else {
		tail -> next = n;
		tail = n;
	}
}