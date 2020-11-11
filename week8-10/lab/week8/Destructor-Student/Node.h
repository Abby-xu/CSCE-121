#ifndef NODE_H
#define NODE_H
struct Node {
    Node(int i) : value(i), next(nullptr) {}
    Node() : value(0), next(nullptr) {}
    int value;
    Node* next;
};
#endif