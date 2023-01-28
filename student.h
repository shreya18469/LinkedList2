#ifndef	STUDENT_H
#define	STUDENT_H
#include <iostream>

using namespace std;

class Student{
 public:
  //properties of a student
  char Fname[20];
  char Lname[20];
  float	gpa;
  int id;
  //methods
  void setStudent(char firstName[20], char lastName[20], float gpa, int id);
  void print();
  int getID();
  float getGPA();
};
#endif
