#include <iostream>
using namespace std;

void reverseDigits(int i){
	cout<<i%10;
	if(i>9)
		reverseDigits(i/10);
}

int main() {
	cout<<"Enter a number: ";
	int i;
	cin>>i;
	reverseDigits(i);
	return 0;
}
