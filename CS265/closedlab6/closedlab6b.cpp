/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/8/16
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>
#include "Queue.h"
#include "stack.h"

using namespace std;

/* function ispalindrome
Purpose: To check if the string is a palindrome and empty the Queue/stack
Receives: Queue and stack
Preconditions: Queue and Stack should both have the same string dumped into them
Postconditions: Returns true if they both are the same, else returns false. */
bool ispalindrome(Queue& Q, stack& S);

int main()
{
	Queue Q;
	stack S;
	string s;
	char c;

	ifstream fin;
	fin.open("palindrome.txt");
	if (fin.fail())
	{
		cerr << "Opening palindrome.txt has failed.";
		exit(1);
	}

	while(!fin.eof())
	{
		getline(fin, s);

		if (s != "") //Check for the last line at end of file.
		{
			for (unsigned i = 0; i < s.length(); i++)
			{
				c = s[i];
				if (isalpha(c))
				{
					if (isupper(c))
						c = tolower(c);
					S.push(c);
					Q.enqueue(c);
				}
			}

		if (ispalindrome(Q, S))
			cout << "The line " << s << " is a palindrome." << endl;
		else
			cout << "The line " << s << " is NOT a palindrome." << endl;
		}
	}

	fin.close();

	return 0;
}

bool ispalindrome(Queue& Q, stack& S)
{
	int a = Q.size();
	bool rbool = true;

	for (int i = 0; i < a; i++)
	{
		if (Q.front() != S.top())
			rbool = false;
		Q.dequeue();
		S.pop();
	}

	return (rbool);
}
