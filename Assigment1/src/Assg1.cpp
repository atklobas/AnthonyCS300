//============================================================================
// Name        : Assg1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "Contact.hh"
#include "Phonebook.hh"
using namespace std;

/*
 * This code assumes that every contact has a first and last name,
 * seperated by a single space. It was my intent to Scan till a number
 * came up but that seemed outside the scope of this project.
 *
 * to simplify the dynamic memory allocation, empty contacts are intialized to
 * Name:empty
 * Number:0
 *
 * however since I make the assumtion that all contacts have first and last name
 * there is no way for a collision to occur and have a legitimate contact be viewed
 * as empty
 *
 */

int main() {
	//needs to be a c style string
	char filename[]="phone.txt";
	ifstream input;
	Phonebook book=Phonebook(10);
	input.open (filename);
int te=0;
	while(!input.eof()){
		string fname,lname;
		int number;
		input>>fname;
		input>>lname;
		input>>number;
		if(fname.empty()){
			continue;
		}
		book.add(Contact(fname+" "+lname,number));
	}
	cout<<"***MY PHONEBOOK APPLICATION***"<<endl<<"Please choose an operation:"<<endl;

	while(true){
		cout<<"A (add) | S (Search) | D (Delete) | L (List) | Q (Quit): ";
		string input;
		cin >> input;
		if(input=="L"){
			for(int i=0;i<book.size();i++){
				cout<<book.get(i)<<endl;
			}
		}else if(input=="Q"){
			break;
		}else if(input=="A"){
			string fname,lname;
			int number;
			cout<<"Enter name: ";
			cin>>fname;
			cin>>lname;
			cout<<"Phone number: ";
			cin>>number;
			book.add(Contact(fname+" "+lname,number));
		}else if(input=="S"){
			string fname,lname;
			cout<<"Enter name: ";
			cin>>fname;
			cin>>lname;
			Contact c=book.search(fname+" "+lname);
			if(c.getName()!="empty"){
				cout<<"Phone number: "<<c.getNumber()<<endl;
			}else{
				cout<<"Contact not found"<<endl;
			}
		}else if(input=="D"){
			string fname,lname;
			cout<<"Enter name: ";
			cin>>fname;
			cin>>lname;
			bool success=book.remove(fname+" "+lname);
			if(success){
				cout<<"Contact removed"<<endl;
			}else{
				cout<<"Contact not found"<<endl;
			}
		}
		cout<<endl;
	}
	//close, output and close that
	input.close();
	ofstream output;
	output.open(filename);
	for(int i=0;i<book.size();i++){
		output<<book.get(i)<<endl;
	}
	output.close();
	cout<<"Goodbye";
	//for(int i=0;i<10;i++){
	//	book.add(Contact("contact",i));
	//}
	//book.remove(Contact("contact",7));
	/*for(int i=0;i<book.size();i++){
		cout<<book.get(i)<<endl;
	}*/
	return 0;
}
