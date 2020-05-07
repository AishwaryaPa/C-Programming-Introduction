/*****************************************
 ** File:    Game.cpp
 ** Project: CMSC 202 Project 4, Fall 2017
 ** Author:  Aishwarya Panchumarty
 ** Date:    11/17/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 **
 ** This file contains the code that controls the entire game. 
 ** It initializes the Monsters, and Ben. It also identifies 
 ** how many rounds (up to 20) the user would like to play. 
 ** Deals with win/loss scenarios, battle, and the menu. Has 
 ** an important destructor to make sure that there are no 
 ** memory leaks!
 **
 ***********************************************/
# include "Game.h"

const int MIN_RANGE = 1;
const int MAX_RANGE = 20;

// Game (Constructor)
// Controls the order of the entire game.  
// When the user is finished, calls the destructor
Game::Game(){
  // Initiate everything before starting the game per level
  m_levels = NumLevels();
  m_level = 0;
  cout <<"                                The game starts....         " << endl;
  InitBen();
  m_mons = new Monster*[m_levels];
  while (m_level < m_levels){
    InitMonsters();
    cout <<"                              Level " << m_level + 1 << " of "  << m_levels  << endl;
    SetBen(m_currBen->GetLife());
    Start(m_currBen->GetLife());
    m_level = m_level + 1;
  }
}

// ~Game (Destructor)
// Deletes all dynamically allocated data including 
// the arrays of Ben and Monster and all the pointers
// inside of them
Game::~Game(){
  for (int i = 0; i < 3; i++){
    delete m_ben[i];
    m_ben[i] = NULL;
  }

  delete [] m_ben;
  m_ben = NULL;

  for (int i = 0; i < m_levels; i++){
    delete m_mons[i];
    m_mons[i] = NULL;
  }

  delete [] m_mons;
  m_mons = NULL;
}

// InitMonsters()
// Dynamically creates an Monster and puts it in the monster
// array. Finally sets the currMons to the newly created one
void Game::InitMonsters(){
  Monster *monsPtr = new Monster(m_level);
  m_mons[m_level] = monsPtr;
  m_currMons = m_mons[m_level];
}

// InitBen()
// Dynamically creates all forms of ben in the ben array. 
// Finally currBen is set to the first form in the array
// The firt form is ben. The second form is Pyronite.
// The third form is Crystalsapien
void Game::InitBen(){
  m_formsBen = 3; 
  m_ben = new Ben*[m_formsBen];
  
  // dynamically creates a pointer and points it at the object 

  Ben* benPtr = new Ben("Ben", 100, "hand-to-hand", "kick", 0, 10.0, 0, 2, 10, 20, 25);
  m_ben[0] = benPtr;

  Ben* pyronitePtr = new Pyronite("Pyronite", benPtr->GetLife(), "fire", "flamer", 0, 15.0, 0, 1, 15, 20, 30);
  m_ben[1] = pyronitePtr;

  Ben* crystalsapienPtr = new Crystalsapien("Crystalsapien", benPtr->GetLife(), "energy", "laser", 25.0, 25.0, 0, 1, 25, 30, 10);
  m_ben[2] =  crystalsapienPtr;   

  m_currBen = m_ben[0]; 
}

// SetBen()
// Sets m_currBen based on user choice
void Game::SetBen(int startLife){
  int benForm;
  int maxForms;
  cout <<"Select one from the available forms of Ben at level " << m_level + 1 <<" are: " << endl;

  // The options(based on the level) the user can choose are:
  if (m_level >= 0){
    cout << "1.Ben" << endl;
    maxForms = 1;
  }
 
  if (m_level >= 1){
    cout << "2.Pyronite" << endl;
    maxForms = 2;
  }
 
  if (m_level >=2){
    cout << "3.Crystalsapien " << endl; 
    maxForms = 3;
  }

  cout <<"What would you like to do?"<< endl;
 
 // input validation 
  while ((cout << "Enter a number between " << MIN_RANGE
          << " and " << maxForms << ": " << endl)
         &&(!(cin >> benForm)) 
         || (benForm < MIN_RANGE) || (benForm > maxForms)) {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Invalid input; please re-enter an integer between 1 and " << maxForms << endl;
  }
  
  // Life is set based on the value of the old form of Ben
  int previousLife = m_currBen->GetLife();
  m_currBen = m_ben[benForm - 1];
  m_currBen->SetLife(previousLife);
}

// Start()
// Starts and guides the entire game by keeping track of points.
// If ben dies, the game ends and exits the function. If ben 
// wins a level, he goes to the next level or he wins the entire 
// game. 
void Game::Start(int startLife){
  // Shows the information of Ben and Monster
  cout << "BEN: " << m_currBen->GetName() << endl; 
  cout << "MONSTER: " << m_currMons->GetName() << endl;
  cout << "The start life of Ben is: " << m_currBen->GetLife() << endl;
  cout << "The start life of " << m_currMons->GetName() << " is " << m_currMons->GetLife() << endl;
  cout << "Ben: " << m_currBen->GetLife() << "      " << m_currMons->GetName() <<": " << m_currMons->GetLife() << endl;

  while (Input() == true){
    // user choice validation
    int option = 0;
    int minOption = 1;
    int maxOption = 3;
    while ((cout << "What would you like to do?" << '\n' 
	    << "1. Normal Attack" << '\n'   
	    << "2. Special Attack"  << '\n'
	    << "3. Ultimate Attack" << '\n'
	    << "Enter a number between " << minOption
	    << " and " << maxOption << ": " << endl)
	   &&(!(cin >> option))
	   || (option < minOption) || (option > maxOption)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input; please re-enter an integer between 1 and 3" << endl;
    }
   
    // Calls types of attack based on user choice
    if (option == 1){
      m_currBen->Attack(m_currMons);
    }
    
    else if (option == 2){
      m_currBen->SpecialAttack(m_currMons);
    }
    
    else if (option == 3){
      m_currBen->UltimateAttack(m_currMons);
    }

    if (Input() == true){
      m_currMons->Attack(m_currBen);
      cout << "Ben: " << m_currBen->GetLife() << "      " << m_currMons->GetName() <<": " << m_currMons->GetLife() << endl;
    }
  }

  // Win and loss 
  if  (Input() == false) {
    if (m_currBen->GetLife() > 0 || m_currMons <= 0){
      cout <<"Congrats! " << m_currBen->GetName() <<" won that level"  <<endl;
      if (m_level + 1 == m_levels){
	cout <<"Congrats! You won the game" << endl;
      }
    }
    
    else if (m_currBen->GetLife() <= 0 ||  m_currMons->GetLife() > 0){
      cout << "You lost" << endl;
      m_level = m_levels; // if Ben loses, stop the game
    } 
  }
}

// NumLevels()
// Returns the user reponse about how many levels he/she would like to play 
int Game::NumLevels(){
  int numLevels = 0;

  // check correct value is entered and takes in a valid value
  cout <<"How many levels would you like to try?" << endl;
  while ((cout << "Enter a number between " << MIN_RANGE
          << " and " << MAX_RANGE << ": " << endl)
         &&(!(cin >> numLevels))
         || (numLevels < MIN_RANGE) || (numLevels > MAX_RANGE)) {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input; please re-enter an integer between 1 and 20." << endl;
  }
  
  return numLevels;
}

// Input()
// Checks to see if Ben and monster are alive
// Return true if both are alive. Returns 
// false if one dies 
bool Game::Input(){
  // Both must be alive to understand whether Ben should go to the next level
  // or the game should end

  if (m_currBen->GetLife() > 0 and m_currMons->GetLife() > 0){
    return true;
  } 
  else if (m_currBen->GetLife() <= 0 or m_currMons->GetLife() <= 0){ 
    return false;
  }
}

