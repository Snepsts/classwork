#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <deque>

template<class T>
class Queue : private std::deque<T>{ //private inheretence dictates that deque
public:                              //is not exposed to/by the rest of the Queue class
	Queue():std::deque<T>(){}
	~Queue(){}
	using std::deque<T>::empty;
	using std::deque<T>::front;
	using std::deque<T>::back;
	void dequeue(){std::deque<T>::pop_front();} //this is basically a rename wrapper
	void enqueue(T t){std::deque<T>::push_back(t);} //^
};

#endif
