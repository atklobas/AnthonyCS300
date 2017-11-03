/*
 * BarberShop.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: anthony
 */

#include "BarberShop.h"
#include "Customer.h"

void BarberShop::addCustomer(Customer& item) {
	this->s1.push(item);
}

Customer BarberShop::nextCustomer() {
	//every item is pushed then popped twice, so even though its worst case is O(n) amortized its O(1)
	if(this->s2.empty()){
		while(!this->s1.empty()){
			Customer item=this->s1.pop();
			this->s2.push(item);
		}
	}
	return this->s2.pop();
}
