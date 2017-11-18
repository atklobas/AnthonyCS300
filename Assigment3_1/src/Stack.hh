/*
 * Stack.hh
 *
 *  Created on: Oct 31, 2017
 *      Author: anthony
 */
#include <assert.h>
#ifndef STACK_HH_
#define STACK_HH_

template<class T> struct node {
	T data;
	node<T>* next=NULL;
};
template<class T> class LinkedStack {
	node<T> *topNode=NULL;
public:
	void push(T&);
	T pop();
	T top();
	bool empty();
};

template<class T>
inline void LinkedStack<T>::push(T& item) {
	node<T> *n = new node<T>;
	n->data=item;
	n->next=topNode;
	topNode=n;
}

template<class T>
inline T LinkedStack<T>::pop() {
	assert(topNode!=NULL);//throws an error if topNode is null (stack is empty)
	node<T> *n=topNode;
	topNode=topNode->next;
	T data=n->data;
	delete n;
	return data;
}
template<class T>
inline T LinkedStack<T>::top() {
	assert(topNode!=NULL);//throws an error if topNode is null (stack is empty)
	return topNode->data;
}

template<class T>
inline bool LinkedStack<T>::empty() {
	return topNode==NULL;
}

#endif /* STACK_HH_ */
