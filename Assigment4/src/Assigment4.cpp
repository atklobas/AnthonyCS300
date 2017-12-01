
#include <iostream>
#include <fstream>
#include "utilities.hh"
#include "Contact.hh"
#include "Phonebook.hh"
#include "OrderedArrayList.h"
#include <ctime>
using namespace std;
void benchmark(Phonebook &book){
	/*
	 *BinarySearchTree
	took: 1.2e-05 seconds
	took: 1.1e-05 seconds
	took: 1.1e-05 seconds
	took: 1.2e-05 seconds
	took: 1.1e-05 seconds
	took: 1e-05 seconds
	took: 9e-06 seconds
	took: 9e-06 seconds
	took: 9e-06 seconds

	//Data has to be loaded in batches or orderedarraylist is very slow to populate
	 *OrderedArrayList
	took: 1.9e-05 seconds
	took: 1.5e-05 seconds
	took: 3.1e-05 seconds
	took: 1.7e-05 seconds
	took: 1.7e-05 seconds
	took: 1.4e-05 seconds
	took: 1.2e-05 seconds
	took: 1.3e-05 seconds
	took: 1.4e-05 seconds

	 *UnorderedArrayList
	 took: 0.04961 seconds
	took: 0.047588 seconds
	took: 0.046943 seconds
	took: 0.048662 seconds
	took: 0.048282 seconds
	took: 0.04727 seconds
	took: 0.048401 seconds
	took: 0.049119 seconds
	took: 0.046802 seconds
	 */

	Contact *temp= new Contact("a",0);
	clock_t begin=clock();
	for(int i=0;i<26;i++){
		//temp->name[0]=('a'+i);
		//book.database.indexOf(*temp);
		Contact c=book.search(*temp);
	}

	clock_t end=clock();
	delete temp;
	double time=double(end-begin)/CLOCKS_PER_SEC;
	cout<<"took: "<<time<<" seconds"<<endl;
}


int main() {
	Phonebook book=Phonebook();

	cout<<"***MY PHONEBOOK APPLICATION***"<<endl<<"Please choose an operation:"<<endl;

	while(true){
		cout<<"A(Add) | L(Load) | S(Search) | P(Print) |F(Filter) | Q(Quit): ";
		string input;
		cin >> input;
		//dark magic to convert lowercase to uppercase
		input[0]=input[0]&0b11011111;
		if(input=="L"){
			cout<<"Enter filename:";
			string filename;
			cin>>filename;
			ifstream input;
			input.open (filename);
			if(input.is_open()){
				cout<<"Loading file "<<filename<<"..."<<endl;
				while(!input.eof()){
					string fname,lname;
					int number;
					input>>fname;
					input>>lname;
					//user input can be flawed, but the program will exit if the file format is invalid
					input>>number;
					if(fname.empty()){
						continue;
					}
					Contact *c=new Contact(fname+" "+lname,number);
					book.add(*c);
				}
				cout<<"Loaded "<<filename<<endl;
			}else{
				cout<<"404 File not found"<<endl;
			}
			input.close();
		}else if(input=="Q"){
			break;//break out of loop
		}else if(input=="A"){
			string fname,lname;
			int number;
			cout<<"Enter name: ";
			cin>>fname;
			cin>>lname;
			cout<<"Phone number: ";
			getInteger(number);
			//create contact from input and add to phonebook
			Contact *c= new Contact(fname+" "+lname,number);
			book.add(*c);
		}else if(input=="S"){
			string fname,lname;
			cout<<"Enter name: ";
			cin>>fname;
			cin>>lname;
			//create a temp contact to compare name against,
			Contact temp(fname+" "+lname,0);
			//search for contact with same name
			Contact c=book.search(temp);

			//if the returned contact has an empty name, its because the contact is empty
			if(c.getName()!=""){
				cout<<"Phone number: "<<c.getNumber()<<endl;
			}else{
				cout<<"Contact not found"<<endl;
			}
		}else if (input=="P"){
			book.print();
		}else if (input=="F"){
			/* filter prints out any contacts alphabetically lower than the input,
			 * even if that input is not in the phonebook, "B" "B" would print out
			 * any contact with a name starting in A
			 */
			string fname,lname;
			cout<<"Enter name: ";
			cin>>fname;
			cin>>lname;
			book.printTo(Contact(fname+" "+lname,0));
		}else{
			cout<<"Sorry I don't recognize that input"<<endl;
		}
		cout<<endl;
	}
	//cannot save here because i woudln't know which file to save to
	cout<<"Goodbye";

	return 0;
}
