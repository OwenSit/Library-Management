#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "librarian.h"

using namespace std;

Librarian::Librarian():User() {};

int Librarian::menuOption() {
	int choice;
	cout << "\nChoose an option below (enter number): " << endl;
	cout << "(1) Add book to library" << endl;
	cout << "(2) Remove book from library" << endl;
	cout << "(3) See book database" << endl;
	cout << "(0) Log out" << endl;
	cin >> choice;
	return choice;
}

void Librarian::bookIn() {
	string name;
	string author;
	string year;

	cout << endl;
	cout << "Enter book name (use underscores for spaces_): " << endl;
	cin >> name;
	cout << "Enter author's name (use underscoress for spaces_): " << endl;
	cin >> author;
	cout << "Enter year of publication: " << endl;
	cin >> year;

	vector<string> newbook{name, author, year, "T"};
	booksVect.push_back(newbook);
	UpdateFiles();

	cout << "\nBook Added Successfully!" << endl;
}

void Librarian::bookOut() {
	string name;

	cout << "-------------------------------------" << endl;
	cout << "Type name of book you wish to remove:" << endl;
	cout << "-------------------------------------" << endl;
	PrintBooksVect();
	cout << endl;
	cin >> name;

	//remove book
	int c=0;
	for (int i=0; i<booksVect.size(); i++) {
		if (booksVect[i][0] == name) {
			booksVect.erase(booksVect.begin() + i);
			UpdateFiles();
			cout << "\nBook Removed Successfully" << endl;
			c=0;
			break;
		}
		else {
			c++;
		}
	}

	if (c >= booksVect.size()) {
		cout << "Book not found!" << endl;
		exit(1);
	}
}