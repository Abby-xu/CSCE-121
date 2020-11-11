#ifndef SCLL_H
#define SCLL_H

#include <iostream>
#include "Node.h"

template <typename T>
class SortedCircularList {
  Node<T>* head;
  Node<T>* tail;
public:
  SortedCircularList() : head(nullptr), tail(nullptr) {}
  void print(std::ostream& out=std::cout) const;
  void printHands(std::ostream& out=std::cout) const;
  // insert val into a sorted circular list
  void insertValue(const T& val);
};

// print function
template <typename T>
void SortedCircularList<T>::print(std::ostream& out) const {
   Node<T>* current=head;
   if (current!=nullptr) {
      out<<current->data<<" ";
      while(current->next != head)
   {
         current = current->next;
         out<<current->data<<" ";
      }
   }
}

// WRITE THIS FUNCTION
template <typename T>
void SortedCircularList<T>::printHands(std::ostream& out) const {
  /* write your code here. This is the only file you should turn in. */
  Node<T>* curr = head;
  do {
    for (int i = 0; i < 4; i++) {
      out << curr -> data << " ";
      if(curr -> next == head)
        break;      
      curr = curr -> next;
    }
    out << std::endl;
  }while(curr -> next != head);
}

// insert function
template <typename T>
void SortedCircularList<T>::insertValue(const T& val)  {
  Node<T>* current= new Node(val);
  if (head == nullptr){
    head = current;
    tail = head;
  }else{
    current ->next = head;
    tail->next = current;
    tail = current;
  }

}

#endif