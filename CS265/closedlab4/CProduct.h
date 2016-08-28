/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/18/16
	Data Type: A product being sold by an office supply store.
	Operations:
		CProduct - The Constructor
		CProduct(explicit) - Explicit Constructor
		get[variable] - Accessors. Return their information
		setCProduct - Mutator
		RetailPrice - Returns the wPrice modified with markup percentage
		overloaded == operator - returns true if CProduct C is = to the obj
	Else returns false.
friend	overloaded << operator - outputs the CProduct for easy main function reading
friend	overloaded >> operator - allows simplified main function input
*/

#ifndef __CPRODUCT_H__
#define __CPRODUCT_H__

#include <iostream>

using namespace std;

class CProduct
{
public:
	//function CProduct - constructor
	CProduct();

	//function CProduct (explicit) - explicit constructor
	CProduct(unsigned p1D, unsigned ma1D, double wPr1ce, double m4rkup);

	/* function getPID
	Purpose: To return the product ID
	Preconditions: Product should have been explicitly constructed or set
	Receives: N/A
	Postconditions: Returns pID
	*/
	unsigned getPID() const;

	/* function getMaID
	Purpose: To return the manufacturer ID
	Preconditions: Product should have been explicitly constructed or set
	Receives: N/A
	Postconditions: Returns maID
	*/
	unsigned getMaID() const;

	/* function getWPrice
	Purpose: To return the wholesale price
	Preconditions: Product should have been explicitly constructed or set
	Receives: N/A
	Postconditions: Returns wPrice
	*/
	double getWPrice() const;

	/* function getMarkup
	Purpose: To return the markup percentage
	Preconditions: Product should have been explicitly constructed or set
	Receives: N/A
	Postconditions: Returns Markup percentage
	*/
	double getMarkup() const;

	/* function setCProduct
	Purpose: To set the object variables from the parameters
	Preconditions:
	Receives: Two unsigned ints (p1D and ma1D) and two doubles (wPr1ce and m4rkup)
	Postconditions: Sets the member variables to the corresponding parameters
	*/
	void setCProduct(unsigned p1D, unsigned ma1D, double wPr1ce, double m4rkup);

	/* function RetailPrice
	Purpose: To return the wholesale price adjusted with the markup
	Preconditions: Product should have been explicitly constructed or set
	Receives: N/A
	Postconditions: Returns wholesale price adjusted with markup
	*/
	double RetailPrice() const;

	//Overloaded Operator==: simplified == in main
	bool operator==(const CProduct& C) const;

	//Overloaded Operator<<: simplified output in main
	friend ostream& operator<<(ostream& out, CProduct C);

	//Overloaded Operator>>: simplified input in main
	friend istream& operator>>(istream& in, CProduct& C);

private:
	unsigned pID, maID;
	double wPrice, markup;
};

#endif
