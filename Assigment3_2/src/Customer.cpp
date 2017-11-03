/*
 * Customer.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: anthony
 */

#include "Customer.h"
#include <string>
using namespace std;
Customer::Customer(string fname, string lname) {
	this->fname=fname;
	this->lname=lname;
}

std::string Customer::getName() {
	return fname+" "+lname;
}
