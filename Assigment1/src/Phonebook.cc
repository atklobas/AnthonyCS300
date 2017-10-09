#include "Phonebook.hh"

Phonebook::Phonebook(int size) {
	this->contacts=new Contact[size];
	this->insertIndex=0;
	this->arraySize=size;
}
Phonebook::~Phonebook() {
	delete [] (this->contacts);
}
Contact Phonebook::get(int index) {
	if(index>=0&&index<this->insertIndex){
		return this->contacts[index];
	}
	return Contact();
}

void Phonebook::add(Contact contact) {
	if(this->insertIndex==this->arraySize){
		this->expland();
	}
	this->contacts[this->insertIndex]=contact;
	this->insertIndex++;
}


bool Phonebook::remove(Contact contact) {
	return this->remove(this->indexOf(contact));
}

bool Phonebook::remove(int index) {
	if(index>=0&&index<this->insertIndex){
		for(int i=index+1;i<this->insertIndex;i++){
			this->contacts[i-1]=this->contacts[i];
		}
		this->insertIndex--;
		return true;
	}
	return false;
}

int Phonebook::indexOf(Contact contact) {
	for(int i=0;i<this->insertIndex;i++){
		if(this->contacts[i]==contact){
			return i;
		}
	}
	return -1;
}

Contact Phonebook::search(std::string name) {
	for(int i=0;i<this->insertIndex;i++){
			if(this->contacts[i].getName()==name){
				return this->contacts[i];
			}
		}
	return Contact();
}
bool Phonebook::remove(std::string name){
	for(int i=0;i<this->insertIndex;i++){
		if(this->contacts[i].getName()==name){
			this->remove(i);
			return true;
		}
	}

	return false;
}

int Phonebook::size() {
	return this->insertIndex;
}

void Phonebook::clear() {
	delete [] (this->contacts);
	this->contacts=new Contact[10];
	this->insertIndex=0;
}

void Phonebook::shrink() {
	//TODO implement
}
void Phonebook::expland(){
	Contact *temp=this->contacts;
	this->arraySize*=2;
	this->contacts=new Contact[this->arraySize];
	for(int i=0;i<this->insertIndex;i++){
		this->contacts[i]=temp[i];
	}
	delete [] temp;

}
/*
 * Phonebook.cc
 *
 *  Created on: Oct 3, 2017
 *      Author: anthony
 */




