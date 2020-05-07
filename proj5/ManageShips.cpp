/*****************************************
 ** File:    ManageShips.cpp
 ** Project: CMSC 202 Project 4, Fall 2017
 ** Author:  Aishwarya Panchumarty
 ** Date:    12/01/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 **
 ** This file contains code for ManageShips class. This class manages 
 ** a majority of the functions. After everything is loaded and some 
 ** calculations are being done, this class manages the various 
 ** aspects including getting the Heaviest and Lightest ships 
 ** (regardless if they are person or item ships), Oldest and Youngest 
 ** person, and Heaviest and Lightest items. Also can output any person 
 ** or item not loaded into a ship due to capacity limitations. Finally, 
 ** can write an output file that contains each ship name and then each 
 ** of the cargo.
 **
 ***********************************************/
# include "ManageShips.h"
const char FILENAME[17] = "proj5_output.txt";

// ManageShips() constructor
// Takes in all the data from ReadySupply in form of vectors.
// These vectors are used in all of the functions in this 
// class to calcuate what the user needs. LoadItemShip()
// and LoadPersonShip() must be immediately called for all
// the function to work
ManageShips::ManageShips(vector< Spaceship <Item> > itemShip,
	    vector< Spaceship <Person> > personShip,
	    vector< Item > itemCargo,
			 vector< Person > personCargo){

  m_itemShips = itemShip;
  m_personShips = personShip;
  m_items = itemCargo;
  m_person = personCargo;

  cout <<" Item Ships Loaded: " << m_itemShips.size()  << endl;
  cout <<" Person Ships Loaded: " << m_personShips.size()  << endl;
  cout <<" Persons Loaded:  " << m_person.size() << endl;
  cout <<" Items Loaded: " << m_items.size()  << endl;

  LoadItemShip();
  LoadPersonShip();
}

// LoadItemShip
// Each ship is loaded with items until it reaches its capacity 
// (weight limit). Every item is loaded on the first avaliable 
// ship meaning that even ships that already have been loaded 
// will be checked for avaliability. It is possible that some 
// items may not be loaded in any ships
void ManageShips::LoadItemShip(){
  unsigned int shipIndex = 0, itemIndex = 0;
  vector<double> totalWeight (m_itemShips.size()); // keeps track of each ships' weight. 
  vector<Item> unloadedItems; // keep track of unloaded items for DisplayItemsLeft();

  // keeps going until every item is tried to be put inside a ship
  while (itemIndex != m_items.size()){ 
 
    bool exitWhileLoop = false;
    while(exitWhileLoop == false){

      if (shipIndex < m_itemShips.size()){ // make sure there are ships avaliable to put the item inside

	if(totalWeight[shipIndex] + m_items[itemIndex].GetWeight() < m_itemShips[shipIndex].GetCapacity()){
	  m_itemShips[shipIndex].AddCargo(m_items[itemIndex]); // Adds cargo in the ship by acessing the vector m_cargo in Spaceship.h
	  totalWeight[shipIndex] = totalWeight[shipIndex] + m_items[itemIndex].GetWeight();
	  exitWhileLoop = true;
	  shipIndex = 0;
	}

	else{
	  shipIndex = shipIndex + 1;
	}

      }

      else{ // exit if the item could not be put inside any ship
	unloadedItems.push_back(m_items[itemIndex]); 
	exitWhileLoop = true;
	shipIndex = 0; // Make sure to check for the first avaliable ship 
      }

    }
    itemIndex = itemIndex + 1;
  }

  m_items = unloadedItems; // only keep track of unloaded items for DisplayItemLeft()

}

// LoadPersonShip
// Loads people into each ship until the ship reaches capacity
// (limited by number of people it can hold). It is possible 
// that there may not be enough ships to hold all people.
void ManageShips::LoadPersonShip(){
  unsigned int shipIndex = 0;
  unsigned int personIndex = 0;

  // keep going until every ship is loaded or every person is tried to
  // be put inside a ship and stop if there are no more ships or people
  while (shipIndex != m_personShips.size() and personIndex != m_person.size()){ 
    int totalPeople = 0;
    bool stopAddingPeople = false; 

    while(stopAddingPeople == false and personIndex != m_person.size()){

      if(totalPeople <= (m_personShips[shipIndex].GetCapacity()-1)){ // check if ship has enough capacity to hold the person

        m_personShips[shipIndex].AddCargo(m_person[personIndex]); // Adds cargo in the ship by acessing the vector m_cargo in Spaceship.h
	totalPeople = totalPeople + 1;
        personIndex = personIndex + 1; // load the next person
      }

      else{
        stopAddingPeople = true;
        shipIndex = shipIndex + 1; // go to next ship
      }
    }
  }

}

// DisplayItemLeft()
// Outputs all the unloaded items. At the end of LoadItemShips(), m_items is 
// updated with only unloaded items. 
void ManageShips::DisplayItemLeft(){
  if (m_items.size() > 0){ // m_items now only holds the unloaded items. This vector should have been updated at the end of LoadItemsShips()
    for (unsigned int i = 0; i < m_items.size(); i++){
      cout << "Item " << i << "- Name: " << m_items[i].GetName() << " - Weight: " << m_items[i].GetWeight()<< endl;
    }
  }
  else{
    cout <<"None" << endl; // Display "None" if no items were left behind
  }
}


// DisplayPersonLeft()
// Outputs all the people not loaded. First calcuates total capacity of all
// ships. Since capacity is limited by number of people a ship can hold, the 
// capacity is therefore a whole number. Then turns totalCapacity into an 
// integer and accesses the people not loaded by indexing them from m_person
void ManageShips::DisplayPersonLeft(){
  double totalCapacity = 0.0; // number of people all ships can hold
  for (unsigned int i = 0; i < m_personShips.size(); i++){
    totalCapacity = totalCapacity + m_personShips[i].GetCapacity();
  }

  int personIndex = static_cast<int>(totalCapacity);
  if (personIndex >= 0){ // index must be greater than zero so it cannot accesses out of bounds
    int counter = 1; // for printing the number for each person
    while (personIndex != m_person.size()){
      cout << "Person "  << counter  << " - Name: "  << m_person[personIndex].GetFName() << endl;
      personIndex = personIndex + 1;
      counter = counter + 1;
    }
  }
}

// OutputShips()
// Writes out all ships and their cargo to a specific output file
// Output file will always be proj5_output.txt
void ManageShips::OutputShips(){
  ofstream outstream;
  outstream.open(FILENAME); 
  // Write the name of the ship and underneath it, write all the cargo inside of it
  // First writes out the data about personnel ships. 
  outstream << "**Personnel Ships**" << endl;
  for (unsigned int i = 0; i < m_personShips.size(); i++){
    outstream << "**Ship Name: "  << m_personShips[i].GetName() <<"**" << endl;
    cout <<"**Ship Name: " << m_personShips[i].GetName() << "**" << endl;
    vector <Person> cargo = m_personShips[i].GetCargo();
    if (cargo.size() > 0){
      for (unsigned int j = 0; j < cargo.size(); j++){
	outstream << cargo[j].GetFName() << " " << cargo[j].GetLName()<< endl;
	cout << cargo[j].GetFName() << " " << cargo[j].GetLName() << endl;
      }
    }

    else{
      outstream << "Empty" << endl;
      cout << "Empty" << endl;
    }

    cout << " " << endl;
  }

  // Then writes about the item ships
  outstream << "**Item Ships**" << endl;
  for (unsigned int i = 0; i < m_itemShips.size(); i++){
    outstream << "**Ship Name: " << m_itemShips[i].GetName() <<"**" <<endl;
    cout <<"**Ship Name: " << m_itemShips[i].GetName() << "**" << endl;
    vector <Item> cargo = m_itemShips[i].GetCargo();
    if(cargo.size() > 0){
      for (unsigned int j = 0; j < cargo.size(); j++){
	outstream << cargo[j].GetName() << endl;
	cout << cargo[j].GetName() << endl;
      }
    }

    else{
      outstream << "Empty" << endl;
      cout << "Empty" << endl;
    }
    cout << " " << endl;
  }
  outstream.close();
}

// GetHeaviestShip()
// Uses the overloaded operator in Spaceship.h file to compare the ships'
// weight. Keeps track of the heaviest ship by using a pointer. At the 
// end, heaviest ship's information is returned by calling its ToString()
// function
string ManageShips::GetHeaviestShip(){
  Spaceship<Item> *itemShipPtr = &m_itemShips[0]; // pointer that keeps track of heaviest item ship' weight 
  for (unsigned int i = 0; i < m_itemShips.size(); i++){
    if (m_itemShips[i] > *itemShipPtr){
      itemShipPtr = &m_itemShips[i];// update pointer to point at item ship holding the most weight
    }
  }

  Spaceship<Person> *personShipPtr = &m_personShips[0];  // pointer that keeps track of heaviest person ship's weight
  for (unsigned int i = 0; i < m_personShips.size(); i++){
    if (m_personShips[i] > *personShipPtr){
      personShipPtr = &m_personShips[i]; // update pointer to point at person ship holding the most weight
    }
  }

  if (*itemShipPtr > *personShipPtr){ // finally compare the heaviest person ship and heaviest person ship
    return itemShipPtr->ToString();
  }

  else{
    return personShipPtr->ToString();
  }
}

// GetLightestShip()
// Uses the overloaded operator in Spaceship.h file to compare the ships'
// weight. Keeps track of the lightest ship by using a pointer. At the
// end, lightest ship's information is returned by calling its ToString()
// function. 
string ManageShips::GetLightestShip(){
  Spaceship<Item> *itemShipPtr = &m_itemShips[0]; // pointer that keeps track of lightest item ship' weight
  for (unsigned int i = 0; i < m_itemShips.size(); i++){
    if (m_itemShips[i] < *itemShipPtr){
      itemShipPtr = &m_itemShips[i]; // update pointer to point at item ship holding the least weight
    }
  }

  Spaceship<Person> *personShipPtr = &m_personShips[0]; // pointer that keeps track of lightest person ship' weight
  for (unsigned int i = 0; i < m_personShips.size(); i++){
    if (m_personShips[i] < *personShipPtr){
      personShipPtr = &m_personShips[i]; // update pointer to point at person ship holding the least weight
    }
  }

  if (*itemShipPtr < *personShipPtr){ // finally compare the lightest item ship and lightest person ship
    return itemShipPtr->ToString();
  }

  else{
    return personShipPtr->ToString();
  }
}

// GetLightestItem()
// Checks all the items in all item ships to find the lightest item
// Finally reutnrs a string that is properly formatted with all 
// information about the item.
string ManageShips::GetLightestItem(){
  // Initialize information for the object
  string name = "Rovers_47";
  int id = 67246;
  double weight = 606845.60;

  // Loop through every ship to find lightest item
  for (unsigned int i = 0; i < m_itemShips.size(); i++){
    vector<Item>cargo = m_itemShips[i].GetCargo(); // check items in m_cargo vector in Spaceship.h 
    if (cargo.size() > 0){ // make sure ship is not empty
      for (unsigned int j = 0; j < cargo.size(); j++){
        if (cargo[j].GetWeight() < weight){
	  name = cargo[j].GetName();
	  id = cargo[j].GetId();
          weight = cargo[j].GetWeight();
        }
      }
    }
  }
  Item item1 (id, name, weight); // Finally create an object excatly like the lightest item
  string printString = item1.ToString(); // ToString() will give the properly formatted string
  return printString;
}

// GetHeaviestItem()
// Checks all the items in all item ships to find the heaviest item
// Finally reutnrs a string that is properly formatted with all
// information about the item.
string ManageShips::GetHeaviestItem(){
  // Initialize information for the object
  string name = "Rovers_47";
  int id = 67246;
  double weight = 606845.60;

  // Loop through every ship to find heaviest item
  for (unsigned int i = 0; i < m_itemShips.size(); i++){
    vector<Item>cargo = m_itemShips[i].GetCargo(); // check items in m_cargo vector in Spaceship.h
    if (cargo.size() > 0){ // make sure ship is not empty
      for (unsigned int j = 0; j < cargo.size(); j++){
        if (cargo[j].GetWeight() > weight){
          name = cargo[j].GetName();
          id = cargo[j].GetId();
          weight = cargo[j].GetWeight();
        }
      }
    }
  }
  Item item1 (id, name, weight); // Finally create an object excatly like the heaviest item
  string printString = item1.ToString(); // ToString() will give the properly formatted string
  return printString;

}

// GetOldestPerson()
// Checks all the people in all people ships to find the oldest person
// Finally reutnrs a string that is properly formatted with all
// information about the person.
string ManageShips::GetOldestPerson(){
  // Initialize information for the object
  string fName = "Chaney" , lName = "Booth";
  int age = 71;
  double weight = 191;
 
  // Loop through every ship to find oldest person
  for (unsigned int i = 0; i < m_personShips.size(); i++){
    vector<Person>cargo = m_personShips[i].GetCargo(); // check people in m_cargo vector in Spaceship.h
    if (cargo.size() > 0){ // make sure ship is not empty
      for (unsigned int j = 0; j < cargo.size(); j++){
        if (cargo[j].GetAge() > age){
	  fName = cargo[j].GetFName();
	  lName = cargo[j].GetLName();
	  age = cargo[j].GetAge();
          weight = cargo[j].GetWeight();
	}
      }
    }
  }
  Person person1 (fName, lName, weight, age, 0); // Finally create an object excatly like the oldest person
  string printString = person1.ToString(); // ToString() will give the properly formatted string 
  return printString;
}

// GetYoungestPerson()
// Checks all the people in all people ships to find the youngest person
// Finally reutnrs a string that is properly formatted with all
// information about the person.
string ManageShips::GetYoungestPerson(){
  // Initialize information for the object
  string fName = "Chaney" , lName = "Booth";
  int age = 71;
  double weight = 191;

  // Loop through every ship to find youngest person
  for (unsigned int i = 0; i < m_personShips.size(); i++){
    vector<Person>cargo = m_personShips[i].GetCargo(); // check people in m_cargo vector in Spaceship.h
    if (cargo.size() > 0){ // make sure ship is not empty
      for (unsigned int j = 0; j < cargo.size(); j++){
        if (cargo[j].GetAge() < age){
          fName = cargo[j].GetFName();
          lName = cargo[j].GetLName();
          age = cargo[j].GetAge();
          weight = cargo[j].GetWeight();
        }
      }
    }
  }
  Person person1 (fName, lName, weight, age, 0); // Finally create an object excatly like the youngest person
  string printString = person1.ToString(); // ToString() will give the properly formatted string
  return printString;
}

