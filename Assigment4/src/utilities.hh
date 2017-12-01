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

template<class T>
void mergeSortHelper(T *ary, int size, T *buffer){
	if(size>1){
		T *l1=buffer,*l1end=buffer+size/2;
		T *l2=l1end,*l2end=buffer+size;
		mergeSortHelper(l1,size/2,ary);
		mergeSortHelper(l2,(size+1)/2,ary+size/2);
		while(l1!=l1end&&l2!=l2end)
			*(ary++)=*l1<*l2?*(l1++):*(l2++);
		while(l1!=l1end)
			*(ary++)=*(l1++);
		while(l2!=l2end)
			*(ary++)=*(l2++);
	}
}
template<class T>
void mergeSort(T* ary, int size){
	T* buffer=new T[size];
	for(int i=0;i<size;i++){
		buffer[i]=ary[i];
	}
	mergeSortHelper(ary,size,buffer);
	delete [] buffer;
}





#endif /* SRC_UTILITIES_HH_ */
