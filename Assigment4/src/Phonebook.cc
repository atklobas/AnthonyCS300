#include "Phonebook.hh"
#include <iostream>;
using namespace std;
void Phonebook::print() {

	int contacts=database.print();
		cout<<contacts<<" contacts...";
}

void Phonebook::printTo(Contact contact) {

	int contacts=database.printTo(contact);
	cout<<contacts<<" contacts...";
}

void Phonebook::add(Contact &contact) {
	this->database.insert(contact);
}

bool Phonebook::remove(Contact &contact) {
	return false;;
}

Contact Phonebook::search(Contact &contact) {
	return(database.find(contact));
}
