#include <iostream>
#include "Stack.hh"
using namespace std;
void ScrollTo(int to,LinkedStack<int> &before,LinkedStack<int> &after);

/*
 * I was originally going to make a class that turned a string into a DFA with
 * access to 2 stacks (equivalent to a turing machine). but I thought it would
 * obfuscate the procedure too much. and would take to long.(I'll probably try
 * something equivalent later.)
 *
 * this is effectively what it's procedure would have been.
 */
int main() {
	//2 stacks is enough storage/access to solve any computable problem
	LinkedStack<int> before;
	LinkedStack<int> after;

	//add marker for start of first input
	int digit=-1;
	before.push(digit);

	//load input
	cout<<"Enter a very large number: ";
	char in=0;
	while(in!='\n'){
		cin>>noskipws>>in;
		digit=in-'0';
		if(digit>=0&&digit<=9)
		before.push(digit);
	}

	//add marker for start of second input
	digit=-1;
	before.push(digit);

	//load input
	cout<<"Enter a very large number: ";
	in=0;
	while(in!='\n'){
		cin>>noskipws>>in;
		digit=in-'0';
		if(digit>=0&&digit<=9)
			before.push(digit);
	}
	int i,j,c=0;
	do{
		//scroll to end and take last digit of second input
		ScrollTo(-3,before,after);
		i=before.pop();
		if (i==-1){
			before.push(i);
			i=0;
		}
		//scroll end of first input and take last digit
		ScrollTo(-1,after,before);
		j=before.pop();
		if (j==-1){
			before.push(j);
			j=0;
		}
		//scroll to beginning
		ScrollTo(-3,after,before);
		//add digits and carry
		c=i+j+c;
		//get the least significant digit and add to front
		int toAdd=c%10;
		if(c!=0)
			before.push(toAdd);
		//compute carry term
		c/=10;

	}while(i!=0||j!=0);//if either of them has digets left, continue

	//scroll to start and print
	ScrollTo(-3,after,before);
	int temp=after.pop();
	while(temp>=0){
		cout<<temp;
		temp=after.pop();
	}
	return 0;
}
void ScrollTo(int to,LinkedStack<int> &before,LinkedStack<int> &after){
	while(!after.empty()){
		int i=after.pop();
		before.push(i);
		if(i==to)
			return;
	}
}
