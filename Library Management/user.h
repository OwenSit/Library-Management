#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#ifndef USER_H
#define USER_H

class User {
	protected:
		// Insert Data Members Here
		vector<vector<string> > usersVect; // vector used to store the user info
		vector<vector<string> > booksVect; //vector for storing the books' info
		int userRow; // user to store the row position of the uesr in the 2d verctor SHARE BETWEEN OBJECTS
		int userCol; // user to store the column position of the uesr in the 2d verctor SHARE BETWEEN OBJECTS


	public:
		User(); //default constructor 
		// User(string accounts, string books);
		virtual int menuOption(){return 1;};
		virtual void bookIn(){return;};
		virtual void bookOut(){return;};
		int GetFileRows(string FileName); // get the row number of the file;
		int GetFileCols(string FileName); // get the col number of the file;
		vector<vector<string> > File2Vec(string fileName); // turn user info file into a 2d vector
		char GetUserType(string name);
		int GetUserRow(){return userRow;};
		int GetuesrCol(){return userCol;};
		vector<vector<string> > GetUsersVect(){return usersVect;};
		vector<vector<string> > GetBooksVect(){return booksVect;};
		void PrintUsersVect();
		void PrintBooksVect();
		void FrozeAccount();
		void UpdateFiles(); //update both "books.txt" and "account.txt";
};

#endif