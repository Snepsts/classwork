/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/14/16
	Data Type: complexType, a complex number representing a real and imaginary part
*/

#include <iostream>
#include <cstdlib>
#include "complexType.h"

using namespace std;

complexType::complexType(double real /*= 0*/, double imaginary /*= 0*/)
// Task: Construct function by setting members to real & imaginary , default = 0
{
	realPart = real; imaginaryPart = imaginary;
}

void complexType::setComplex(const double& real, const double& imaginary)
// Task: set members to real & imaginary
{
	realPart = real; imaginaryPart = imaginary;
}

bool complexType::operator==(const complexType& otherComplex) const
// Task: return true if complexType objs are equal, else return false
{
	if(this->realPart == otherComplex.realPart && this->imaginaryPart == otherComplex.imaginaryPart)
		return true;
	else
		return false;
}

//Note: For the next four operators:
// a = this->realPart, b = this->imaginaryPart
// c = otherComplex.realPart, d = otherComplex.imaginaryPart

complexType complexType::operator+(const complexType& otherComplex) const
// Task: Add complexType objs together
{
	complexType thisComplex;
	// (a, b) * (c, d) = (a + c), (b + d)
	thisComplex.realPart = this->realPart + otherComplex.realPart;
	thisComplex.imaginaryPart = this->imaginaryPart + otherComplex.imaginaryPart;
	return thisComplex;
}

complexType complexType::operator*(const complexType& otherComplex) const
// Task: Multiply complexType objs
{
	complexType thisComplex;
	// (a, b) * (c, d) = (ac - bd), (bc + ad)
	thisComplex.realPart = (this->realPart * otherComplex.realPart) - (this->imaginaryPart * otherComplex.imaginaryPart);
	thisComplex.imaginaryPart = (this->imaginaryPart * otherComplex.realPart) + (this->realPart * otherComplex.imaginaryPart);
	return thisComplex;
}

complexType complexType::operator-(const complexType& otherComplex) const
// Task: Subtract complexType objs
{
	complexType thisComplex;
	// (a, b) - (c, d) = (a - c), (b - d)
	thisComplex.realPart = this->realPart - otherComplex.realPart;
	thisComplex.imaginaryPart = this->imaginaryPart - otherComplex.imaginaryPart;
	return thisComplex;
}

complexType complexType::operator/(const complexType& otherComplex) const
// Task: Divide complexType objs
{
	complexType thisComplex;
	// Check for divide by zero logic
	if(otherComplex.realPart == 0 && otherComplex.imaginaryPart == 0)
	{
		cout << "Error: Tried to divide by zero. Exiting Program." << endl;
		exit(1);
	}
	// (a, b) / (c, d) = ((ac + bd)/(c^2 + d^2)), ((bc - ad)/(c^2 + d^2))
	thisComplex.realPart = ((this->realPart * otherComplex.realPart) + (this->imaginaryPart * otherComplex.imaginaryPart)) / ((otherComplex.realPart * otherComplex.realPart) + (otherComplex.imaginaryPart * otherComplex.imaginaryPart));
	thisComplex.imaginaryPart = ((this->imaginaryPart * otherComplex.realPart) - (this->realPart * otherComplex.imaginaryPart)) / ((otherComplex.realPart * otherComplex.realPart) + (otherComplex.imaginaryPart * otherComplex.imaginaryPart));
	return thisComplex;
}

ostream& operator<<(ostream& out, const complexType& c)
// Task: Output complexType obj
{
	out << "(" << c.realPart << ", " << c.imaginaryPart << ")";
	return out;
}

istream& operator>>(istream& in, complexType& c)
// Task: Set complexType obj through Input
{
	char filler;
	cout << "Please enter your ordered pair in the form of (a, b): ";
	in >> filler >> c.realPart >> filler >> c.imaginaryPart >> filler;
	return in;
}
