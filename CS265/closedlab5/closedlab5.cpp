/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/25/16
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "stack.h"

using namespace std;

/* Function convertL
	Task: Convert letter (char c) to a lowercase if need be
	Receives: Char c
	Preconditions: N/A
	Postconditions: If c is capital, it is converted to lowercase
*/
void convertL(char& c);

/* Function dumpstack
	Task: To empty the stack into
	Receives: Stack & a string
	Preconditions: Stack should be full & string should be properly resized
	Postconditions: Stack is empty into string
*/
void dumpstack(stack& s1, string& s);

/* Function checkstring
	Task: Returns size of string with only alpha characters
	Receives: A string
	Preconditions: String must have something in it
	Postconditions: Returns string size w/o space/punctuation
*/
int checkstring(string s);

int main()
{
	stack s1;
	string first, second, holder;
	char c;
	int count;

	ifstream fin;
	fin.open("palindrome.txt");
	if (fin.fail())
	{ //Check if it fails
		cout << "Error in opening palindrome.txt (not found?) Exiting." << endl;
		exit(1);
	}

	ofstream fout;
	fout.open("NEWpalindrome.txt");
	if (fout.fail())
	{ //Check if it fails
		cout << "Error in opening the NEWpalindrome file. Exiting." << endl;
		exit(1);
	}

	while (!fin.eof()) //While the file isn't at it's end
	{
		first.clear(); //For every loop while makes, reset first and second strings
		second.clear();
		getline(fin, first); //Since it's on a line by line basis, we use getline
		holder = first; //Save first as holder for later usage
		second.resize(checkstring(first)); //Resize the second based on what the size of first w/o alphabetic chars is
		count = 0; //Restart count every time

		for (unsigned i = 0; i < first.length(); i++)
		{
			c = first[i];
			if(isalpha(c)) //Check if it isn't a space/punctuation
			{
				convertL(c); //Convert to lowercase
				second[count] = c; //Second string (as char array) adds each alpha char
				count++; //count up every time
				s1.Push(c); //Push each char c to stack
			}
		}

		first.resize(second.length()); //Resize to second since it's going to have the same number of chars
		dumpstack(s1, first); //Dump the stack into the string (adds all letters in second backwards into first)
		if (first == second && first != "" && second != "") //if they're the same, add to output/file
		{
			cout << "The string \"" << holder << "\" is a palindrome." << endl;
			fout << holder << endl;
		}
		else if (first != "" && second != "") //Else say it isn't, if it's null ("") don't do anything
			cout << "The string \"" << holder << "\" is NOT a palindrome." << endl;
	}
	fin.close(); //close the files
	fout.close();

	return 0;
}

void convertL(char& c)
{
	if (isupper(c))
		c = tolower(c);
}

void dumpstack(stack& s1, string& s)
{
	int i;
	i = 0;
	while (!s1.Empty())
	{
		s[i] = s1.Top();
		i++;
		s1.Pop();
	}
}

int checkstring(string s)
{
	int count;
	count = 0;
	for (unsigned i= 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
			count++;
	}

	return count;
}
