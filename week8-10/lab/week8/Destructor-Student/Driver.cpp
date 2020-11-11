#include <iostream>
#include "LinkedList.h"
using namespace std;

void generateList();

int main()
{
    LinkedList ll_one("Linked List one");
    int num = 0;
    for (int i = 15; i < 20; ++i) {
        ll_one.insertFront(i);
    }
    cout << "Outputting Linked List one..." << endl;
    cout << ll_one << endl;

    //FIXME: Call your clear function here
    ll_one.clear();

    cout << "Outputting Linked List one..." << endl;
    cout << ll_one << endl << endl;

    // FIXME: uncomment below after creating your destructor
    generateList();
    // cout << "Back in main function..." << endl;

    // system("pause");  // uncomment for VS; comment for vocareum submission
}

void generateList()
{
    cout << "Creating linked list inside a function..." << endl;
    LinkedList ll_two("Linked List two");
    int num = 0;
    for (unsigned int i = 25; i < 30; ++i) {
        ll_two.insertFront(i);
    }
    cout << "Outputting Linked List two..." << endl;
    cout << ll_two << endl;
    cout << "Returning from function..." << endl;
}