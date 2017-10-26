/*
 * OrderedLinkedList.hh
 *
 *  Created on: Oct 18, 2017
 *      Author: anthony
 */

#ifndef ORDEREDLINKEDLIST_HH_
#define ORDEREDLINKEDLIST_HH_
#include "LinkedList.hh"
template <class T>
class OrderedLinkedList : public LinkedList<T>{
public:
	T* search(T&);
	virtual void insert(T&);
};

template<class T>
void OrderedLinkedList<T>::insert(T& object) {
	this->count++;
	//All problems in computer science can be solved by another level of indirection - David Wheeler
	node<T>** p = &(this->head);
	node<T> *temp = new node<T>;
	temp->data = object;
	while(*p!=NULL&&(*p)->data<object){
		p=&((*p)->next);//Don't worry, these are just random symbols
	}
	if(*p==NULL){
		this->last=temp;
	}
	temp->next=(*p);
	*p=temp;
}

template<class T>
T* OrderedLinkedList<T>::search(T& object) {
	node<T>* p =this->head;
	while(p!=NULL&&p->data!=object){
		p=p->next;
	}
	if(p!=NULL){
		return &(p->data);
	}
	return NULL;

}

#endif /* ORDEREDLINKEDLIST_HH_ */
