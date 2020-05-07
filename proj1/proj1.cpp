/*
File:    Project 1
Project: CMSC 202 Project 1, Fall 2016
Author:  Aishwarya Panchumarty
Date:    09/23/16
Section: 07
E-mail:  aispan1@umbc.edu
Description: This program contains information about an 
             ATM with very basic features
*/

#include "proj1.h"
const char* FILENAME = "proj1.txt"; 

int main () {
  int menuStartChoice = menuStart();

  // In case the user chooses 3, this if statement will prevent the while loop from executing 
  int exit = 1;
  if (menuStartChoice == 3) {
    exit = 0;
      }
  string fName, lName;
  int age;
  float accountBalance;

  while (exit == 1) { 
      switch (menuStartChoice)
	{
	  // Loads User Input from proj1.txt file
	case 1:
	{
	  fstream inputStream;
	  inputStream.open(FILENAME);
	  inputStream >> fName >> lName >> age >>  accountBalance;
	  inputStream.close();
	  menuStartChoice = 4;
	  break;
	}
	
	// New User Profile  
	case 2:
	{
	  cout << "First Name: " << endl;
	  cin >> fName;
	  cout << "Last Name: " << endl;
	  cin >> lName;
	  cout << "Age: " << endl;
	  cin >> age;
	  cout << "Initial Deposit: " << endl;
	  cin >> accountBalance;
	  cout << "$" << fixed << setprecision (2) << accountBalance << " " << "deposited" << endl;
	  menuStartChoice = 4;
	  break;
	}
	
	case 4:
	  {
	    int menuMainChoice = menuMain();
	    switch (menuMainChoice)
	      {
	      case 1:
		{
		  displayBalance(accountBalance);
		  break;
		}
		
	      case 2:
		{
		  deposit(accountBalance);
		  break;
		}
	      case 3:
		{
		  withdraw(accountBalance);
		  break;
		}
	      case 4:
		{
		  displayAccountDetails(fName, lName, age, accountBalance);
		  break;
		}
	      case 5:
		{
		  string saveOption;
		  cout << "Would you like to save your account information?: " << endl;
		  cout << "yes or no" << endl;
		  cin >> saveOption;
		  if (saveOption == "yes") {
		    fstream outputStream;
		    outputStream.open(FILENAME);
		    outputStream << fName << " " <<lName << " " <<age << " " << accountBalance;
		    outputStream.close();
		    cout << "File Saved" << endl;
		  }
		  exit = 0;
		}
	
	      } 

	  } 
     	} 
  } 
  cout << "Thank you for using the UMBC ATM" << endl;
  return 0;
}

/*
Name: menuStart()
PreCondition: None
PostCondition: Returns the selected option (1, 2, or 3)
*/
int menuStart() {
  // choices
  cout <<"Welcome to the UMBC ATM" << endl; 
  cout <<"Choose from below:" << endl;
  cout <<"1. Load a User Profile from File" <<endl;
  cout <<"2. Enter a new User Profile" <<endl;
  cout <<"3. Exit" << endl;
  
  int userChoice;
  cout <<"Enter your choice:" << endl;
  cin >> userChoice;

  //user verification
  while (userChoice < 1 or userChoice > 3) {
    cout << "Enter choice between 1 and 3:" << endl;
    cin >> userChoice;
    
  }
  return userChoice;
}


/*
Name: menuMain()
PreCondition: The user input has either been loaded from file or entered by user
PostCondition: Returns the selected option (1, 2, 3, 4, or 5)
*/
int menuMain() {
  // choices
  cout << "********Please choose option from the menu*********" << endl;
  cout << "1. Account Balance" << endl;
  cout << "2. Deposit money" << endl;
  cout << "3. Withdraw money" << endl;
  cout << "4. Display your account details" << endl;
  cout << "5. Exit" << endl;

  int userChoice;
  cout <<"Enter your choice:" << endl;
  cin >> userChoice;

  //user verification
  while (userChoice < 1 or userChoice > 5) {
    cout << "Enter choice between 1 and 5:" << endl;
    cin >> userChoice;

  }
  return userChoice;
}

/*
Name: displayBalance
PreCondition: Relevant data (accountBalance) has been loaded/entered
PostCondition: None (void)
*/
void displayBalance(float accountBalance) {
  cout << "Account Balance: " << fixed << setprecision (2) <<"$"<< accountBalance << endl;
}


/*
Name: displayAccountDetails
PreCondition: Relevant data (fName, lName, age, accountBalance) has been loaded/entered
PostCondition: None (void)
*/
void displayAccountDetails(string fName, string lName, int age, float accountBalance) {
  cout << "First Name: " << " " << fName << endl;
  cout << "Last Name: " << " " << lName << endl;
  cout << "Age: " << " " << age << endl;
  cout << "Account Balance: " << fixed << setprecision (2) << "$" << accountBalance << endl;
}
 

/*
Name: deposit
PreCondition: Variable accountBalance is passed-by-reference
PostCondition: accountBalance is permanently changed via pass-by-reference
*/
void deposit(float &accountBalance) {
  float amount;
  cout << "Please enter the amount to be deposited: " << endl;
  cin >> amount;
  if (amount > 0){ 
    accountBalance = accountBalance + amount;
    cout << "$" << fixed << setprecision (2) << amount << " " << "deposited to your account" << endl;
  }  
  else if (amount <= 0){
      cout << "Amount should be greater than 0" << endl;
  }
}

/*
Name: withdraw
PreCondition: Variable accountBalance is passed-by-reference
PostCondition: accountBalance is permanently changed via pass-by-reference
*/
void withdraw(float &accountBalance) {
  float amount;
  cout << "Please enter the amount to be withdrawn: " << endl;
  cin >> amount;
  if (amount > accountBalance){ 
    cout << "You can only withdraw" << " " <<fixed << setprecision (2) << "$" << accountBalance << " " << "or less" << endl;
  }
  else if (amount < accountBalance and amount > 0){ 
    accountBalance = accountBalance - amount;
    cout << "$" << fixed << setprecision (2) << amount << " " <<"withdrawn from your account" << endl;
  }
  else if (amount <= 0){ 
    cout << "Amount must be greater than zero" << endl;
  }
}
