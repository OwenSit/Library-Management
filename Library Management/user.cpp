#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <fstream>
#include <vector>
#include "user.h"
using namespace std;


User::User(){  //default constructor set generator 2 2-d vectors
	userRow = 0;
	userCol = 0;
	usersVect = File2Vec("accounts.txt");
	booksVect = File2Vec("books.txt");
}

void User::PrintUsersVect(){
	for (int i = 0; i < usersVect.size(); ++i){
		for (int j = 0; j < usersVect[i].size(); ++j){
			cout << usersVect[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

void User::PrintBooksVect(){
  cout << left << setw(25) << "Book Title";
  cout << setw(20) << "Author";
  cout << setw(15) << "Published";
  cout << "Availability" << endl;
	for (int i = 0; i < booksVect.size(); ++i){
    cout << left << setw(25) << booksVect[i][0];
		cout << setw(20) << booksVect[i][1];
    cout << setw(15) << booksVect[i][2];
    cout << booksVect[i][3];
		cout << endl;
	}
	return;
}

int User::GetFileRows(string FileName){
	class error{};
	try{
		int rows = 0;
		ifstream ifs;
		string tempStr;
		ifs.open(FileName);
		if(!ifs.is_open()){
			throw error();
		}
		while(!ifs.eof()){
			getline(ifs, tempStr);
			rows++;
		}
		ifs.close();
		return rows;
	}
	catch(error e){
		cout << "file is not open!" << endl;
		return -1;
	}	
}

int User::GetFileCols(string FileName){
	class error{};
	try{
		int cols = 1;
		ifstream ifs;
		string tempStr;
		ifs.open(FileName);
		if(!ifs.is_open()){
			throw error();
		}
		getline(ifs, tempStr);
		for (int i = 0;tempStr[i]!='\0'; ++i){
			if(tempStr[i] == ' '){
				cols++;
			}
		}
		ifs.close();
		return cols;
		}
	catch(error e){
		cout << "file is not open!" << endl;
		return -1;
	}
}

vector<vector<string> > User::File2Vec(string fileName){
	class error{};
	int columns = GetFileCols(fileName);
	int rows = GetFileRows(fileName);
	vector<vector<string> > myVect(rows); // set #of rows of the 2d array
	try{
		string tempStr;
		ifstream ifs;
		ifs.open(fileName);
		if(!ifs.is_open()){
			throw error();
		}

		for (int i = 0; i < rows; ++i){
			myVect[i] = vector<string> (columns);  //set columns
		}
		while (!ifs.eof()){
			for(int i = 0; i < rows; ++i){
				for (int j = 0; j < columns; ++j){
					ifs >> myVect[i][j];
				}
			}	
		}
		ifs.close();
		return myVect;
	}
	catch(error e){
		cout << "file is not open!" << endl;
		return myVect;
	}
}

char User::GetUserType(string userName){
	bool matched = false; 
	userRow = 0; 
	userCol = 0;
	//check if input name match the user name
	for (int i = 0 ; i < usersVect.size(); ++i){
		if (usersVect[i][0] == userName){  //compare with the names on the first column
			matched = true;
			userRow = i;
			break;
		}
	}
	//FIRST STEP: IF THE NAME DOESN'T MATHCH:
	if (matched == false){
		return '0';
	}

	else{
		//SECOND STEP: IF THE ACCOUNT IS FORZEN OR NOT:
		if(usersVect[userRow][3] == "F"){
			return 'F';
		}
		else { // if the account is valid:
			//THIRD STEP: IF THE USER IS A librarian:
			if (usersVect[userRow][2] == "l"){
				return 'l';
			} 
			// FORTH STEP: IF THE USER IS A CUSTOMER:	
			if (usersVect[userRow][2] == "c") {
				return 'c';
			}
		}
	}
	return '1';
}
void User::FrozeAccount(){
	usersVect[userRow][3] = "F";
	UpdateFiles();
	return;
}
void User::UpdateFiles(){
	ofstream ofs;
	ofs.open("books.txt");  //updating file "books.txt"
	for (int i = 0; i < booksVect.size() -1; ++i){
		for (int j = 0; j < booksVect[i].size() - 1; ++j){
			ofs << booksVect[i][j] << " ";
		}
		ofs << booksVect[i][booksVect[i].size()-1];
		ofs << endl;
	}
	for (int j = 0; j < booksVect[0].size() - 1; ++j) {
		ofs << booksVect[booksVect.size()-1][j] << " "; 
	}
	ofs << booksVect[booksVect.size()-1][booksVect[0].size()-1];
	ofs.close();


	ofs.open("accounts.txt");  //updating the file "accounts.txt"
	for (int i = 0; i < usersVect.size() - 1; ++i){
		for (int j = 0; j < usersVect[i].size() - 1; ++j){
			ofs << usersVect[i][j] << " ";
		}
		ofs << usersVect[i][usersVect[i].size()-1];
		ofs << endl;
	}
	for (int j = 0; j < usersVect[0].size() - 1; ++j) {
		ofs << usersVect[usersVect.size()-1][j] << " "; 
	}
	ofs << usersVect[usersVect.size()-1][usersVect[0].size()-1];
	ofs.close();
	return;
}

