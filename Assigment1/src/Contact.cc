#include"Contact.hh"

bool Contact::operator ==(const Contact& c) {
	return c.name==this->name;
}
std::ostream& operator<<(std::ostream& out, const Contact& p){
		 return out<<p.name<<" "<<p.number;

}

std::string Contact::getName() {
	return this->name;
}

int Contact::getNumber() {
	return this->number;
}
/*
 * Contact.cc
 *
 *  Created on: Oct 3, 2017
 *      Author: anthony
 */




