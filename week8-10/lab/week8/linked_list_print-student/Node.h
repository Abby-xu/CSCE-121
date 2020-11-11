#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node
{
	int value;
	Node* next;
	Node(int value) : value(value), next(nullptr) {}
	Node() : value(0), next(nullptr) {}
};

#endif