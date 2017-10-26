/*
 * Passenger.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: anthony
 */

#include "Passenger.hh"



Passenger::~Passenger() {
	// TODO Auto-generated destructor stub
}

bool Passenger::operator <(const Passenger& p) {
	return this->last<p.last;
}
bool Passenger::operator ==(const Passenger& p) {
	return this->last==p.last&&this->first==p.first;
}
bool Passenger::operator !=(const Passenger& p) {
	return this->last!=p.last||this->first!=p.first;
}
std::ostream& operator<<(std::ostream& out, const Passenger& p){
		 return out<<p.first<<" "<<p.last<<" ["<<p.address<<"] ["<<p.phone<<"]";

}

/*
std::ostream& operator<<(std::ostream& os, Passenger& p){


	return os;
}*/
