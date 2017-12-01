/*
 * Phonebook.hh
 *
 *  Created on: Oct 3, 2017
 *      Author: anthony
 */

#ifndef PHONEBOOK_HH_
#define PHONEBOOK_HH_
#include "Contact.hh"
#include "BinarySearchTree.h"
#include <iostream>
class Phonebook{
private:
	BinarySearchTree<Contact> database;
public:
	void add(Contact&);
	bool remove(Contact&);
	Contact search(Contact&);
	void print();
	void printTo(Contact);
};




#endif /* PHONEBOOK_HH_ */
