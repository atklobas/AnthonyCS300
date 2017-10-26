//============================================================================
// Name        : Assigment2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include "OrderedLinkedList.hh"
#include "Passenger.hh"
#include "utilities.hh"
using namespace std;
void addPassenger(OrderedLinkedList<Passenger> list[]);
void deletePassenger(OrderedLinkedList<Passenger> list[]);
void findPassenger(OrderedLinkedList<Passenger> list[]);
void listPassengers(OrderedLinkedList<Passenger> list[]);
int getFlightNumber();

int main() {
	OrderedLinkedList<Passenger> flights[4];
	cout<<"***DELTA AITLINES***"<<endl<<"Please choose an operation:"<<endl;

	while(true){
		cout<<"A (add) | S (Search) | D (Delete) | L (List) | Q (Quit): ";
		string in;
		getline(cin,in);
		char s=in[0]&0b11011111;//the difference between lower and upper case is 1 bit
		switch(s){
			case 'Q':
				//The dreaded goto
				goto quit;
			case 'A':
				addPassenger(flights);
				break;
			case 'S':
				findPassenger(flights);
				break;
			case 'D':
				deletePassenger(flights);
				break;
			case 'L':
				listPassengers(flights);

				break;
			default:
				cout<<"Sorry, I don't understand that input";
		}
	}
	quit:;
	cout<<"goodbye!"<<endl;

	return 0;
}

inline void addPassenger(OrderedLinkedList<Passenger>list[]) {
	int flightNumber;
	string fname,lname,address,phone;
	cout<<"Enter flight number: ";
	flightNumber=getFlightNumber();
	cout<<"Enter first name: ";
	getAphabetic(fname);
	cout<<"Enter last name: ";
	getAphabetic(lname);
	cout<<"Enter address: ";
	getString(address);
	cout<<"Enter phone: ";
	getString(phone);
	Passenger *p=new Passenger(fname,lname,address,phone);
	list[flightNumber/100-1].insert(*p);

}

inline void deletePassenger(OrderedLinkedList<Passenger>list[]) {
	int flightNumber;
	string fname,lname;
	cout<<"Enter flight number: ";
	flightNumber=getFlightNumber();
	cout<<"Enter first name: ";
	getAphabetic(fname);
	cout<<"Enter last name: ";
	getAphabetic(lname);
	Passenger p(fname,lname,"","");
	list[flightNumber/100-1].deleteNode(p);
}

inline void findPassenger(OrderedLinkedList<Passenger>list[]) {
	string fname,lname;
	cout<<"Enter first name: ";
	getAphabetic(fname);
	cout<<"Enter last name: ";
	getAphabetic(lname);
	for(int i=0;i<4;i++){
		Passenger tosearch(fname,lname,"","");
		Passenger *p=list[i].search(tosearch);
		if(p!=NULL){
			cout<<"Flight Number: "<<(i+1)*100<<endl;
			cout<<"First Name: "<<p->getFirst()<<endl;
			cout<<"Last Name: "<<p->getLast()<<endl;
			cout<<"Address: "<<p->getAddress()<<endl;
			cout<<"Phone: "<<p->getPhone()<<endl;
		}
	}
}

inline void listPassengers(OrderedLinkedList<Passenger> list[]) {
	int flightNumber;
	cout<<"Enter flight number: ";
	flightNumber=getFlightNumber();
	cout<<list[flightNumber/100-1];
}
inline int getFlightNumber(){
	string raw;
	getRegex(raw,"^[1-4]00$","sorry, that's not a valid flight number: ");
	return std::stoi(raw);
}
