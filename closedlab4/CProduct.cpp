/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/18/16
*/

#include <iostream>
#include <iomanip>
#include "CProduct.h"

using namespace std;

CProduct::CProduct()
// Task: Default Constructor
{
	pID = 00000; maID = 0000; wPrice = 0.00; markup = 0.00;
}

CProduct::CProduct(unsigned p1D, unsigned ma1D, double wPr1ce, double m4rkup)
// Task: Explicit Constructor
{
	pID= p1D; maID = ma1D; wPrice = wPr1ce; markup = m4rkup;
}

unsigned CProduct::getPID() const
// Task: Return Product ID
{
	return pID;
}

unsigned CProduct::getMaID() const
// Task: Return Manufacturer ID
{
	return maID;
}

double CProduct::getWPrice() const
// Task: Return Wholesale Price
{
	return wPrice;
}

double CProduct::getMarkup() const
// Task: Return Markup Value
{
	return markup;
}

void CProduct::setCProduct(unsigned p1D, unsigned ma1D, double wPr1ce, double m4rkup)
// Task: Set CProduct by user-defined parameters
{
	pID= p1D; maID = ma1D; wPrice = wPr1ce; markup = m4rkup;
}

double CProduct::RetailPrice() const
// Task: Return the RetailPrice, which is just wholesale modified with markup value
{
	return wPrice + (wPrice * markup);
}

bool CProduct::operator==(const CProduct& C) const
// Task: See if one CProduct is equivalent to the other
{
	if (this->pID == C.pID && this->maID == C.maID)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, CProduct C)
// Task: Output the CProduct in main for easier reading
{
	out << "Product ID: " << setfill('0') << setw(5) << C.pID << endl;
	out << "Manufacturer ID: " << setfill('0') << setw(4) << C.maID << endl;
	out << setprecision(2) << fixed;
	out << "Wholesale Price: " << C.wPrice << endl;
	out << "Markup value: " << C.markup * 100 << '%' << endl;
	out << "Retail Price: " << C.RetailPrice() << endl;
	return out;
}

istream& operator>>(istream& in, CProduct& C)
// Task: Input the CProduct values for esaier reading in main
{
	cout << "Please enter the Product ID (5 digits): ";
	in >> C.pID;
	cout << "Please enter the Manufacturer ID (4 digits): ";
	in >> C.maID;
	cout << "Please enter the Wholesale Price: ";
	in >> C.wPrice;
	cout << "Please enter the markup value (if it is 11 percent type as 0.11): ";
	in >> C.markup;
	return in;
}
