/*****************************************
 ** File:    Monster.cpp
 ** Project: CMSC 202 Project 4, Fall 2017
 ** Author:  Aishwarya Panchumarty
 ** Date:    11/17/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu 
 **
 ** This file contains the code for Monster. Monster name is 
 ** randomly picked from monster.txt and its data is 
 ** determined based on the level of the game. Monsters' data  
 ** such as life and attack are controlled in this file.
 **
 ***********************************************/
#include "Monster.h"
#include <cstdlib>

const char FILENAME[12] = "monster.txt";

// Monster (Constructor)
// Sets the name of the monster randomly from the monster.txt file.
// Sets the life and attack based on calculated values
Monster::Monster(int level){
  m_name = SummonMonster();
  srand(time(NULL));
  // life values and attack values are set based on level
  if (level == 0){
    m_life = (rand() % (50 - 20)) + 20;
    m_attack = (rand() % (5 - 1)) + 1;
  }

  else if (level == 1){
    m_life = (rand() % (60 - 30)) + 30;
    m_attack = (rand() % (10 - 3)) + 3;
  }

  else if (level >= 2){
    m_life = (rand() % (70 - 40)) + 40;
    m_attack = (rand() % (15 - 5)) + 5;
  }

  m_monster.clear(); 
}

// ~Monster
// does nothing
Monster::~Monster(){
  // All memory is deleted in Game destructor
}

// SummonMonster
// Choses a random monster from the vector and returns its name
string Monster::SummonMonster(){
  LoadMonster();
  int vectorSize = ((int) m_monster.size()) - 1; // have to subtract one because the index starts at 0
  int randomIndex = (rand() % (vectorSize - 0)) + 0; 
  int chosenIndex;
  for (unsigned int i = 0; i <= vectorSize; i++) // finds the index choosen by random generator 
    {
      if (i == randomIndex)
	{
	  chosenIndex = i;
	}
    }
  return m_monster[chosenIndex];
}

// LoadMonster
// Populates the vector with the monster names in the file
void Monster::LoadMonster(){
  string name;
  fstream inputStream;
  inputStream.open(FILENAME);
  while (getline(inputStream, name)){ 
    m_monster.push_back(name);
  }
  inputStream.close();
}

// Attack()
// Attacks the opponent by reducing the oppenent's life value
void Monster::Attack(Ben *&target){
  int opponentLife = target->GetLife();
  
  // Attacks Crystalsapien based on defense bonus, so damage is reduced
  if (target->GetName() == "Crystalsapien"){
    int reduceDamage = static_cast<int>((target->GetDefenseBonus()/100)*m_attack);
    target->SetLife(opponentLife - (m_attack - reduceDamage));
    cout << m_name << " attacks " << target->GetName() << " using a normal attack." << endl;
    cout << m_name << " did " << (m_attack - reduceDamage) << " to " << target->GetName() << endl;
  }

  // No defense bonus for other forms of ben, so attacks normally
  else {
    target->SetLife(opponentLife - m_attack);
    cout << m_name << " attacks " << target->GetName() << " using a normal attack." << endl;
    cout << m_name << " did " << m_attack << " to " << target->GetName() << endl;
  }
}

// SetLife() updates the new value of life. The getters return the value they were asked for
void Monster::SetLife(int life){
  m_life = life;
}

int Monster::GetLife(){
  return m_life;
}

string Monster:: GetName(){
  return m_name;
}


