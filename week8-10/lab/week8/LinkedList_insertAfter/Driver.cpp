#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList ll("Test List");
    ll.insert_front(10);
    ll.insert_back(12);
    cout << "Outputting Test List..." << endl;
    cout << ll << endl;
    cout << "Printing Test List head..." << endl; ll.print_head();
    cout << "Printing Test List tail:" << endl; ll.print_tail();
    cout << endl;

    ll.insert_after(10, 11);
	cout << "Outputting Test List..." << endl;
	cout << ll << endl;
	cout << "Printing Test List head..." << endl; ll.print_head();
	cout << "Printing Test List tail:" << endl; ll.print_tail();
	cout << endl;

    return 0;
}