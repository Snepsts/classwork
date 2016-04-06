/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/29/16
	Data Type: ListQueue, a Queue of Lists
*/

#ifndef __LISTQUEUE_H__
#define __LISTQUEUE_H__

#include <iostream>
#include <list>

using namespace std;

const int SIZE = 10; //set the queue size to 10

template <typename T>
class listqueue
{
public:
	bool empty()
	{
		return (lst.empty());
	}

	int size()
	{
		int i = 0;
		for(typename list<T>::iterator it = lst.begin(); it != lst.end(); it++)
			i++;
		return i;
	}

	void enqueue(T item)
	{
		lst.push_back(item);
	}

	void dequeue()
	{
		lst.pop_front();
	}

	T front()
	{
		return lst.front();
	}

	T back()
	{
		return lst.back();
	}

	void display()
	{
		for(typename list<T>::iterator i = lst.begin(); i != lst.end(); i++)
			cout << *i << " ";
		cout << endl;
	}

private:
	list<T> lst;
};

#endif
