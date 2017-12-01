/*
 * Contact.cc
 *
 *  Created on: Oct 3, 2017
 *      Author: anthony
 */

#ifndef CONTACT_CC_
#define CONTACT_CC_
#include <iostream>

class Contact{
	std::string name;
	int number;
public:

	Contact(std::string s,int number){
		name=s;
		this->number=number;
	}
	Contact():Contact("empty",0){}
	bool operator==(const Contact& c);
	bool operator!=(const Contact& c);
	bool operator<(const Contact& c);
	bool operator>(const Contact& c);
	bool operator<=(const Contact& c);
	std::string getName();
	int getNumber();
	friend std::ostream& operator<<(std::ostream& out, const Contact& p);
};




#endif /* CONTACT_CC_ */
