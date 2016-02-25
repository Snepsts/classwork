/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/25/16
	Data Type: Stack using vector to store values.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include "stack.h"

using namespace std;

bool stack::Empty()
{
	return v.empty();
}

void stack::Push(StackType item)
{
	v.push_back(item);
}

void stack::Pop()
{
	if (!v.empty())
	{
		v.pop_back();
	}
	else
	{
		cerr << "Error: Stack is already empty.";
	}
}

StackType stack::Top()
{
	if (!v.empty())
	{
		return v.back();
	}
	else
	{
		cerr << "Error: Stack is empty.";
		exit(1);
	}
}

ostream& operator<<(ostream& out, stack s)
{
	out << s.Top();
	return out;
}
