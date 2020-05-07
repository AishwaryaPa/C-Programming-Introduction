/*****************************************
 ** File:    Ben.cpp
 ** Project: CMSC 202 Project 4, Fall 2017
 ** Author:  Aishwarya Panchumarty
 ** Date:    11/17/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 **
 ** This file contains the code for Ben. It has several 
 ** data members that are populated during the constructor. 
 ** Has some virtual functions that are overridden by child 
 ** classes including Pyronite and Crystalsapien. 
 **
 ***********************************************/
#include "Ben.h"
#include "Monster.h"
#include <stdlib.h>
#include <time.h>

// Ben (Constructor)
// Creates an object of Ben and his forms
Ben::Ben(string name, int life){
  m_name = name;
  m_life = life;
  m_usedSpecial = 0;
}

// Ben (Overloaded constructor)
// Creates a specific version of Ben for use in transformed versions
Ben::Ben(string name, int life, string nameNorm, string nameSpecial,
    double defenseBonus, double missPercent, int usedSpecial,
	 int maxSpecial, int minDamNorm, int maxDamNorm, int damSpec){
  m_name = name;
  m_nameNormal = nameNorm;
  m_nameSpecial =  nameSpecial;
  m_life = life;
  m_defenseBonus =  defenseBonus; 
  m_missPercent = missPercent; 
  m_usedSpecial = usedSpecial;
  m_maxSpecial = maxSpecial; 
  m_minDamageNormal = minDamNorm;
  m_maxDamageNormal = maxDamNorm; 
  m_damageSpecial = damSpec; 
}

// ~Ben
// does nothing
Ben::~Ben(){
  //All memory is deleted in Game Destructor
}

// Attack()
// Attacks target based on calcuated data. 
// It is possible for Ben and his forms to miss.
void Ben::Attack(Monster *&target){
  srand(time(NULL));
  
  // 10% chance of missing the attack. 
  double miss = static_cast<double>(rand() % (100 - 1) + 1);
  if (miss <= m_missPercent){
    cout << m_name << " misses the normal attack. " << target->GetName() <<" retaliates!" << endl;
  }

  // if attack is not missed, then do damage
  else {
    int normalDamage = (rand() % (m_maxDamageNormal - m_minDamageNormal)) + m_minDamageNormal;
    int opponentLife = target->GetLife();
    target->SetLife(opponentLife - normalDamage);
    cout << m_name <<" attacks using his " << m_nameNormal << endl;
    cout << m_name <<" did " << normalDamage << " to " << target->GetName() << endl; 
  }
}

// SpecialAttack()
// Another type of attack, but does more damage. The number of attacks of this type
// is limited. This number is based on the form of Ben. If the  user uses more than 
// allowed, the monster will automatically retailiate. Damage data is calcuated
void Ben::SpecialAttack(Monster *&target){
  
  // not allowed to use more than two special attacks
  if (m_usedSpecial >= m_maxSpecial){
    cout << m_name <<" is out of special attacks! " << target->GetName() <<" retaliates!"  << endl;
  }

  else if(m_usedSpecial < m_maxSpecial){
    int opponentLife = target->GetLife();
    target->SetLife(opponentLife -  m_damageSpecial);
    cout << m_name << " attacks using his " << m_nameSpecial << endl;
    cout << m_name << " did " << m_damageSpecial << " to " << target->GetName() << endl;
    m_usedSpecial = m_usedSpecial + 1;  // keeps track of number of special attacks the user used
  }
}

// Ultimate Attack()
// This attack is only avaliable for Crystalsapien. If other
// forms use this attack, the target automatically retaliates 
void Ben::UltimateAttack(Monster *&target){
  cout <<"Ben has no ultimate attack! " << target->GetName() << " retaliates!" << endl;
}

// Name: Mutators and Acccessors
// SetLife() updates values and the rest return a member variable
void Ben::SetLife(int life){
  m_life = life;
}

string Ben::GetName(){
  return m_name;
}

int Ben::GetLife(){
  return m_life;
}

double Ben::GetDefenseBonus(){
  return m_defenseBonus;
}
