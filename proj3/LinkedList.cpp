/*****************************************
 ** File:    LinkedList.cpp
 ** Project: CMSC 202 Project 2, Fall 2016
 ** Author:  Aishwarya Panchumarty
 ** Date:    11/01/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 **
 ** This file contains the functions for Linked list.
 ** It dynamically creates nodes that will store the 
 ** data. In order to decrypt the code, the list is  
 ** first sorted by m_int and then displayed. Finally,  
 ** the list is deleted.
 ***********************************************/


# include "LinkedList.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// contructor
LinkedList::LinkedList(){
  m_head = NULL; 
  m_tail = NULL; 
}

// destructor
LinkedList::~LinkedList(){
  Clear();
}

// CreateNode(int newInt, string newPayload)
// dynamically allocates a new node, populates it with data,
// and returns it to InsertEnd()
Node *LinkedList::CreateNode(int newInt, string newPayload){
  Node *newNode = new(Node); //(struct Node)
  newNode->m_int = newInt;
  newNode->m_payload = newPayload;
  newNode->m_next = NULL;
  return newNode;
}

// InsertEnd(int newInt, string newPayload)
// Calls CreateNode, and adds a new node at the end of the list
void LinkedList::InsertEnd(int newInt, string newPayload){
  
  Node *newNode = CreateNode(newInt, newPayload);
  // first node
  if (m_head == NULL)
    {
      m_head = newNode;
      m_tail = newNode;
    }

  // rest of the nodes
  else
    { 
      m_tail->m_next = newNode;
      m_tail = newNode;
    }
}

// Display()
// diaplays the message. It does not have to be sorted.
void LinkedList:: Display(){
  Node *CURR = m_head;
  cout << "Payload of list are: "<< endl;
  while (CURR != NULL)
    {
      cout << CURR->m_payload << "->";
      CURR = CURR->m_next;
    }
  cout << "END" << endl;
}

// Sort()
// Bubble sorts the list by m_int value.
void LinkedList::Sort(){
  Node *CURR = m_head;

  // count number of nodes so the for loop can be executed that many times
  int numForLoop = 0;
  while (CURR != NULL)
    {
      numForLoop = numForLoop + 1;
      CURR = CURR->m_next;
    }

  // sort out the list
  int counter = 0;
  while (counter != numForLoop)
    {
      for (CURR = m_head; CURR != NULL; CURR = CURR->m_next)
	{          
	  if (CURR->m_next != NULL) // Make sure both items in the pair are not pointing to NULL
	    {
	      Node *firstNode = CURR;   
	      Node *secondNode = CURR->m_next;
	      
	      if (firstNode->m_int > secondNode->m_int)
		{
		  int integer = secondNode->m_int;
		  string code = secondNode->m_payload;
		  
		  // swap second node's data with the first node's data
		  secondNode->m_int = firstNode->m_int;
		  secondNode->m_payload = firstNode->m_payload;
		  
		  // swap first node's data with the second node's data
		  firstNode->m_int = integer;
		  firstNode->m_payload = code;
		}
	    }
	}
      counter = counter + 1;
    }
}

// IsEmpty()
// Checks if the list is empty or not
bool LinkedList::IsEmpty(){
  if (m_head == NULL)
    {
      return true;
    }
  return false;
}

// Decrypt()
// Takes a encrypted message and decrypts by choosing only the 
// values that have a perfect square or perfect cube
LinkedList LinkedList::Decrypt(){
  LinkedList list2;
  Node *CURR;
  for (CURR = m_head; CURR != NULL; CURR = CURR->m_next)
    {
      bool perfectSquare = IsPerfectSquare(CURR->m_int);
      bool perfectCube = IsPerfectCube(CURR->m_int);
      if (perfectSquare == true or perfectCube == true)
	{
	  if (perfectSquare == true)
	    {
	     CURR->m_int = sqrt(CURR->m_int);
	    }
	  if (perfectCube == true)
            {
	      CURR->m_int = cbrt(CURR->m_int);
            }
	  list2.InsertEnd(CURR->m_int, CURR->m_payload);
	}
    }
  return list2;
}

// IsPerfectSquare(int n)
// returns the squareroot of the integer given
bool LinkedList::IsPerfectSquare(int n){
  int  squareRoot = sqrt(n);
  if (squareRoot*squareRoot == n){
    return true;
  }
  return false;
}

// IsPerfectCube(int n)
// returns the cuberoot of the integer given
bool LinkedList::IsPerfectCube(int n){
  int cubeRoot = cbrt(n);
  if (cubeRoot*cubeRoot*cubeRoot == n){
    return true;
  }
  return false;
}

// Clear()
// deallocates all the pointers in the list and 
// finally sets head to NULL
void LinkedList::Clear(){
  Node * curr = m_head;
  Node * next = m_head;
  while (next != NULL)
    {
      curr = next;
      next = next->m_next;
      delete curr;
    }
  m_head = NULL;
}




