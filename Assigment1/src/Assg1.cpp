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

int main() {
	ifstream input;
	Phonebook book=Phonebook(10);
	input.open ("phonebook.txt");

	while(!input.eof()){
		string fname,lname;
		int number;
		input>>fname;
		input>>lname;
		input>>number;
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
