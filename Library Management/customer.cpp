#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "customer.h"
using namespace std;

void Customer::bookOut() {
  bool matched = false;
  int bookRow;
  string checkOutTitle;
  cout << "Input the title of the book that you want to checkout." << endl;
  PrintBooksVect();
  cin >> checkOutTitle;
  for (int i = 0 ; i < booksVect.size(); i++){
		if ((booksVect[i][0] == checkOutTitle) && booksVect[i][3] == "T"){
			matched = true;
			bookRow = i;
			break;
		}
    else if((booksVect[i][0] == checkOutTitle) && booksVect[i][3] == "F") {
      cout << "Book has already been checked out." << endl;
      break;
    }
	}
  if (matched == true) {
    booksVect[bookRow][3] = "F";
    cout << booksVect[bookRow][0] << " has been checked out." << endl;
    UpdateFiles();
  }
  else {
    cout << "This book doesn't exist in our library." << endl;
  }
  
}

void Customer::bookIn() {
  bool matched = false;
  int bookRow;
  string returnTitle;
  cout << "Input the title of the book that you wish to return." << endl;
  PrintBooksVect();
  cin >> returnTitle;
  for (int i = 0 ; i < booksVect.size(); i++){
		if ((booksVect[i][0] == returnTitle) && booksVect[i][3] == "F"){
			matched = true;
			bookRow = i;
			break;
		}
    else if((booksVect[i][0] == returnTitle) && booksVect[i][3] == "T") {
      cout << "Book has not been checked out yet." << endl;
      break;
    }
	}
  if (matched == true) {
    booksVect[bookRow][3] = "T";
    cout << booksVect[bookRow][0] << " has been returned." << endl;
    UpdateFiles();
  }
  else {
    cout << "This book doesn't exist in our library." << endl;
  }
}