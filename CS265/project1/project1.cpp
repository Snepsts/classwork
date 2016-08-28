/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/14/16
*/

#include <iostream>
#include <iomanip>
#include "complexType.h"

using namespace std;

int main()
{
	double real, imaginary;
	char filler;
	complexType c1, c2(3.00, 5.00), c3;
	cout << setprecision(2) << fixed; // Set to round to 2 decimal points
	cout << "Complex number 2 has values 3.00 and 5.00 for it's values." << endl;
	cout << "You will now be prompted to enter values for complex number 1." << endl;
	cin >> c1;
	if (c1 == c2)
		cout << c1 << " is equal to " << c2 << endl;
	else
		cout << c1 << " is not equal to " << c2 << endl;
	cout << "You will now be prompted to enter values for complex number 2." << endl;
	cout << "Please enter your number in the form of (a, b): ";
	cin >> filler >> real >> filler >> imaginary >> filler;
	c2.setComplex(real, imaginary);
	if (c1 == c2)
		cout << c1 << " is equal to " << c2 << endl;
	else
		cout << c1 << " is not equal to " << c2 << endl;
	c3 = c1 + c2;
	cout << c1 << " + " << c2 << " = " << c3 << endl;
	c3 = c1 - c2;
	cout << c1 << " - " << c2 << " = " << c3 << endl;
	c3 = c1 * c2;
	cout << c1 << " x " << c2 << " = " << c3 << endl;
	c3 = c1 / c2;
	cout << c1 << " / " << c2 << " = " << c3 << endl;

	return 0;
}
