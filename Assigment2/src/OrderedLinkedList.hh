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
	virtual void deleteNode(T&);
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
	while(p!=NULL&&p->data<object){
		cout<<"here";
		p=p->next;
	}
	if(p!=NULL && p->data==object){
		return &(p->data);
	}
	return NULL;

}

template<class T>
void OrderedLinkedList<T>::deleteNode(T& item) {
	if(this->head == NULL)
			cerr<<"empty list";
		else{
			if(this->head->data == item){
				node<T>* p = this->head;
				this->head = this->head->next;
				delete p;
				this->count--;
				if(this->head==NULL) this->last = NULL;
			}else{
				node<T>* p = this->head;
				node<T>* q = p->next;
				while(q!=NULL && q->data < item){
					p = q;
					q = q->next;
				}
				if(q!=NULL && q->data==item){
					p->next = q->next;
					this->count--;
					if(this->last == q) this->last = p;
					delete q;
				}
			}
		}
}

#endif /* ORDEREDLINKEDLIST_HH_ */
