#include "student.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

void Student::setStudent(char firstName2[20], char lastName2[20], float gpa2, int id2){ //set student properties
  strcpy(Fname, firstName2);
  strcpy(Lname, lastName2);
  gpa = gpa2;
  id = id2;
}
void Student::print(){ //print student
  cout << " Name: " << Fname << " " << Lname << " " << "ID: " << id << " " << "GPA: " << setprecision(2) << fixed <<  gpa;
}
int Student::getID(){ //return the ID
  return id;
}
float Student::getGPA(){ //return the GPA
  return gpa;
}
