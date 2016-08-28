/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 4/26/16
	Data Type: NewString, a char array with functions to emulate a string
*/

#include "newstring.h"
#include <iostream>

newstring::newstring()
{//null constructor
	length = 0; c = new char[CAPACITY]; c[0] = '\0';
}

newstring::newstring(char nc[])
{//explicit constructor
	length = 0; c = new char[CAPACITY];

	for(int i = 0; i < CAPACITY; i++)
	{
		if(nc[i] == '\0')
		{
			c[i] = '\0';
			break;
		}
		else
		{
			c[i] = nc[i];
			length++;
		}
	}
}

newstring::newstring(const newstring& orig)
{//copy constructor
	c = new char[CAPACITY];

	for (int i = 0; i < CAPACITY; i++)
		c[i] = orig.c[i];

	length = orig.length;
}

newstring::~newstring()
{//destructor
	delete [] c; length = 0;
}

newstring newstring::operator=(const newstring& other)
{
	length = 0;

	for(int i = 0; i < CAPACITY; i++)
	{
		if(other.c[i] == '\0')
		{
			c[i] = '\0';
			break;
		}
		else
		{
			c[i] = other.c[i];
			length++;
		}
	}

	return *this;
}

void newstring::appendChar(const char& ac)
{
	c[length] = ac;
	length++;
	c[length] = '\0';
}
