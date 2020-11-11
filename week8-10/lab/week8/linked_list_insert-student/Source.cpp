#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList ll("Test List");

    ll.print_head();
    ll.print_tail();
    ll.print();



    //system("pause");
    cout << endl;

	Node* new_node = new Node(10);
	ll.insert_back(new_node);
	ll.print(); ll.print_head(); ll.print_tail(); cout << endl;
 
	Node* new_node2 = new Node(11);
	ll.insert_back(new_node2);
	ll.print(); ll.print_head(); ll.print_tail(); cout << endl;

	Node* new_node3 = new Node(12);
	ll.insert_back(new_node3);
	ll.print(); ll.print_head(); ll.print_tail(); cout << endl;

}

///Users/abby/Desktop/2020_summer/CSCE121/Lab/week8/linked_list_insert-student