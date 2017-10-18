/*
 * utilities.cc
 *
 *  Created on: Oct 18, 2017
 *      Author: anthony
 */
#include"utilities.hh"
#include<iostream>
#include<regex>
#include<string>
using namespace std;

void getString(std::string& buffer, std::string message, std::istream& in) {
	getline(in,buffer);
}

void getRegex(std::string& buffer, std::string regex,std::string message, std::istream& in) {
	std::regex e(regex);
	buffer="test";
	getline(in,buffer);
	while(!std::regex_match(buffer, e)){
		cout<<message;
		getline(in,buffer);
	}
}
void getAphabetic(std::string& buffer,std::string message,std::istream& in) {
	getRegex(buffer,"^[^0-9]*$",message,in);
}

void getInteger(int& buffer,std::string message,std::istream& in) {
	string s;
	getRegex(s,"^-?[0-9]*$",message,in);
	buffer=std::stoi(s);
}



