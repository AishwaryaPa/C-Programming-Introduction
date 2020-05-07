/*****************************************
 ** File:    proj2.cpp
 ** Project: CMSC 202 Project 2, Fall 2016
 ** Author:  Aishwarya Panchumarty
 ** Date:    10/06/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu 
 **
 ** This file contains the main driver program for Project 2.
 ** It gets input from the text files pokeDex.txt and
 ** myCollection.txt and populates the vectors with that data. 
 ** These vectors are used to show the data inside of them.
 ** They are also used so that the user could battle, train, 
 ** and catch pokemon.   
 ***********************************************/

#include "proj2.h"

int main () {
  srand(10);
  vector<Pokemon> pokeDex;
  vector<MyPokemon> myCollection;
  getPokeDex(pokeDex);
  getMyCollection(myCollection);
  mainMenu (pokeDex, myCollection);
  return 0;
}

// getPokeDex(vector)
// Take input from a file and returns a populated pokeDex vector

void getPokeDex(vector<Pokemon>& pokeDex){
  // Input from file pokeDex.txt
  int num, cpMin, cpMax, rarity;
  string name;
  fstream inputStream;
  inputStream.open(POKEDEX);

  for (int i = 0; i < POKECOUNT; i++) {
    inputStream >> num >> name >> cpMin >> cpMax >> rarity;

    // Populates Vector
    Pokemon newPokemon(num, name, cpMin, cpMax, rarity);
    pokeDex.push_back(newPokemon);
  }   
  inputStream.close();
}

// getMyCollection(vector)
// Take input from a file and returns a populated pokeDex vector

void getMyCollection(vector<MyPokemon> & myCollection){
  // Input from file myCollection.txt
  int num, cp, hp, rarity;
  string name;
  fstream inputStream;
  inputStream.open(MYCOLLECTION);
  while (inputStream >> num >> name >> cp >> hp >> rarity) {
   
    // Populates vector
    MyPokemon addPokemon(num, name, cp, hp, rarity);
    myCollection.push_back(addPokemon);
  }
  inputStream.close(); 
}

// printPokeDex (vector)
// Takes in populated vector and prints the information in it for each pokemon

void printPokeDex(vector <Pokemon> & pokeDex){
  for (unsigned i = 0; i < pokeDex.size(); i++) {
    cout << pokeDex[i].GetNum() << " "
         << pokeDex[i].GetName() << " " << endl;
  }
}

// printMyCollection (vector)
// Takes in populated vector and prints the information in it for each pokemon

void printMyCollection(vector <MyPokemon> & myCollection){
  int count = 0;
  for (unsigned i = 0; i < myCollection.size(); i++) {
    cout << count << "." << " "  
	 << myCollection[i].GetNum() << " "
         << myCollection[i].GetName() << " "
         << myCollection[i].GetCP() << " "
         << myCollection[i].GetHP() << " "
         << myCollection[i].GetRarity() << endl;
    count = count + 1;
  }
}

// catchPokemon(vector, vector)
// Takes in the two vectors and tries to catch a random pokemon based on rarity.
// If a Pokemon is found, calls foundPokemon

void catchPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int typePokemon;
  cout <<" What type of Pokemon would you like to try and catch?:" << endl;
  cout <<" 1. Very Common (Very High Probability)" << endl;
  cout <<" 2. Common (High Probability)" << endl;
  cout <<" 3. Uncommon (Normal Probability) " << endl;
  cout <<" 4. Rare (Low Probability) " << endl;
  cout <<" 5. Ultra Rare (Extremely Low Probability) " << endl;
  cin >> typePokemon;
  
  cout << "You start to search" << endl;
  
  srand(time(NULL));
  int pokeNum = rand() % 100 + 1;
  
  // check if pokemon has been found
  if (typePokemon == 1 and pokeNum <= 65) {
      foundPokemon(typePokemon, pokeDex, myCollection);
  }
  else if (typePokemon == 2 and pokeNum <= 45) {
    foundPokemon(typePokemon, pokeDex, myCollection);
  }
  else if (typePokemon == 3 and pokeNum <= 25) {
    foundPokemon(typePokemon, pokeDex, myCollection);
  }
  else if (typePokemon == 4 and pokeNum <= 10) {
    foundPokemon(typePokemon, pokeDex, myCollection);
  }
  else if (typePokemon == 5 and pokeNum <= 1) {
    foundPokemon(typePokemon, pokeDex, myCollection);
  }
  else {
    cout << "Pokemon not found" << endl;
  } 
}

// foundPokemon (rarity, vector pokeDex, vector myCollection)
// Finds a pokemon based on the rarity passed from catchPokemon()
// and adds the new Pokemon to user's collection

void foundPokemon(int rarity, vector <Pokemon> & pokeDex,
		  vector<MyPokemon> & myCollection ){
  
  bool pokemonFound = false;
  while (pokemonFound == false) {
  
    srand(time(NULL));
    int pokeNum = rand() % POKECOUNT + 1;
    int pokeIndex = pokeNum - 1;
    
    // make sure the rarity of the new pokemon matches what the user entered
    if (pokeDex[pokeIndex].GetNum() == pokeNum and pokeDex[pokeIndex].GetRarity() == rarity) {
      cout << "Congrats! You found a " << pokeDex[pokeIndex].GetName() << endl;
      
      int cpMin = pokeDex[pokeIndex].GetCPMin();
      int cpMax = pokeDex[pokeIndex].GetCPMax();
      
      // calcuate cp and hp
      srand(time(NULL));
      int cp = rand() % cpMax + cpMin;
      int hp = static_cast<int> (cp * (.10));
      
      int num = pokeNum;
      string name = pokeDex[pokeIndex].GetName();
      
      MyPokemon newPokemon (num, name, cp, hp, rarity);
      myCollection.push_back(newPokemon);
      pokemonFound = true;
    }
  }  
}

// mainMenu(vector, vector)
// Calls various function based on user's choice. Passes the appropriate vectors when needed.

void mainMenu(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int option = 0;
  bool isExit = 0;
  do {
    do {
      cout << "What would you like to do?: " << endl;
      cout << "1. See the PokeDex" << endl;
      cout << "2. See your collection" << endl;
      cout << "3. Search for a new Pokemon" << endl;
      cout << "4. Battle Your Pokemon" << endl;
      cout << "5. Train your Pokemon" << endl;
      cout << "6. Exit" << endl;
      cin >> option;
    }while(option < 1 || option > 6);

    switch(option){
    case 1:
      printPokeDex(pokeDex);
      break;
    case 2:
      printMyCollection(myCollection);
      break;
    case 3:
      catchPokemon(pokeDex,  myCollection);
      break;
    case 4:
      battlePokemon(pokeDex, myCollection);
      break;
    case 5:
      trainPokemon(pokeDex, myCollection);
      break;
    case 6:
      exitPokemon(myCollection);
      isExit = 1;
    }
  }while(isExit == 0);
}

// battlePokemon(vector, vector)
// Randomly chooses an enemy and that pokemon's cp. 
// Determines if battle is won or lost - returns to mainMenu

void battlePokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  // pick opponent randomly
  srand(time(NULL));
  int pokeNum = rand() % POKECOUNT + 1;
  int pokeIndex = pokeNum - 1;
  
  // randomly assigns cp for the oppenent
  int cpMin = pokeDex[pokeIndex].GetCPMin();
  int cpMax = pokeDex[pokeIndex].GetCPMax();
  srand(time(NULL));
  int cp = rand() % cpMax + cpMin;
  
  string name = pokeDex[pokeIndex].GetName();

  printMyCollection(myCollection);
  cout << "You are going to fight a " << name << endl;
  cout << "The enemy has a CP of " << cp << endl;
  
  int userChoice;
  cout << "Which of your Pokemon would you like to use?:" << endl;
  cin >> userChoice;
  
  if (myCollection[userChoice].GetCP() > cp) {
    cout << "You won!!" << endl;
  }
  else {
    cout << "You lost." << endl;
  }  
}

// trainPokemon(vector pokeDex, vector myCollection)
// trais the pokemon by increasing CP by 10. Updates myCollection
     
void trainPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int userChoice;
  cout << "Which of your Pokemon would you like to use?:" << endl;
  printMyCollection(myCollection);
  cin >> userChoice;

  myCollection[userChoice].Train();
  cout <<  myCollection[userChoice].GetName() << " is trained" << endl;
  cout << "Its CP is now " << myCollection[userChoice].GetCP() << endl;
}

// exitPokemon(vector)
// Calls saveMyCollection and exits application

void exitPokemon(vector<MyPokemon> & myCollection){
  saveMyCollection(myCollection);
}

// saveMyCollection(vector)
// Saves all the changes user made
void saveMyCollection(vector<MyPokemon> & myCollection){
  
  // updates myCollection.txt
  fstream outputStream;
  outputStream.open(MYCOLLECTION);
  for (unsigned i = 0; i < myCollection.size(); i++) {
    outputStream << myCollection[i].GetNum() << " " 
		 << myCollection[i].GetName() << " "
		 << myCollection[i].GetCP() << " "
		 << myCollection[i].GetHP() << " "
		 << myCollection[i].GetRarity() << endl;
  }
  outputStream.close();
  cout << "File Saved" << endl;
}
