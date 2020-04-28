#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "user.h"

class Customer: public User {
	private:

	public:
		// Customer can return book
		void bookIn();
		// Customer can borrow book
		void bookOut();

};

#endif
