/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/29/16
	Data Type: Containers, one big data type to do all stl operations on
*/

#ifndef __CONTAINERS_H__
#define __CONTAINERS_H__

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;

template <typename T>
class containers
{
public:
	containers();

	/* function vecsearchindex
	Receives: T type item
	Preconditions: N/A
	Postconditions: Returns index of where the item is in vector, else returns -1*/
	int vecsearchindex(T item);

	/* function vecsearchiterator
	Receives: T type item
	Preconditions: N/A
	Postconditions: Returns index of where the item is in vector, else returns -1 */
	int vecsearchiterator(T item);

	/* function
	Receives:
	Preconditions:
	Postconditions: */
	void addfirstsixints(int array[]);

	/* function
	Receives:
	Preconditions:
	Postconditions: */
	void displaydeque()
	{
		for(typename deque<T>::iterator i = deq.begin(); i != deq.end(); i++)
			cout << *i << endl;
	}

	/* function
	Receives:
	Preconditions:
	Postconditions: */
	void changebackvalue(T value)
	{
		typename deque<T>::iterator i = deq.end() - 1;
		*i = value;
	}

	/* function
	Receives:
	Preconditions:
	Postconditions: */
	void inputstreamfunction(istringstream ss)
	{
		for(typename list<T>::iterator i = lst.begin(); !ss.eof(); i++)
			ss >> *i;
	}

	/* function
	Receives:
	Preconditions:
	Postconditions: */
	void vectolist(vector<T> v);

	/* function
	Receives:
	Preconditions:
	Postconditions: */
	void changelstto(T item, T change);

	/* function
	Receives:
	Preconditions:
	Postconditions: */
	void displaylst()
	{
		for (typename list<T>::iterator i = lst.begin(); i != lst.end(); i++)
			cout << *i << " ";
		cout << endl;
	}

	/* function
	Receives:
	Preconditions:
	Postconditions: */
	void clearlst()
	{
		lst.clear();
	}

private:
	vector<T> vec;
	deque<T> deq;
	list<T> lst;
};

template<>
containers<char>::containers()
{
	vec.push_back('a'); vec.push_back('b'); vec.push_back('c'); vec.push_back('d'); vec.push_back('e');
}

template<>
containers<int>::containers()
{
	vec.push_back(5); vec.push_back(10); vec.push_back(15); vec.push_back(20); vec.push_back(25);
}

template <typename T>
int containers<T>::vecsearchindex(T item)
{
	for(int i = 0; i < vec.capacity(); i++)
	{
		if(vec[i] == item)
			return i;
	}

	return -1;
}

template <typename T>
int containers<T>::vecsearchiterator(T item)
{
	typename vector<T>::iterator begin = vec.begin();

	for(typename vector<T>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		if(*i == item)
			return distance(begin, i);
	}

	return -1;
}

template<>
void containers<int>::addfirstsixints(int array[])
{
	for(int i = 0; i < 6; i++)
	{
		if(i % 2 > 0)
			deq.push_front(array[i]);
		else
			deq.push_back(array[i]);
	}
}

template <typename T>
void containers<T>::vectolist(vector<T> v)
{
	typename list<T>::iterator ilst = lst.begin();
	for (typename vector<T>::iterator i = v.begin(); i != v.end(); i++)
		*ilst = *i;
		ilst++;
}

template <typename T>
void containers<T>::changelstto(T item, T change)
{
	typename list<T>::iterator lstb = lst.begin();
	typename list<T>::iterator lste = lst.end();
	if(find(lstb, lste, item) != lste)
	{
		typename list<T>::iterator location = find(lstb, lste, item);
		lst.erase(location);
		lst.insert(location, change);
	}
	else
		cerr << "[error]: Function \"changelstto\" failed, the parameter \"item\" (\"" << item << "\" in this case) could not be found in the list." << endl;
}

#endif
