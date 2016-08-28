/*  Header file for class CharStack.
    Data:  Stack of Characters
    Purpose: examine if a string is a palindrome
*/

#ifndef __CHARSTACK_H__
#define __CHARSTACK_H__ //header guard added by author

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

class CharStack
{
	private:
		Stack myCharacters; // STL stack of chars.

	public:
		void StringToStack(const string & inStr);
		/*  StringToStack function reads the string into its private stack.
		    Precondition: check if a character is an alphabetic letter
		    Postcondition: only alphabetic letters of the string are in the private stack.
                           Other characters(like space, digit, punct, etc) can not be in the stack.

		*/

		friend ostream & operator << (ostream & out, const CharStack & CS);
		/* Overloaded output << operator.
		   Postcondition:  Contents of stack have been output to ostream out,
		                   on one line.  CS is unchanged.
		*/

		CharStack Reverse();
		/*  Reverse function empties its private stack out into another stack, causing the
		    order of the characters to be reversed.  Returns this new stack.
		    Precondition:  Private stack is not empty.
		    Postcondition:  If private stack is empty, displays error and returns.

		                    Otherwise: Returns new stack containing private stack's
		                    elements in reverse order.  Private stack is empty.
		*/

		bool IsEqual (CharStack & B);
		/* IsEqual function tests if both private stack and B's stack are the same.

		   Precondition:  Neither stack is empty.

		   Postcondition:  If either stack is empty,
		                   displays error message and returns.

		                   Otherwise:
		   				   Returns true if both stacks are the same, returns false otherwise.
		   				   Both the private stack and B's stack are empty.
		*/

};

#endif
