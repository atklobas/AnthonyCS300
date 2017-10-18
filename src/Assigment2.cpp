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
		char s=in[0];
		switch(s){
			case 'Q':
			case 'q':
				//The dreaded goto
				goto quit;
			case 'A':
			case 'a':
				addPassenger(flights);
				break;
			case 'S':
			case 's':
				findPassenger(flights);
				break;
			case 'D':
			case 'd':
				deletePassenger(flights);
				break;
			case 'L':
			case 'l':
				for(int i=0;i<4;i++){
					cout<<(i+1)*100<<":"<<endl<<flights[i];
				}
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
	string fname,lname,address,phone;
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
}

inline void listPassengers(OrderedLinkedList<Passenger> list[]) {
}
inline int getFlightNumber(){
	string raw;
	getRegex(raw,"^[1-4]00$","sorry, that's not a valid flight number: ");
	return std::stoi(raw);
}
