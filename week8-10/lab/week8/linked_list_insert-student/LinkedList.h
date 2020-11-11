#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include "Node.h"

class LinkedList {
    Node* head;
    Node* tail;
    std::string name;

public:
    LinkedList();
    LinkedList(std::string);

    bool is_empty();

    void insert_front(Node * n);
    void insert_back(Node * n);

    void setName(std::string);
    std::string getName() const;

    void makeTestList();

    void print(char = ' ', std::ostream& os = std::cout);
    void print_head(char = '\n', std::ostream& os = std::cout);
    void print_tail(char = '\n', std::ostream& os = std::cout);

};

#endif