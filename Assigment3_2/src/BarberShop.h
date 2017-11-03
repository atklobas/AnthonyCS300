#ifndef BARBERSHOP_H_
#define BARBERSHOP_H_

#include <iostream>
#include "LinkedStack.h"

//needed to add this line
#include "Customer.h"

using namespace std;
class BarberShop {
	LinkedStack<Customer> s1;
	LinkedStack<Customer> s2;
public:
	void addCustomer(Customer&);
	Customer nextCustomer();
};

#endif /* BARBERSHOP_H_ */
