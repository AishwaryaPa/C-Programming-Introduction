/*****************************************
 ** File:    Person.cpp
 ** Project: CMSC 202 Project 4, Fall 2016
 ** Author:  Aishwarya Panchumarty
 ** Date:    12/01/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 **
 ** This file contains code for defining people 
 ** used in personnel ships.
 **
 ****************************************/
# include "Person.h"

// Person()
// Default contructor. Used for safety reasons
Person::Person(){
  m_id = 12;
  m_fName = "Dennis";
  m_lName = "Gutierrez";
  m_age = 89;
  m_weight = 345.0;
}

// Person() constructor
// Creates an object of person. Takes five
// arguements: first name, last name, weight,
// age, and weight
Person::Person(string infName, string inlName, double inWeight, int inAge, int inId){
  m_id = inId;
  m_fName = infName;
  m_lName = inlName;
  m_age = inAge;
  m_weight = inWeight;
}


// Accessors for Person
// return the appropriate member varibales when needed
int Person::GetId() const{
  return m_id;
}

string Person::GetFName() const{
  return m_fName;
}

string Person::GetLName() const{
  return m_lName;
}

int Person::GetAge() const{
  return m_age;
}

double Person::GetWeight() const{
  return m_weight;
}

// ToString()
// Returns a properly formatted string of all information about the person
string Person::ToString() const{
  // format a string containg information about first name, last name, age, and weight
  ostringstream os;
  os << "First Name: " << m_fName
     << "\nLast Name: " << m_lName
     << "\nAge: " << m_age 
     << "\nWeight: " << m_weight << endl;
  return os.str();
}
