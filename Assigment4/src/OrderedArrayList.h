#ifndef ORDEREDARRAYLIST_H_
#define ORDEREDARRAYLIST_H_

#include <iostream>
#include <algorithm>
#include "utilities.hh"
using namespace std;

template <class T>
class ArrayList{
	T *list;
	int insertIndex;
	int arraySize;
	void expland();
	void mergeSort(T* batch, int size);
public:
	ArrayList(int size);
	ArrayList():ArrayList(10000){};
		~ArrayList();
		//Order n^2 for random insert, order 1 for append
		void add(T);
		// order n+m*log(m) where n is current list and m is batch
		//Currently n+m^2 because of sorting
		void add(T* batch, int size);
		void insert(T t){add(t);}
		int print();
		int printTo(T);
		bool remove(T);
		bool remove(int);
		int indexOf(T&);
		T search(T);
		T find(T t){return search(t);}
		T get(int index);
		int size();
		void clear();
};

template<class T>
inline void ArrayList<T>::expland() {

	T *temp=this->list;
		this->arraySize*=2;
		this->list=new T[this->arraySize];
		for(int i=0;i<this->insertIndex;i++){
			this->list[i]=temp[i];
		}
		delete [] temp;
		if(this->insertIndex>=this->arraySize){
			this->expland();
		}
}

template<class T>
inline ArrayList<T>::ArrayList(int size) {
	this->list=new T[size];
	this->insertIndex=0;
	this->arraySize=size;
}

template<class T>
inline ArrayList<T>::~ArrayList() {
	delete [] (this->list);
}

template<class T>
inline void ArrayList<T>::add(T item) {
	cout<<insertIndex<<endl;
	this->insertIndex++;
	if(this->insertIndex>=this->arraySize){
		this->expland();
	}
	if(this->insertIndex==1){
		list[0]=item;
		return;
	}
	int i;
	for(i=this->insertIndex-2;list[i]>item;i--){
		list[i+1]=list[i];
	}
	list[i+1]=item;
}



template<class T>
inline void ArrayList<T>::add(T* batch, int size) {
	//sort incoming data
	::mergeSort(batch,size);
	//keep copy of old list
	T* old=this->list;
	int end=this->insertIndex;
	//allocate a buffer of correct size for the new list
	this->arraySize=insertIndex+size+1;
	this->list=new T[this->arraySize];
	this->insertIndex+=size;


	int oldi=0, newi=0;
	int index=0;
	while(oldi<end&&newi<size){
		if(old[oldi]<batch[newi]){
			list[index++]=old[oldi++];
		}else{
			list[index++]=batch[newi++];
		}
	}
	while(oldi<end){
		list[index++]=old[oldi++];
	}
	while(newi<size){
		list[index++]=batch[newi++];
	}
	delete [] old;


}


template<class T>
inline T ArrayList<T>::search(T item) {
	return list[indexOf(item)];
}

template<class T>
inline int ArrayList<T>::indexOf(T &item) {
	int index=0;
	while((this->list[index]!=item)&&index<this->insertIndex){
		index++;
	}

	/*int top=this->insertIndex-1;
		int bottom=0;
		int index=top>>1;
		int previous=0;
		while((this->list[index]!=item)&&(index!=previous)){
			previous=index;
			//cout<<top<<","<<bottom<<","<<index<<endl;
			if(list[index]>item){
				top=index;
			}else{
				bottom=index;
			}
			index=((top+bottom)>>1);
		}*/
		return index;
}

template<class T>
inline bool ArrayList<T>::remove(T item) {
	return this->remove(indexOf(item));
}

template<class T>
inline bool ArrayList<T>::remove(int index) {
	if(index>=0&&index<this->insertIndex){
	for(int i=index+1;i<this->insertIndex;i++){
		this->list[i-1]=this->list[i];
	}
	this->insertIndex--;
	return true;
	}
return false;
}


template<class T>
inline T ArrayList<T>::get(int index) {
	return this->list[index];
}

template<class T>
inline int ArrayList<T>::size() {
	return this->insertIndex;
}

template<class T>
inline int ArrayList<T>::print() {
	for(int i=0;i<this->insertIndex;i++){
		cout<<this->list[i]<<",";
	}
	return this->insertIndex;
}

template<class T>
inline int ArrayList<T>::printTo(T) {
	int i=0;
	for(;i<this->insertIndex;i++){
			cout<<this->list[i]<<",";
		}
		return i;
}

template<class T>
inline void ArrayList<T>::clear() {
	delete [] (this->list);
		this->list=new T[10];
		this->insertIndex=0;
}


#endif
