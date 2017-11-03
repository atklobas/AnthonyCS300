/*
 * Customer.h
 *
 *  Created on: Nov 2, 2017
 *      Author: anthony
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

class Customer {
	std::string fname,lname;
public:
	Customer(std::string="",std::string="");
	std::string getName();
};

#endif /* CUSTOMER_H_ */
