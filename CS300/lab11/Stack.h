#ifndef __STACK_H__
#define __STACK_H__

#include <vector>

template<class T>
class Stack : private std::vector<T>{ //private inheretence of a vector for stack
public:
	Stack():std::vector<T>(){}
	~Stack(){}
	using std::vector<T>::empty;
	T top(){return std::vector<T>::back();}
	void push(T t){std::vector<T>::push_back(t);}
	void pop(){std::vector<T>::pop_back();}
};

#endif
