/*****************************************
 ** File:    Spaceship.h
 ** Project: CMSC 202 Project 5, Fall 2016
 ** Author:  Aishwarya Panchumarty
 ** Date:    12/01/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 **
 ** This file contains code for defining spaceships.
 ** Templated class. Used to build either item ships 
 ** or personnel ships. Also has overloaded operators 
 ** to compare templated ships
 **
 ****************************************/
#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Item.h"
#include "Person.h"

#include <vector>
#include <sstream> //Used to concatenate a string that includes numbers
#include <iomanip> //Used to format weights to make more sense
using namespace std;

template <class T>
class Spaceship
{
 public:
  //Name: Spaceship
  //Default constructor 
  Spaceship();
  
  //Name: Spaceship(string, string, double) Overloaded constructor.
  //Precondition: Requires ship file has been loaded
  //Postcondition: Builds a new templated ship
  Spaceship(string inName, string inType, double inCapacity);

  //Name: GetCargo
  //Precondition: Requires that the ship's cargo has been populated
  //Postcondition: Templated accessor for this ship's cargo
  vector<T> GetCargo() const;
  
  //Name: GetCargoAt
  //Precondition: Requires that the ship's cargo has been populated
  //Postcondition: Templated accessor for this ship's cargo at a specific location
  const T& GetCargoAt(int index) const;
 
 //Name: AddCargo
  //Precondition: Requires that the ships have been loaded
  //Postcondition: Adds an item into this ship
  void AddCargo(T inputObject);

  //Name: ToString
  //Precondition: Requires that the ships and cargo have been loaded
  //Postcondition: Used to output information about a specific ship
  string ToString() const;

  //Name: GetCapacity
  //Precondition: Requires that the ships have been loaded
  //Postcondition: Used to access the capacity of a ship
  double GetCapacity() const;
 
 //Name: GetName
  //Precondition: Requires that the ships have been loaded
  //Postcondition: Used to access the name of a ship
  string GetName() const;

  //Name: operator> (Overloaded) Both ships are templated!
  //Precondition: Requires two ships
  //Postcondition: Returns which ship heavier including cargo
  template <class U>
    bool operator>( Spaceship<U> &otherShip);

  //Name: operator< (Overloaded) Both ships are templated!
  //Precondition: Requires two ships
  //Postcondition: Returns which ship lighter including cargo
  template <class U>
    bool operator<( Spaceship<U> &otherShip);
  

private:
  string m_name;
  string m_type;
  double m_capacity;
  vector<T> m_cargo;	
};

//*************************************************************
// Spaceship()
// Default constructor. Used for safety reasons
template <class T>
Spaceship<T>::Spaceship(){
  m_name = "Supply1";
  m_type = "Item";
  m_capacity = 15000000;
}

// Spaceship(string, string, double) Overloaded constructor.
// Creates an object of a new templated ship. Can hold items or people.
template <class T>
Spaceship<T>::Spaceship(string inName, string inType, double inCapacity){
  m_name = inName;
  m_type = inType;
  m_capacity = inCapacity;
}

// GetCargo()
// A templated accessor fuction. Returns a vector containing 
// all the cargo of a specific ship. The cargo may be items 
// or people. 
template <class T>
vector<T> Spaceship<T>::GetCargo() const{
  return m_cargo;
}

// GetCargoAt()
// Templated accessor fucntion. Returns an element in the 
// m_cargo vector at a specific location for a specefic ship.
template <class T>
const T& Spaceship<T>::GetCargoAt(int index) const{
  return m_cargo[index];
}

// AddCargo()
// Adds cargo (items or people) into a m_cargo vector
// for a specific ship
template <class T>
void Spaceship<T>::AddCargo(T inputObject){
  m_cargo.push_back(inputObject);
}

// ToString()
// Returns a formatted string containing all the 
// information about a specific ship.
template <class T>
string Spaceship<T>::ToString() const{
  // format a string containg information about first name, last name, age, and weight
  double weight = 0.0;  // There is no member variable for ship's weight. Weight has to be calcuated
  if (m_cargo.size() > 0){
    for(unsigned int i = 0; i < m_cargo.size(); i++){
      weight = weight + m_cargo[i].GetWeight();
    }
  }
  ostringstream os;
  os << "Ship Type: " << m_type
     << "\nShip Name: " << m_name
     << "\nTotal Weight: " << fixed << setprecision (2) <<  weight
     << "\nTotal Capacity: " << fixed << setprecision (2) << m_capacity << endl;
  return os.str();   
}

// GetCapacity()
// Templated accessor fucntion that returns the capacity
// of a specific ship. This ship may hold people or item
template <class T>
double Spaceship<T>::GetCapacity() const{
  return m_capacity;
}

// GetName()
// Templated accessor fucntion that returns the name
// of a specific ship. This ship may hold people or item
template <class T>
string Spaceship<T>::GetName() const{
  return m_name;
}

// operator> (Overloaded) Both ships are templated!
// Compares two ships' (one is the object at which this function 
// is called and the other is given through the arguements) weight. 
// Weight is calcuated for both ships inside this function. Weight 
// is not a member variable. Returns true if the ship (the object 
// this function is called on) is heavier than the one given in 
// arguements. Otherwise false. 
template <class T>
template <class U>
bool Spaceship<T>::operator>( Spaceship<U> &otherShip){
  // first ship's weight. This ship is the object on which the this function is called
  double firstShipWeight = 0.0;
  if (m_cargo.size() > 0){
    for (unsigned int i = 0; i < m_cargo.size(); i++){
      firstShipWeight = firstShipWeight + m_cargo[i].GetWeight(); // add all the items' weight or people's weight
    }
  }

  // second ship's weight. This ship is given through the arguements
  double secondShipWeight = 0.0;
  vector<U>cargo = otherShip.GetCargo();
  if (cargo.size() > 0){
    for (unsigned int i = 0; i < cargo.size(); i++){
      secondShipWeight = secondShipWeight + cargo[i].GetWeight();  // add all the items' weight or people's weight
    }
  }

  if (firstShipWeight > secondShipWeight){
    return true;
  } 
  else{
    return false;
  }
}


// operator> (Overloaded) Both ships are templated!
// Compares two ships' (one is the object at which this function
// is called and the other is given through the arguements) weight.
// Weight is calcuated for both ships inside this function. Weight
// is not a member variable. Returns true if the ship (the object
// this function is called on) is lighter than the one given in
// arguements. Otherwise false.
template <class T>
template <class U>
bool Spaceship<T>::operator<( Spaceship<U> &otherShip){
  // first ship's weight. This ship is the object on which the this function is called
  double firstShipWeight = 0.0;
  if (m_cargo.size() > 0){
    for (unsigned int i = 0; i < m_cargo.size(); i++){
      firstShipWeight = firstShipWeight + m_cargo[i].GetWeight();  // add all the items' weight or people's weight
    }
  }

  // second ship's weight. This ship is given through the arguements
  double secondShipWeight = 0.0;
  vector<U>cargo = otherShip.GetCargo();
  if (cargo.size() > 0){
    for (unsigned int i = 0; i < cargo.size(); i++){
      secondShipWeight = secondShipWeight + cargo[i].GetWeight();  // add all the items' weight or people's weight
    }
  }

  if (firstShipWeight < secondShipWeight){
    return true;
  }
  else{
    return false;
  }
}

#endif
