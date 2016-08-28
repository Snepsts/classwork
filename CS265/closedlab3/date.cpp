/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/11/16
	Data Type: Date, an object that contains members year, month, and day.
*/

#include <iostream>
#include <string>
#include "date.h"

using namespace std;

//Task: Initialize the date default to Jan 1st, 1
date::date()
{
	month = 1; day = 1; year = 1;
}

//Task: Initialize the date to user-defined parameters passed from main
date::date(unsigned m0nth, unsigned d4y, unsigned y3ar)
{
	month = m0nth; day = d4y; year = y3ar;
}

//Task: Set the date members to user-defined parameters passed from main
void date::setYear(unsigned m0nth, unsigned d4y, unsigned y3ar)
{
	month = m0nth; day = d4y; year = y3ar;
}

//Task: Return the year
int date::getYear()
{
	return year;
}

//Task: Return the month
int date::getMonth()
{
	return month;
}

//Task: Return the day
int date::getDay()
{
	return day;
}

//Task: Return true if date D is greater than date obj, else return false
bool date::operator<(date D)
{
	bool yeareq, montheq;

	if(this->year == D.year) //check if years are equal
		yeareq = true;
	else
		yeareq = false;
	if(this->month == D.month) // check if months are equal
		montheq = true;
	else
		montheq = false;
	if(yeareq) //if years are equal
	{
		if(montheq) //and months are equal
		{
			if(this->day < D.day) //then check days
				return true;
			else
				return false;
		}
		else //else check months
		{
			if(this->month < D.month)
				return true;
			else
				return false;
		}
	}
	else //if neither are equal check years
	{
		if(this->year < D.year)
			return true;
		else
			return false;
	}
}

istream& operator>>(istream& in, date& D)
{
	cout << "Please enter the day (in numeric form): ";
	in >> D.day;
	cout << "Please enter the month (in numeric form): ";
	in >> D.month;
	cout << "Please enter the year (in numeric form): ";
	in >> D.year;
	return in;
}

ostream& operator<<(ostream& out, date D)
{
	string suffix, month;

	switch(D.month)
	{
	case 1:
		month = "January";
		break;
	case 2:
		month = "February";
		break;
	case 3:
		month = "March";
		break;
	case 4:
		month = "April";
		break;
	case 5:
		month = "May";
		break;
	case 6:
		month = "June";
		break;
	case 7:
		month = "July";
		break;
	case 8:
		month = "August";
		break;
	case 9:
		month = "September";
		break;
	case 10:
		month = "October";
		break;
	case 11:
		month = "November";
		break;
	case 12:
		month = "December";
		break;
	default:
		cout << "Error, month is wrong." << endl;
		break;
	}

	switch(D.day)
	{
	case 1:
		suffix = "st";
		break;
	case 2:
		suffix = "nd";
		break;
	case 3:
		suffix = "rd";
		break;
	default:
		suffix = "th";
		break;
	}
	out << D.day << suffix << " of " << month << ", " << D.year;
	return out;
}
