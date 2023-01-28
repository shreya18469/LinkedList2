#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"

using namespace std;
//function prototypes
void add(Node* &input, char firstName[20], char lastName[20], float gpa, int id);
void print(Node* next);
void deleteStu(Node* &head, Node* current, Node* prev, int input);;
void avgGPA(Node* current, float avg, int num);

Node* head = NULL;
int main(){
  char input[10];
  bool stillPlaying = true;
  while(stillPlaying == true){
    cout << "Enter a command(ADD, PRINT, DELETE, AVERAGE, or QUIT)" << endl;
    cin >> input;
    for (int i = 0; i < 10; i++){ // convert input to uppercase
    input[i] =  toupper(input[i]);
  }
    if (strcmp(input, "ADD") == 0){ //if user wants to add
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
    }else if (strcmp(input, "PRINT") == 0){ //if user wants to print
      print(head);
      cout << endl;
    } else if (strcmp(input, "DELETE") == 0) { //if user wants to delete
      int input;
      cout << "What is the student's ID?" << endl;
      cin >> input;
      deleteStu(head, head, head, input);
    } else if (strcmp(input, "AVERAGE") == 0){ //if user wants to average
      float total;
      float count = 0;
      avgGPA(head, total, count);
    } else if (strcmp(input, "QUIT") == 0){ //if user wants to quit
      stillPlaying = false;
    } else {
      cout << "Sorry, invalid command." << endl;
    }
  }
  return 0;
}

void add(Node* &current, char firstName[20], char lastName[20], float gpa, int id){ //add a new student to the list 
  if(current == NULL){//if we are adding the first student
    current = new Node(new Student());
    current->getStudent()->setStudent(firstName, lastName, gpa, id);//set the students properties
    return;
  } else if(current->getNext() == NULL){
    Student* s = new Student; 
    Node* n = new Node(s); //create a new node to add
    s->setStudent(firstName, lastName, gpa, id);
    if(current->getStudent()->getID() > s->getID()){ //if new student has lower ID than existing students
      n->setNext(current);
      current = n;
    }
    else{
      current->setNext(n);
    }
    return;
  }
  if(current->getNext()->getStudent()->getID() > id){//If next ID is greater than new students
    Student* s = new Student;
    Node* n = new Node(s); //create new node
    s->setStudent(firstName, lastName, gpa, id);
    n->setNext(current->getNext());
    current->setNext(n);
    return;
  }
  Node* next = current->getNext();
  add(next, firstName, lastName, gpa, id); //using recursion
}
void print(Node* next){//Print all students
  if(next == head){
    cout << "List:";
  }
  if (head == NULL){
    return;
  }
  if(next != NULL){
    next->getStudent()->print();
    print(next->getNext()); //using recursion
  }
}


void deleteStu(Node* &head, Node* current, Node* prev, int input){ //delete a student by ID
  if (head == NULL){
    cout << "List is empty" << endl;
    return;
  }
  if (current->getStudent()->getID() == input){ //if current student matches ID input
    if (current == head){
      head = current->getNext(); 
    } else {
      //head = current->getNext();
      prev->setNext(current->getNext()); 
    }
    delete current; //delete current node
  } else {
    if(current->getNext() != NULL){
      deleteStu(head, current->getNext(), current, input); //using recursion
    } else {
      cout << "Sorry, no ID matches" << endl;
    }
  }
}

void avgGPA(Node* current, float avg, int num){ //take the average of the GPAs 
  if (current == NULL){ //check if reached end of list
    cout << "Average GPA: " << fixed << setprecision(2) << avg/num << endl; //calculate the average 
    return;
  }
  avg += current->getStudent()->getGPA(); //add current GPA to running total 
  num++; //increment number of students count
  avgGPA(current->getNext(), avg, num); //using recursion to continue the processs until all students are processed
}
