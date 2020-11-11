#include <iostream>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node() : val(0), next(nullptr) {} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(int num) : val(num), next(nullptr) {}
