/*
#CLASS: COSC 1430 w/ Prof.Toti
##FINAL PROJECT: THE LIBRARY
###GROUP MEMBERS: Dung Dinh, Armando Mata, Songwen Xue
####NOTICES:
for the files "books.txt" and "accounts.txt", remember to leave NO SPACES at the end of each line and with NO EMPTY LINE in the end. 
*/

//headers files:
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "user.h"
#include "customer.h"
#include "librarian.h"
using namespace std;


int main(){
	int ForzenCounter = 0;
	string userName, Password, customerTemp;
	char userType;
  bool temp = false;
	User *myuser;
	myuser = new User;
	cout << "user name: ";
	cin >> userName;
	userType = myuser->GetUserType(userName);
	if(userType == '0') {
		//where user is absent from the user name list
		cout << "User not appears!" << endl;
		delete myuser;
		return 0;
	}
	else if(userType == 'F'){
		//cases where the user is frozen
		cout << "Account frozen!" << endl;
		delete myuser;
		return 0;
	}
	else if(userType == 'l'){
		cout << "you are libralian!" << endl << endl;
		cout << "Password: ";
		cin >> Password;
		while(Password != (myuser->GetUsersVect())[myuser->GetUserRow()][1]){
			ForzenCounter++;
			if(ForzenCounter > 2){
				cout << "account being frozen!" << endl;
				myuser->FrozeAccount();
				delete myuser;
				return 0;
			}
			cout << "remaining " << 3 - ForzenCounter << " trails!" << endl;
			cout << "Password: ";
			cin >> Password;
		}
		ForzenCounter = 0;
		cout << "Password correct! " << endl << endl;

		delete myuser;
		myuser = new Librarian;
		int choice = -1;
		while (choice != 0) {
			choice = myuser->menuOption();
			if (choice == 1) {myuser->bookIn();}
			else if (choice == 2) {myuser->bookOut();}
			else if (choice == 3) {myuser->PrintBooksVect();}
			else if (choice == 0) {
				cout << "GOODBYE" << endl;
			}
			else {cout << "Invalid Choice!";
			 delete myuser;
			 return -1;}
		}
		delete myuser;
		return 0;
		
	}

	else {
		cout << "you are a customer!" << endl;
		cout << "Password: ";
		cin >> Password;
		while(Password != (myuser->GetUsersVect())[myuser->GetUserRow()][1]){
			ForzenCounter++;
			if(ForzenCounter > 2){
				cout << "account being frozen!" << endl;
				myuser->FrozeAccount();
				delete myuser;
				return 0;
			}
			cout << "remaining " << 3 - ForzenCounter << " trails!" << endl;
			cout << "Password: ";
			cin >> Password;
		}
		ForzenCounter = 0;
		cout << "Password correct! " << endl << endl;
    cout << "Would you like to checkout or return a book?(Enter \"checkout\" or \"return\") "<< endl;
    cin >> customerTemp;
    delete myuser;
    myuser = new Customer;
    while(temp == false) {
      if (customerTemp == "checkout") {
      myuser->bookOut();
      temp = true;
    }
    else if(customerTemp == "return") {
      myuser->bookIn();
      temp = true;
    }
    else {
      cout << "Invalid input, please input either checkout or return." << endl;
      cin >> customerTemp;
    }
    }
		delete myuser;
	}

	
	return 0;
}