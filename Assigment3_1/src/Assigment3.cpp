#include <iostream>
#include "Stack.hh"
using namespace std;

int main() {
	LinkedStack<int> s;
	//if it survives this test, it'll survive anything
	for(int i=32;i>0;i-=2){
		s.push(i);
	}
	int num=0;
	while(!s.empty()){
		num++;
		if(num%2)
			s.push(num);
		cout<<s.pop()<<", ";
	}
	cout<<endl;
	//make sure it continues working after being emptied
	for(int i=32;i>0;i-=2){
		s.push(i);
	}
	num=0;
	while(!s.empty()){
		num++;
		if(num%2)
			s.push(num);
		cout<<s.pop()<<", ";
	}
	return 0;
}
