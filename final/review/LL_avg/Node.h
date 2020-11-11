#ifndef NODE
#define NODE

struct Node {
	int val;
	Node* next; 
	// remember to check if the ll is a simple direction or doubnle direction
	// for simple direction only has one pointer named next in ll
	// for double direction has two pointers named next and prev in ll

	// Default constructor
	Node();
	Node(int num); // remember to initialize next to nullptr
};

// any overloaded operator has to be assigned outside the definition of a struct or class

#endif