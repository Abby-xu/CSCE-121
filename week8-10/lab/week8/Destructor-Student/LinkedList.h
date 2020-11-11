#ifndef LINKEDLIST
#define LINKEDLIST
#include <ostream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Node.h"

class LinkedList {
public:
    LinkedList();
    LinkedList(std::string);
    // FIXME: destrcutor declaration
    ~LinkedList();
    void empty();
    void setName(std::string);
    std::string getName() const;
    Node* getHead() const;
    void insertFront(int);
    void insertBack(int);
    void clear();
    void print() const;
    void print(std::ostream&) const;
    void printReverse() const;
    void printReverse(std::ostream&) const;
    void log(std::string what) const;
private:
    Node* head;
    Node* tail;
    std::string name;
    void recursePrint(Node*, std::ostream&) const;

};
std::ostream& operator<<(std::ostream&, const LinkedList&);

#endif


