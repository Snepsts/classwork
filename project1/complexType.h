/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/14/16
	Data Type: complexType, a complex number representing a real and imaginary part
	Operations:
		complexType - constructor
		setComplex - mutator
		operator(+,-,*,/,==,>>,<<) - overloaded operators
*/

#ifndef __COMPLEXTYPE_H__
#define __COMPLEXTYPE_H__

#include <iostream>

using namespace std;

class complexType
{
public:
	/* Function complexType
	Purpose: To construct the complex number
	Receives: double real & double imaginary
	Preconditions: N/A, if no parameters are passed will default to zero
	Postconditions: complexType.realPart & imaginaryPart will be set */
	complexType(double real = 0, double imaginary = 0);

	/* Function setComplex
	Purpose: To mutate the members of complexType obj
	Receives: double real & double imaginary
	Preconditions: N/A
	Postconditions: complexType obj members set to real & imaginary*/
	void setComplex(const double& real, const double& imaginary);

	/* Overloaded Operator ==
	Purpose: To check whether complexType objs are equal or not
	Receives: Another complexType obj
	Preconditions: N/A
	(Typed: (complexType1 == complexType2))
	Postconditions: Returns true if ==, else returns false */
	bool operator==(const complexType& otherComplex) const;

	/* Overloaded Operator +
	Purpose: To allow easy addition of complexType objs in main
	Receives: Another complexType obj
	Preconditions: N/A
	(Typed: (complexType1 + complexType2))
	Postconditions: Returns the resulting complexType obj from the addition */
	complexType operator+(const complexType& otherComplex) const;

	/* Overloaded Operator *
	Purpose: To allow easy multiplication of complexType objs in main
	Receives: Another complexType obj
	Preconditions: N/A
	(Typed: (complexType1 * complexType2))
	Postconditions: Returns the resulting complexType obj from the multiplication */
	complexType operator*(const complexType& otherComplex) const;

	/* Overloaded Operator -
	Purpose: To allow easy subtraction of complexType objs in main
	Receives: Another complexType obj
	Preconditions: N/A
	(Typed: (complexType1 - complexType2))
	Postconditions: Returns the resulting complexType obj from the subtraction */
	complexType operator-(const complexType& otherComplex) const;

	/* Overloaded Operator /
	Purpose: To allow easy division of complexType objs in main
	Receives: Another complexType obj
	Preconditions: otherComplex types cannot = 0
	(Typed: (complexType1 / complexType2))
	Postconditions: Returns the resulting complexType obj from the division */
	complexType operator/(const complexType& otherComplex) const;

	/* Overloaded Operator <<
	Purpose: To allow easy output of complexType objs in main
	Receives: complexType obj
	Preconditions: N/A
	(Typed: (<< complexType1))
	Postconditions: Outputs complexType obj: (realPart, imaginaryPart)*/
	friend ostream& operator<<(ostream& out, const complexType& c);

	/* Overloaded Operator >>
	Purpose: To allow easy input of complexType objs in main
	Receives: complexType obj
	Preconditions: Input must be in format: (c.realPart, c.imaginaryPart)
	(Typed: (>> complexType1))
	Postconditions: Sets realPart & imaginaryPart by user-defined parameters */
	friend istream& operator>>(istream& in, complexType& c);

private:
	double realPart, imaginaryPart;
};

#endif
