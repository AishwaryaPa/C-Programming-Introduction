/*****************************************
 ** File:    proj3.cpp
 ** Project: CMSC 202 Project 3, Fall 2016
 ** Author:  Aishwarya Panchumarty
 ** Date:    11/01/16
 ** Section: 07
 ** E-mail:  aispan1.umbc.edu
 **
 ** This file contains the main driver program for Project 3.
 ** It gets input from the text files the user enters and 
 ** and stores that data in a linked list. All the functions
 ** related to the linked list are in LinkedList.cpp.
 ***********************************************/


#include "LinkedList.h"
#include "proj3.h"

int main () {
  LinkedList list;
  mainMenu(list);
  return 0;
}

// readFile()
// Reads in a file that the user enters.  
void readFile(LinkedList &list){
  bool listEmpty = list.IsEmpty();
  int option = 0;

  // if the list is not empty
  if (listEmpty == false)
    {
      cout << "Do you want to: " << endl;
      cout <<"1. Overwrite the message " << endl;
      cout <<"2. Append the message " <<endl;
      cout <<"3. Cancel " << endl;
      cin >> option;
      if (option == 1)
	{
	  cout << "Previous message cleared" << endl;
	  option = 0;
	  
	}
    }

  // if the list is empty or list is not empty but need to add new data into the list
  if (option == 0 or option == 2)
    {
      int num;
      string code;
      string userFileName; 
      cout <<"What is the file name?:"<< endl;
      cin >> userFileName;
      fstream inputStream;
      inputStream.open(userFileName.c_str());
      cout << "file uploaded" << endl;
      while (inputStream >> num >> code)
	{
	  list.InsertEnd(num, code);  
	}
      inputStream.close();
    }
}

// mainMenu(list)
// displays options and takes in user input. Calls a function that 
// corresponds to that input
void mainMenu(LinkedList &list){
  int option = 0;
  bool isExit = 0;
  do {
    do {
      cout << "What would you like to do?: " << endl;
      cout << "1. Load a new encrypted message" << endl;
      cout << "2. Display a raw message" << endl;
      cout << "3. Display an encrypted message" << endl;
      cout << "4. Exit" << endl;
      cin >> option;
    }while(option < 1 || option > 4);

    switch(option){
    case 1:
      readFile(list);
      break;
    case 2:
      displayMessage(list);
      break;
    case 3:
      displayEncrypt(list);
      break;
    case 4:
      exitLinked(list);
      isExit = 1;
    }
  }while(isExit == 0);
}

// displayMessage(list)
// displays two messages that has not been decrypted. 
// one that is not sorted and one that is sorted
void displayMessage(LinkedList &list){
  bool listEmpty = list.IsEmpty();
  if (listEmpty == true)
    {
      cout << "You haven't loaded an encrypted message yet." << endl;
    }
  else if (listEmpty == false)
    {
      list.Display();
      list.Sort();
      list.Display();
    }
}

// exitLinked(list)
// if the list is not empty, clear the list and exits
void exitLinked(LinkedList &list){
  bool isEmpty = list.IsEmpty();
  if (isEmpty == false)
    {
      list.~LinkedList();
    }
  cout <<"Have a nice day!" << endl;
}

// displayEncrypt(list)
// displays the message that has been encrypted. Only the nodes
// that have perfect square or perfect cube numbers
void displayEncrypt(LinkedList &list){
  bool listEmpty = list.IsEmpty();
  if (listEmpty == true)
    {
      cout << "You haven't loaded an encrypted message yet." << endl;
    }
  else if (listEmpty == false)
    {
      LinkedList list2 = list.Decrypt();
      list2.Sort();
      list2.Display();
      list2.~LinkedList();
    }
}
