#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void add(Node* input, char firstName[20], char lastName[20], float gpa, int id);
void print(Node* next);
void deleteStu(Node* &head, Node* current, Node* prev, int input);;

Node* head = NULL;
int main(){
  char input[10];
  bool stillPlaying = true;
  while(stillPlaying == true){
    cout << "Enter a command." << endl;
    cin >> input;
    if (strcmp(input, "ADD") == 0){
       int id;
      float gpa;
      char firstName[20];
      char lastName[20];
      cout << "What is their first name?" << endl;
      cin >> firstName;
      cout << "What is their last name?" << endl;
      cin >> lastName;
      cout << "What is their student ID?" << endl;
      cin >> id;
      cout << "What is their GPA?" << endl;
      cin >> gpa;
      add(head, firstName, lastName, gpa, id);
    }else if (strcmp(input, "PRINT") == 0){
      print(head);
      cout << endl;
    } else if (strcmp(input, "DELETE") == 0) {
      int input;
      cout << "What is the student's ID?" << endl;
      cin >> input;
      deleteStu(head, head, head, input);
    }
  }
  return 0;
}

void add(Node* input, char firstName[20], char lastName[20], float gpa, int id){
  if (head == NULL){
    head = new Node(new Student());
    head->getStudent()->setStudent(firstName, lastName, gpa, id);
    return;
  } else if(input->getNext() != NULL) {
    add(input->getNext(), firstName, lastName, gpa, id);
  }
  input->setNext(new Node(new Student));
input->getNext()->getStudent()->setStudent(firstName, lastName, gpa, id);
  return;
}

void print(Node* next){
  if (next == head){
    cout << "List:";
  }
  if (next != NULL){
    next->getStudent()->print();
    print(next->getNext());
  }
}

void deleteStu(Node* &head, Node* current, Node* prev, int input){
  if (current->getStudent()->getID() == input){
    if (prev == NULL){
      prev->setNext(current->getNext());
    } else {
      head = current->getNext();
    }
    delete current;
  } else {
    if(current->getNext() != NULL){
      deleteStu(head, current->getNext(), current, input);
    } else {
      cout << "Sorry, no ID matches" << endl;
    }
  }
}
