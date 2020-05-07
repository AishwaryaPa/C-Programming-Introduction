/*****************************************
 ** File:    Pyronite.cpp
 ** Project: CMSC 202 Project 4, Fall 2017
 ** Author:  Aishwarya Panchumarty
 ** Date:    11/17/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 ** Child class of Ben. Inherits lots of stuff and 
 ** overrides Attack and Special Attack. Does not 
 ** have an Ultimate Attack.
 **
 ***********************************************/
#include "Pyronite.h"
#include "Monster.h"
#include <stdlib.h>
#include <time.h>

// Attack()
// Does calculated damage to the target based on data 
void Pyronite::Attack(Monster *&target){
  srand(time(NULL));

  // 15% chance of missing the attack. 
  double miss = static_cast<double>(rand() % (100 - 1) + 1);
  if (miss <=  m_missPercent){
    cout << m_name << " misses the normal attack. " << target->GetName() <<" retaliates!" << endl;
  }

  // if attack is not missed, then do damage to target
  else {
    int normalDamage = (rand() % (m_maxDamageNormal - m_minDamageNormal)) + m_minDamageNormal;
    int opponentLife = target->GetLife();
    target->SetLife(opponentLife - normalDamage);
    cout << m_name << " attacks using his " << m_nameNormal << endl;
    cout << m_name <<  " did " << normalDamage << " to " << target->GetName() << endl;
  }
}


// SpecialAttack()
// Another type of attack, but does more damage. The number of attacks of this type
// is limited. This number is based on the form of Ben. If the  user uses more than
// allowed, the monster will automatically retailiate. Damage data is calcuated
void Pyronite::SpecialAttack(Monster *&target){
  // not allowed to use more than one special attack
  if (m_usedSpecial >= m_maxSpecial){
    cout << m_name <<" is out of special attacks! " << target->GetName() <<" retaliates!"  << endl;
  }

  else if(m_usedSpecial < m_maxSpecial){
    int opponentLife = target->GetLife();
    target->SetLife(opponentLife -  m_damageSpecial);
    cout << m_name <<" attacks using his " << m_nameSpecial << endl;
    cout << m_name <<" did " << m_damageSpecial << " to " << target->GetName() << endl;
    m_usedSpecial = m_usedSpecial + 1;
  }
}

