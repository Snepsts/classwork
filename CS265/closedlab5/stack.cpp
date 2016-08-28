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
{ //Task: To return true/false based on whether or not the stack is empty
	return v.empty();
}

void stack::Push(StackType item)
{ //Task: To add "StackType item" to top of stack
	v.push_back(item);
}

void stack::Pop()
{ //Task: Remove top item from stack
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
{ //Task: Return the item that's on the top
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
{ //Task: Simplify output in main
	out << s.Top();
	return out;
}
