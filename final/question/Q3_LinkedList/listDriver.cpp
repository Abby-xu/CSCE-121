// listDriver.cpp
#include <iostream>
#include <string>
#include "SCLL.h"

using std::cout, std::endl;

int main()
{
   // Define a SortedCircularList object.
   SortedCircularList<int> list;

   // Store the integer objects in the list.
   // for (int i = 1; i < 53; i++) {
   //    list.insertValue(i);
   // }
   list.insertValue(1);
   list.insertValue(2);
   list.insertValue(3);
   list.insertValue(4);
   list.insertValue(5);
   list.insertValue(6);
   list.insertValue(7);
   list.insertValue(8);
   list.insertValue(9);
   list.insertValue(10);
   list.insertValue(11);
   list.insertValue(12);
   list.insertValue(13);


   // Display the values in the list.
   cout << "Here is the initial list:\n";
   list.print();
   cout << endl;

   // insert 99
   list.insertValue(99);
   cout << "Here is the list after inserting 99:\n";
   list.print();
   cout << endl << "Players hands: \n";
   list.printHands();  

   return 0;
} 
