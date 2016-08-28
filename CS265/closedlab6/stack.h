/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/25/16
	Data Type: Stack using vector to store values.
	Functions:
		Empty: Returns true if stack is empty, else returns false.
		Push: Adds StackType to top of stack.
		Pop: Removes top item from stack.
		Top: Returns StackType from top of stack.
friend	ostream& operator<<: Outputs top item of stack.
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
	/* function Empty
		Task: To see if a stack is empty.
		Receives: N/A
		Preconditions: N/A
		Postconditions: Returns true if stack is empty. Else returns false. */
	bool empty();

	/* function Push
		Task: To add an item to the top of the stack
		Receives: StackType item
		Preconditions: Item must be of StackType
		Postconditions: Item is now on top of stack */
	void push(StackType item);

	/* function Pop
		Task: To remove the top part of the stack.
		Receives: N/A
		Preconditions: Stack must NOT be empty
		Postconditions: Stack's top is one lower, unless there is none, then it is empty
		If stack is empty, will terminate the program. */
	void pop();

	/* function Top
		Task: To display the top item
		Receives: N/A
		Preconditions: Stack shouldn't be empty
		Postconditions: Returns the Top item of stack */
	StackType top();

	/* overloaded << operator
		Task: To easily display in main
		Receives: stack s and an ostream for Outputs
		Preconditions: Stack cannot be empty
		Postconditions: Outputs stack.Top(); */
	friend ostream& operator<<(ostream& out, stack s);

private:
	vector<StackType> v;
};

#endif
