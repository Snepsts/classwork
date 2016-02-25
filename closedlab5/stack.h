/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/25/16
	Data Type: Stack using vector to store values.
*/

#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <vector>

typedef char StackType;

using namespace std;

class stack
{
public:
	bool Empty();
	void Push(StackType item);
	void Pop();
	StackType Top();
	friend ostream& operator<<(ostream& out, stack s);
private:
	vector<StackType> v;
};

#endif
