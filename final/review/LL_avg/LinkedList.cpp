#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
}

LinkedList::~LinkedList() {
	clear();
}

bool LinkedList::is_empty() const
{
    if (head == nullptr && tail == nullptr)
        return true;
    else
        return false;
}

void LinkedList::insert_front(int value) {
    Node* newNode = new Node(value);
    newNode->next = head; // attach to list
    head = newNode;
    if (tail == nullptr) { // empty list
        tail = newNode; // only node is both head and tail
    }
}

void LinkedList::insert_back(int value) {
    Node* newNode = new Node(value);
    if (tail != nullptr)
        tail->next = newNode; // attach to list
    tail = newNode;
    if (head == nullptr) { // empty list
        head = newNode; // only node is both head and tail
    }
}

bool LinkedList::insert_after(int after_val, int insert_val) {
    if (head == nullptr) {
        return false;
    }
    else {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr -> val == after_val) {
                Node* new_node = new Node(insert_val);
                new_node -> next = curr -> next;
                curr -> next = new_node;
                if (curr == tail) {
                    tail = new_node;
                }
                return true;
            } else {
                curr = curr -> next;
            }
        }
    }
}

void LinkedList::clear() {
	while (head != nullptr) {
		Node* temp = head -> next;
		delete head;
		head = temp;
	}
}

Node* LinkedList::getHead() const {
	// head is a private member so it has to be got by a read function
    return head;
}

string LinkedList::print() const {
	std::stringstream ss;
	Node* curr = head;
	while(curr != nullptr) {
		ss << curr -> val << endl;
		curr = curr -> next;
	}

	return ss.str();
}

double LinkedList::findAVG(string location, int upYr, int dwnYr){

	double sum = 0.0;
	int count = 0;
	for (Node* curr = head; curr != nullptr; curr = curr -> next) {
		sum += curr -> val;
		count ++;
	}

	if (count == 0) {
		cout << "sth error" << endl;
		exit(1);
	}

	return (sum / count);
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
