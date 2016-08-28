/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/11/16
	Data Type: Date, an object that contains members year, month, and day.
*/

#include <iostream>
#include "date.h"

using namespace std;

int main()
{
	unsigned m0nth, d4y, y3ar;
	date yearOne;
	date yearTwo(12, 17, 1996);
	cout << "First date is: The " << yearOne << endl;
	cout << "Second date is: The " << yearTwo << endl;
	cout << "Please enter the numeric value for a month: ";
	cin >> m0nth;
	cout << "Please enter the day: ";
	cin >> d4y;
	cout << "Please enter the year: ";
	cin >> y3ar;
	yearOne.setYear(m0nth, d4y, y3ar);
	cout << "The new date is: The " << yearOne << endl;
	if(yearOne < yearTwo)
		cout << "The " << yearTwo << " is greater than the " << yearOne << endl;
	else
		cout << "The " << yearOne << " is equal to or greater than the " << yearTwo << endl;
	date yearThree;
	cin >> yearThree;
	cout << "The " << yearThree << endl;

	return 0;
}
