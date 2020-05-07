/*****************************************
 ** File:    proj2.cpp
 ** Project: CMSC 202 Project 2, Fall 2016
 ** Author:  Aishwarya Panchumarty
 ** Date:    10/06/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 **
 ** This file contains the class MyPokemon for project 2
 ***********************************************/

#include "MyPokemon.h"
using namespace std;

//Constructors
MyPokemon::MyPokemon () {
  m_Num = 27;
  m_Name = "Sandshrew";
  m_CP = 77;
  m_HP = 7;
  m_Rarity = 1;
}

MyPokemon::MyPokemon (int num, string name, int cp, int hp, int rarity) {
  m_Num = num;
  m_Name = name;
  m_CP = cp;
  m_HP = hp;
  m_Rarity = rarity;
  //  Pokemon pokemon1;
}

//Accessors 
int MyPokemon::GetCP(){
  return m_CP;
}

int MyPokemon::GetHP(){
  return m_HP;
}

int MyPokemon::GetRarity(){
  return m_Rarity;
}

string MyPokemon::GetName(){
  return m_Name;
}

int MyPokemon::GetNum(){
  return m_Num;
}

//Mutators
void MyPokemon::SetRarity(int newRarity){
  m_Rarity = newRarity;
}

void MyPokemon::SetName(string newName){
  m_Name = newName;
}

void MyPokemon::SetCP(int newCP){
  m_CP = newCP;
}

void MyPokemon::SetHP(int newHP){
  m_HP = newHP;
}

//Member Functions
// Train()
// trains pokemon by adding ten cp
void MyPokemon::Train(){
  m_CP = m_CP + 10;
}




