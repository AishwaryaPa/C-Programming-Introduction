/*****************************************
 ** File:    Item.cpp
 ** Project: CMSC 202 Project 5, Fall 2016
 ** Author:  Aishwarya Panchumarty
 ** Date:    12/01/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 **
 ** This file contains code for defining cargo 
 ** items. Used in item ships in ReadySupply.cpp
 **
 ****************************************/
#include "Item.h"

// Item()
// Default contructor. User for safety reasons
Item::Item(){
  m_id = 67246;
  m_name = "Rovers_47";
  m_weight = 606845.60;
}

// Item() constructor
// Creates an object of item. Takes three 
// arguements: id, name, and weight
Item::Item(int inId, string inName, float inWeight){
  m_id = inId;
  m_name = inName;
  m_weight = inWeight;
}

// Accessors for Item
// return the appropriate member varibales when needed
int Item::GetId() const{
  return m_id;
}

string Item::GetName() const{
  return m_name;
}

float Item::GetWeight() const{
  return m_weight;
}

// ToString()
// Returns a properly formatted string of all information about the item
string Item::ToString() const{
  // format a string containg information about name, id, and weight
  ostringstream os;
  os << "Item Name: " << m_name
     << "\nID: " << m_id 
     << "\nWeight: " << fixed << setprecision (2) << m_weight << endl;
  return os.str();
}

