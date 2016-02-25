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

void convertL(char& c);
void dumpstack(stack& s1, string& s);
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
	{
		cout << "Error in opening palindrome.txt (not found?) Exiting." << endl;
		exit(1);
	}

	ofstream fout;
	fout.open("NEWpalindrome.txt");
	if (fout.fail())
	{
		cout << "Error in opening the NEWpalindrome file. Exiting." << endl;
		exit(1);
	}

	while (!fin.eof())
	{
		first.clear();
		second.clear();
		getline(fin, first);
		holder = first;
		second.resize(checkstring(first));
		count = 0;

		for (unsigned i = 0; i < first.length(); i++)
		{
			c = first[i];
			if(isalpha(c))
			{
				convertL(c);
				second[count] = c;
				count++;
				s1.Push(c);
			}
		}

		first.resize(second.length());
		dumpstack(s1, first);
		if (first == second && first != "" && second != "")
		{
			cout << "The string \"" << holder << "\" is a palindrome." << endl;
			fout << holder << endl;
		}
		else if (first != "" && second != "")
			cout << "The string \"" << holder << "\" is NOT a palindrome." << endl;
	}
	fin.close();
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
