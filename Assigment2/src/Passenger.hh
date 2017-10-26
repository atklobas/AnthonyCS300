/*
 * Passenger.h
 *
 *  Created on: Oct 18, 2017
 *      Author: anthony
 */

#ifndef PASSENGER_HH_
#define PASSENGER_HH_
#include<iostream>

class Passenger {
	std::string first;
	std::string last;
	std::string address;
	std::string phone;
public:
	Passenger(std::string first="", std::string last="",std::string address="", std::string phone=""):first(first),last(last),address(address),phone(phone){

	}
	virtual ~Passenger();
	bool operator< (const Passenger &p);
	bool operator== (const Passenger &p);
	bool operator!= (const Passenger &p);
	friend std::ostream& operator<<(std::ostream& out, const Passenger& p);

	const std::string& getAddress() const {
		return address;
	}

	const std::string& getFirst() const {
		return first;
	}

	const std::string& getLast() const {
		return last;
	}

	const std::string& getPhone() const {
		return phone;
	}
};




#endif /* PASSENGER_HH_ */

