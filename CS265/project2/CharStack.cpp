/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/28/16
	Data Type: CharStack, a stack for type Char
*/

#include <iostream>
#include <string>
#include "CharStack.h"
#include "Stack.h"

using namespace std;

//--- Definition of StringToStack()
void CharStack::StringToStack(const string & inStr)
{
	unsigned slength;
	slength = inStr.length();

	for (unsigned i = 0; i < slength; i++)
	{
		if (isalpha(inStr[i])) //if the character is alphabetic, add to stack
		{
			if (isupper(inStr[i]))
				myCharacters.push(tolower(inStr[i]));
			else
				myCharacters.push(inStr[i]);
		}
	}
}

//--- Definition of friend overloaded << operator
ostream& operator<<(ostream& out, const CharStack& CS)
{
	CS.myCharacters.display(out);
	return out;
}

//--- Definition of Reverse()
CharStack CharStack::Reverse()
{
	CharStack c1;

	if (!myCharacters.empty())
	{
		while (!myCharacters.empty())
		{
			c1.myCharacters.push(myCharacters.top());
			myCharacters.pop();
		}

		return c1;
	}

	cerr << "\nCharStack member function \"Reverse()\" called while member stack \"myCharacters\" is empty.\n";
}

//--- Definition of IsEqual()
bool CharStack::IsEqual(CharStack& B)
{
	if (!myCharacters.empty() && !B.myCharacters.empty()) //If they aren't empty
	{
		while (!myCharacters.empty() && !B.myCharacters.empty() && myCharacters.top() == B.myCharacters.top()) //Check while they aren't empty & equal to eachother
		{
			myCharacters.pop();
			B.myCharacters.pop();
		}

		if (myCharacters.empty() && B.myCharacters.empty()) //If they are equal the whole time, they will both be empty. Therefore return True
			return true;
		else //Else it returns false
			return false;
	}

	cerr << "\nCharStack member function \"IsEqual(CharStack& B)\" tried to execute with either private empty stack or B empty stack.\n";
}
