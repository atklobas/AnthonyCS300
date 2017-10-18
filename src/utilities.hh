/*
 * utilities.hh
 *
 *  Created on: Oct 18, 2017
 *      Author: anthony
 */

#ifndef SRC_UTILITIES_HH_
#define SRC_UTILITIES_HH_
#include <iostream>
void getAphabetic(std::string &buffer,std::string message="sorry, no numbers allowed: ",std::istream &in=std::cin);
void getInteger(int &buffer,std::string message="sorry, input must be int: ",std::istream &in=std::cin);
void getString(std::string &buffer,std::string message="this should never be displayed",std::istream &in=std::cin);
void getRegex(std::string &buffer, std::string regex,std::string message="sorry, that is invalid input: ",std::istream &in=std::cin);





#endif /* SRC_UTILITIES_HH_ */
