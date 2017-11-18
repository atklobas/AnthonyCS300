#include <iostream>
#include "utilities.hh"
using namespace std;

void reverseDigits(int i){
	cout<<i%10;
	//tail recursion, effectively a loop, see: http://www.geeksforgeeks.org/tail-recursion/
	if(i>9)
		reverseDigits(i/10);
}

int main() {
	cout<<"Enter a number: ";
	int i;
	getInteger(i,"Sorry, You must input an Integer");
	reverseDigits(i);
	return 0;
}
