#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "user.h"

class Librarian: public User {
	private:

	public:
		Librarian();
		int menuOption(); // librarian's main menu
		// Librarian can add new book to database
		void bookIn();
		// Librarian can remove book from database
		void bookOut();

};
#endif