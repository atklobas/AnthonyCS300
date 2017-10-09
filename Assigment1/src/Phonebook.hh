/*
 * Phonebook.hh
 *
 *  Created on: Oct 3, 2017
 *      Author: anthony
 */

#ifndef PHONEBOOK_HH_
#define PHONEBOOK_HH_
#include "Contact.hh"
#include <iostream>
class Phonebook{
private:
	Contact *contacts;
	int insertIndex;
	int arraySize;
	void expland();
public:
	Phonebook(int size);
	Phonebook():Phonebook(1){};
	~Phonebook();
	void add(Contact);
	bool remove(Contact);
	bool remove(int);
	int indexOf(Contact);
	Contact search(std::string);
	bool remove(std::string);
	Contact get(int index);
	int size();
	void clear();
	//wil reduce array to minimum size that can contain current array
	void shrink();

};




#endif /* PHONEBOOK_HH_ */
