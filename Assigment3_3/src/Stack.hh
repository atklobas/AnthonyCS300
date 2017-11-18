/*
 * Stack.hh
 *
 *  Created on: Oct 31, 2017
 *      Author: anthony
 */

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
	node<T> *n=topNode;
	topNode=topNode->next;
	T data=n->data;
	delete n;
	return data;
}

template<class T>
inline bool LinkedStack<T>::empty() {
	return topNode==NULL;
}

#endif /* STACK_HH_ */
