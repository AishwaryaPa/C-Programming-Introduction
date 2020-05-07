/*****************************************
 ** File:    proj2.cpp
 ** Project: CMSC 202 Project 2, Fall 2016
 ** Author:  Aishwarya Panchumarty
 ** Date:    10/06/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 **
 ** This file contains the class Pokemon for project 2.
 ***********************************************/
#include "Pokemon.h"
using namespace std;

Pokemon::Pokemon(){
  m_Num = 1;
  m_Name = "Balbasaur";
  m_MinCP = 321;
  m_MaxCP = 1072;
  m_Rarity = 2;
}

Pokemon::Pokemon(int num, string name, int cpMin, int cpMax, int rarity){
  m_Num = num;
  m_Name = name;
  m_MinCP = cpMin;
  m_MaxCP = cpMax;
  m_Rarity = rarity;

}

// Accessors
int Pokemon::GetCPMin(){
  return m_MinCP;
}

int Pokemon::GetCPMax(){
  return m_MaxCP;
}

int Pokemon::GetRarity(){
  return m_Rarity;
}

string Pokemon::GetName(){
  return m_Name;
}

int Pokemon::GetNum(){
  return m_Num;
}

// Mutators
void Pokemon::SetRarity(int newRarity){
  m_Rarity = newRarity;
}

void Pokemon::SetName(string newName){
  m_Name = newName;
}











