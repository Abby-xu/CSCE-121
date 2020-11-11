#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    cout << endl << "Linked list print (traversal) lab" << endl;
	LinkedList ll("Test List");
	ll.make_test_list();
	// fills with { 7, 3, 12 }

	cout << ll.get_name() << endl;
	ll.make_test_list();
	ll.set_name("My List");
	cout << ll.get_name() << endl;

	cout << endl << "ll.print('\\t');" << endl;
	ll.print('\t');
	cout << endl << "ll.print('\\n');" << endl;
	ll.print('\n');


}