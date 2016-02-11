/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/11/16
	Data Type: Date, an object that contains members year, month, and day.
	Operations:
		date(); - The Constructor
		date(unsigned m0nth, unsigned d4y, unsigned y3ar); - Explicit Constructor
		setYear(unsigned m0nth, unsigned d4y, unsigned y3ar); - Mutator
		get[variable](); - Accessors. Return their information
		overloaded < operator - returns true if date D is bigger than the other.
	Else returns false.
friend	overloaded << operator - outputs the date for easy main function reading
friend	overloaded >> operator - allows simplified main function input
*/

#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>

class date
{
public:
	//function date(); - constructor
	date();
	/* function date();
	task: explicitly construct the object
	preconditions: Needs m0nth, d4y, and y3ar values passed
	postconditions: date obj's month, day, and year are set */
	date(unsigned m0nth, unsigned d4y, unsigned y3ar);
	/* function setYear();
	task: set the date obj members after they've been constructed
	preconditions: m0nth, d4y, and y3ar unsigned integers parameters
	postconditions: date members set to appropriate values */
	void setYear(unsigned m0nth, unsigned d4y, unsigned y3ar);
	/* function getYear();
	task: return the date member year
	preconditions: N/A
	postconditions: N/A */
	int getYear();
	/* function getMonth();
	task: return the date member month
	preconditions: N/A
	postconditions: N/A */
	int getMonth();
	/* function getDay();
	task: return the date member day
	preconditions: N/A
	postconditions: N/A */
	int getDay();
	/* function operator<();
	task: evaluate whether date D is greater than current date obj
	preconditions: date D & main date obj have been set appropriately
	postconditions: returns true if D is greater, otherwise false */
	bool operator<(date D);
	/* function istream operator>>();
	task: enter date member values with >> operator
	preconditions: Must be used on a date
	postconditions: date D is set with user-defined values */
	friend std::istream& operator>>(std::istream& in, date& D);
	/* function ostream operator<<();
	task: output date with << operator
	preconditions: date D must be set appropriately
	postconditions: date D is printed to screen */
	friend std::ostream& operator<<(std::ostream& out, date D);

private:
	unsigned month, day, year;
};

#endif
