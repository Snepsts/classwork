/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 4/26/16
	Data Type: NewString, a char array with functions to emulate a string
*/

#ifndef __NEWSTRING_H__
#define __NEWSTRING_H__

const int CAPACITY = 30;

class newstring
{
public:
	/*null constructor
	Preconditions: N/A
	Receives: N/A
	Postconditions: initializes the object with null array */
	newstring(); //null constructor

	/*explicit constructor
	Preconditions: Must be called explicitly
	Receives: char array nc[]
	Postconditions: initializes the object with predefined array*/
	newstring(char nc[]); //explicit constructor

	/*copy constructor
	Preconditions: Must be called explicitly
	Receives: newstring orig
	Postconditions: initializes the object with predefined newstring */
	newstring(const newstring& orig); //copy constructor

	/*destructor
	Preconditions: N/A
	Receives: N/A
	Postconditions: Deletes and deallocates memory */
	~newstring(); //destructor

	/*overloaded operator=
	Preconditions: N/A
	Receives: Another newstring object
	Postconditions: makes local newstring equal to object other newstring*/
	newstring operator=(const newstring& other);

	/*function appendChar
	Preconditions: N/A
	Receives: Another char ac
	Postconditions: Adds ac to the end of the newstring array*/
	void appendChar(const char& ac);

private:
	char *c;
	unsigned int length;
};

#endif
