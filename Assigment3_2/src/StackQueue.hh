/*
 * StackQueue.hh
 *
 *  Created on: Oct 31, 2017
 *      Author: anthony
 */

#ifndef STACKQUEUE_HH_
#define STACKQUEUE_HH_
#include "Stack.hh"

template<class T>
class StackQueue{
	LinkedStack<T> in;
	LinkedStack<T> out;
public:
	void enqueue(T& item);
	T dequeue();
	bool empty();
};

template<class T>
inline void StackQueue<T>::enqueue(T& item) {
	in.push(item);
}

template<class T>
inline T StackQueue<T>::dequeue() {
	if(out.empty()){
		while(!in.empty()){
			T item=in.pop();
			out.push(item);
		}
	}
	return out.pop();
}

template<class T>
inline bool StackQueue<T>::empty() {
	return in.empty()&&out.empty();
}

#endif /* STACKQUEUE_HH_ */
