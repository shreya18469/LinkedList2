#include <iostream>
#include <cstring>
#include "student.h"

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
 public:
  Node(Student* studentNew);
  ~Node();
  Student* getStudent();
  void setNext(Node*);
  Node* getNext();
 private:
  Student* student;
  Node* next;
};
#endif
