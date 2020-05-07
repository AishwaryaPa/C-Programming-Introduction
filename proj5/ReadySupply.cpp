/*****************************************
 ** File:    ReadySupply.cpp
 ** Project: CMSC 202 Project 4, Fall 2016
 ** Author:  Aishwarya Panchumarty
 ** Date:    12/01/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 **
 ** This file contains code for ReadySupply Class . 
 ** This class is designed to load files into vectors. 
 ** Uses the proj5_cargo.txt to build Items and 
 ** Persons. Uses proj5_ships.txt to build item ships 
 ** and person ships. After ships are “built” they are 
 ** filled with the appropriate cargo: person ships 
 ** are filled with persons (only) and item ships are 
 ** filled with items (only)
 **
 ***********************************************/
#include "ReadySupply.h"

// ReadySupply() Default Constructor
// Does nothing. But here for safety reasons
ReadySupply::ReadySupply(){
  m_shipFile = "proj5_ship.txt";
  m_cargoFile = "proj5_cargo.txt";
}

// ReadySupply() Overloaded constructor
// Creates an objects of ReadySupply. Immediately loads ships and 
// cargo so they can be accessed by ManageShips class in main
ReadySupply::ReadySupply(string shipFile, string cargoFile){
  m_shipFile = shipFile;
  m_cargoFile = cargoFile;
  LoadCargo();
  LoadShips();
}

// LoadShips
// Populates two vectors: One that holds the names of ships
// carrying people and another that holds the names of ships
// carrying items
void ReadySupply::LoadShips(){
  string character, name;
  double capacity;
  fstream inputStream;
  inputStream.open(m_shipFile.c_str()); 
  while (inputStream >> character){
    // Populate m_itemShips with objects of Spaceships. 
    // This vector specifically keeps track of ships holding only items
    if (character == "Item"){
      inputStream >> name >> capacity;
      Spaceship<Item> itemShip(name, character, capacity);
      m_itemShips.push_back(itemShip);
    }
    
    // Populate m_personShips with objects of Spaceships.
    // This vector specifically keeps track of ships holding only people 
    else if (character == "Person"){
      inputStream >> name >> capacity;
      Spaceship<Person> personShip(name, character, capacity);
      m_personShips.push_back(personShip);
    }
  }
  inputStream.close(); 
}

// LoadCargo
// Populates two vectos: one that holds the objects of items 
// and another that holds objects of people
void ReadySupply::LoadCargo(){
  string character, fName, lName;
  int age, id;
  double weight;
  fstream inputStream;
  inputStream.open(m_cargoFile.c_str()); 
  while (inputStream >> character){
    // Populates m_itemCargo with only objects of items
    if (character == "i"){
      inputStream >> id >> fName >> weight;
      Item item1(id, fName, weight);
      m_itemCargo.push_back(item1);
    }

    // populates m_personCargo with only objects of person
    else if (character == "p"){
      inputStream >> fName >> lName >> weight >> age >> id;
      Person person1(fName, lName, weight, age, id);
      m_personCargo.push_back(person1);
    }
  }
  inputStream.close();
}

// GetItemShips
// Returns the vectors that is populated with ships caryying items
vector< Spaceship<Item> > ReadySupply::GetItemShips(){
  return m_itemShips;  
}

// GetPersonShips
// Returns a vector that is populated with  person ships
vector< Spaceship<Person> > ReadySupply::GetPersonShips(){
  return m_personShips;
}

// GetItemCargo
// Returns a vector of all items
vector< Item > ReadySupply::GetItemCargo(){
  return m_itemCargo; 
}

// GetPersonCargo
// Returns a vector of all people (person)
vector< Person > ReadySupply::GetPersonCargo(){
  return  m_personCargo;
}


