#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include "BinaryRepresentation.h"
#include "PrintVisual.h"
using namespace std;

int main (int argc, char * argv[])
{
    cout << "- First we will initialize an \"int* i\" (pointer named \"i\" to an int ) " << endl;
    cout << "    to point to a \"new int(10)\"." << endl;
    cout << "- We write this as \"int* i = new int(10)\"" << endl;
    cout << "- The 'new' keyword will prompt a new integer object to be dynamically allocated" << endl;
    cout << "    on the freestore/heap" << endl;
    cout << "- The return value of \"new int(10)\" is the address of the newly created object" << endl;
    cout << "    on the heap" << endl;
    cout << "- We need to store this address so that we can interact with this " << endl;
    cout << "    unnamed region of memory" << endl;
    cout << "- So we initialize an int pointer (because the address will be to an int) " << endl;
    cout << "    to store the returned address" << endl;
    cout << "- A pointer is simply an object whose value is an address" << endl;
    cout << "    that points to another object in memory" << endl;
    cout << "- In this case, that is an unnamed integer object with the value 10" << endl;
    int *i = new int(10);
    vis::print(i, "i");
    cout << endl;
    return_to_continue();
    cout << "- The binary representation of the pointer object i's value in memory is" << endl;
    cout << brepf(&i, sizeof(int*), false) << endl;
    cout << "    or " << i << " in hexadecimal" << endl;
    cout << "- This value is the address of the object to which it points" << endl;
    cout << "- Note: the pointer object itself has an address; it is located at address " << endl;
    cout << "    " << &i << " in memory" << endl << endl;
    return_to_continue();
    cout << "- The binary representation of the value of the object " << endl;
    cout << "    being pointed to in memory is" << endl;
    cout << brepf(i, sizeof(int), false) << endl;
    cout << "    or " << *i << " in decimal" << endl << endl;
    return_to_continue();
    cout << "- When we want to access the object being pointed to, we must use the " << endl;
    cout << "    dereference operator to dereference the pointer" << endl;
    cout << "- We can dereference the int object pointed to by i in an expression " << endl;
    cout << "    by writing *i" << endl;
    cout << "- For example, \"cout << *i;\" would output the value stored in " << endl;
    cout << "    the object pointed to by i; in this case, that value is " << *i << endl;
    cout << "- If we use the int* i in an expression without dereferencing it, " << endl;
    cout << "    the value stored in i (the address to the object that it points to) " << endl;
    cout << "    will be used" << endl;
    cout << "- For example, \"cout << i;\" would output pointer's value: " << endl;
    cout << "    the address to the int object that we dynamically allocated " << endl;
    cout << "    on the freestore" << endl << endl;
    return_to_continue();
    cout << "- We are not restricted to a single pointer to an object" << endl;
    cout << "- We can create multiple pointers to an object in memory; " << endl;
    cout << "    however, when we do, we must manage that memory carefully" << endl << endl;
    return_to_continue();
    cout << "- Let's initialize an additional int* to the int object " << endl;
    cout << "    that we dynamically allocated on the freestore; let's call it j" << endl;
    cout << "- We write this as \"int* j = i;\"" << endl;
    int *j = i;
    cout << "- This causes both int* i and int* j to point to the int object that " << endl;
    cout << "    we dynamically allocated on the freestore earlier" << endl;
    vis::print(i, "i");
    cout << endl;
    vis::print(j, "j");
    cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
    cout << "- Notice that both int* objects have the same memory address as their value" << endl << endl;
    return_to_continue();
    cout << "- Considering that i and j both refer to the same object..." << endl;
    cout << "- If we dereference the object to which either points and update " << endl;
    cout << "    the value stored in that object, the changes will be visible when we access " << endl;
    cout << "    the object indirectly through i or j" << endl;
    cout << "- For instance, let's execute the statement \"*i = 11;\"" << endl;
    *i = 11;
    vis::print(i, "i");
    cout << endl;
    vis::print(j, "j");
    cout << endl;
    cout << "- Pointers provide one means to access objects indirectly" << endl;
    return_to_continue();
    cout << "- We have to be careful when we access objects allocated on the freestore" << endl;
    cout << "    through pointers..." << endl;
    cout << "- We are responsible for managing the memory allocated to the freestore objects" << endl;
    cout << "- Considering we only have a finite amount of freestore space allocated " << endl;
    cout << "    to our program by the operating system" << endl;
    cout << "- We need to tell the run-time system when we are done using a freestore object " << endl;
    cout << "    so that we can reclaim its memory" << endl;
    cout << "- Calling delete on a pointer (e.x., \"delete i;\") tells the run-time system " << endl;
    cout << "    that the memory at the address that it points to " << endl;
    cout << "    can be freed for something else." << endl;
    return_to_continue();
    cout << "- If we assign the int* object named i a new address, let's say a new int(7), " << endl;
    cout << "    notice that we can now only access the object located at the old address " << endl;
    cout << "    through our int* object named j" << endl;
    i = new int(7);
    vis::print(i, "i");
    cout << endl;
    vis::print(j, "j");
    cout << endl;
    cout << "- If we assign the value of the int* object named i with another value, " << endl;
    cout << "    and if we make this assignment before " << endl;
    cout << "    calling delete on the pointer's old value..." << endl;
    cout << "- In this situation, we would not have any means to access " << endl;
    cout << "    the address associated with the dynamically allocated " << endl;
    cout << "    freestore object that we created earlier" << endl;
    cout << "- Consequently, we would not be able to delete that object since " << endl;
    cout << "    we would no longer know where it resided in memory" << endl;
    cout << "- This would result in a memory leak, as the memory allocated " << endl;
    cout << "    for the freestore objects could never be reclaimed" << endl;
    cout << "- This is because we wouldn't know where those objects resided" << endl;
    cout << "- If this happens repeatedly in our program for " << endl;
    cout << "    many dynamically allocated objects, our program will eventually " << endl;
    cout << "    run out of memory" << endl;
    return_to_continue();
    cout << "- Let's tell the run-time system to release the memory associated with " << endl;
    cout << "    the object pointed to by i" << endl;
    cout << "- We can do this by writing \"delete i;\"" << endl;
    cout << "- My next line of code will do just that..." << endl;
    delete i;
    cout << "- At this point, the dynamically allocated int object pointed to by i " << endl;
    cout << "    has been \"removed from the freestore\"" << endl;
    cout << "- Most compiler implementations do not \"zero-out\" " << endl;
    cout << "    the memory at these locations" << endl;
    cout << "- Therefore, the value that was stored in the reclaimed objects " << endl;
    cout << "    can remain accessible for sometime" << endl;
    cout << "- On some implementations, an exception is thrown " << endl;
    cout << "    if you try to dereference a pointer to an object that has been " << endl;
    cout << "    \"removed from the freestore\"" << endl;
    cout << "- On other implementations, you maybe able to dereference the pointer " << endl;
    cout << "    to the \"deleted\" object, accessing the value that had been " << endl;
    cout << "    stored in the object, but its value is unpredictable since" << endl;
    cout << "    updated by another thread or program." << endl;
    vis::print(i, "i");
    cout << endl;
    cout << "- You maybe able to access that value for sometime; eventually, that memory " << endl;
    cout << "    will be reclaimed and associated with another object" << endl;
    cout << "- Meaning you will no longer be able to access the \"old\" value..." << endl;
    cout << "- This can cause problems in your program, especially if you've forgotten " << endl;
    cout << "    that a freestore object had been \"deleted\"" << endl;
    return_to_continue();
    cout << "- Due to these reasons, it is normally good practice to assign " << endl;
    cout << "    a pointer to an object \"removed from the freestore\" the value nullptr, " << endl;
    cout << "    i.e., zero" << endl;
    cout << "- The next line will execute the statement \"i = nullptr\"" << endl;
    i = nullptr;
    cout << "- Trying to dereference a pointer object with the value nullptr will likely " << endl;
    cout << "    cause a segmentation fault..." << endl;
    cout << "- However, assigning a pointer nullptr provides a means for us to check whether" << endl;
    cout << "    a pointer points to a \"valid\" memory address" << endl;
    cout << "- This allows us to perform conditional checks, such as \"if (i != nullptr)\" or" << endl;
    cout << "    \"if (i == nullptr)\", on the pointer and " << endl;
    cout << "    take an appropriate action depending on the result" << endl;
    return_to_continue();
    cout << "- Assigning the pointer nullptr is also beneficial when it comes to \"deleting\"" << endl;
    cout << "    dynamically allocated freestore objects" << endl;
    cout << "- If you pass the delete function a pointer to an object that " << endl;
    cout << "    has already been \"deleted\", standard compliant implementations " << endl;
    cout << "    will throw an exception" << endl;
    cout << "- For instance, if you forget that you've \"deleted\" the freestore object " << endl;
    cout << "    pointed to by a pointer and try to \"delete\" that object again, " << endl;
    cout << "    you'll likely be confronted with an exception" << endl;
    cout << "- If you pass the delete function a pointer whose value is the nullptr, " << endl;
    cout << "    most implementations will not produce an error" << endl;
    return_to_continue();
    cout << "- The potential problems that can arise from multiple pointers " << endl;
    cout << "    pointing to the same object on the freestore will be illustrated" << endl;
    cout << "- Let's assign \"i = j;\"; that is, have i and j both " << endl;
    cout << "    point to the same object on the freestore" << endl;
    i = j;
    vis::print(i, "i");
    cout << endl;
    vis::print(j, "j");
    cout << endl;
    cout << "- If I call delete on the int* i and set its value to the nullptr, " << endl;
    cout << "    notice that int* j will continue point to the \"deleted\" object" << endl;
    cout << "- Moreover, that the object to be reclaimed by the run-time system " << endl;
    cout << "    will remain accessible through j until that memory at that location is reused" << endl;
    delete i;
    i = nullptr;
    std::ostringstream os; os << (&i); std::string address1 = os.str(); os.str(""); os.clear();
    vis::boxstr("0", address1, "i");
    cout << endl;
    vis::print(j, "j");
    cout << endl;
    cout << "- To avoid attempts to access the \"deleted\" freestore object, " << endl;
    cout << "    I will go ahead and assign nullptr to j" << endl;
    j = nullptr;
    os << (&j); std::string address2 = os.str(); os.str(""); os.clear();
    vis::boxstr("0", address1, "i");
    cout << endl;
    vis::boxstr("0", address2, "j");
    cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
    cout << "- You really need to be conscientious as to which " << endl;
    cout << "    pointers point to what objects..." << endl;
    cout << "- So that you do not inadvertently introduce dangling pointers into your program" << endl;
    return_to_continue();

}
