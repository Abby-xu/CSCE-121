#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::LinkedList(string name) : head(nullptr), tail(nullptr), name(name) {}

void LinkedList::set_name(string name)
{
    this->name = name;
}

string LinkedList::get_name() const
{
    return name;
}

Node* LinkedList::get_head() const
{
    return head;
}

bool LinkedList::is_empty() const
{
    if (head == nullptr && tail == nullptr)
        return true;
    else
        return false;
}

void LinkedList::insert_front(int value)
{
    Node* newNode = new Node(value);
    newNode->next = head; // attach to list
    head = newNode;
    if (tail == nullptr) { // empty list
        tail = newNode; // only node is both head and tail
    }
}

void LinkedList::insert_back(int value)
{
    Node* newNode = new Node(value);
    if (tail != nullptr)
        tail->next = newNode; // attach to list
    tail = newNode;
    if (head == nullptr) { // empty list
        head = newNode; // only node is both head and tail
    }
}

void LinkedList::print_head(char c, ostream& os) const
{
    if (head != nullptr) {
        os << head->value << c;
    } else {
        os << "<Empty List>" << c;
    }
}

void LinkedList::print_tail(char c, ostream& os) const
{
    if (head != nullptr) {
        os << tail->value << c;
    } else {
        os << "<Empty List>" << c;
    }
}

ostream& operator<<(ostream& os, const LinkedList& ll)
{
    os << ll.get_name() << " {";
    Node* current = ll.get_head();
    if (current == nullptr) {
        os << " <Empty List>";
    }
    while (current != nullptr) {
        if (current != ll.get_head())
            cout << ",";
        cout << " " << current->value;
        current = current->next;
    }
    cout << " }";
    return os;
}

void LinkedList::makeTestList()
{
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

void LinkedList::log(const string& what) const
{
    std::cout << "[" << this << "] " << what << std::endl;
}

bool LinkedList::insert_after(int after_val, int insert_val) {
    if (head == nullptr) {
        return false;
    }
    else {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr -> value == after_val) {
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
