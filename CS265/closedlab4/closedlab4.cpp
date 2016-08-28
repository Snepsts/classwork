/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 2/18/16
*/

#include <iostream>
#include "CProduct.h"

using namespace std;

int main()
{
	CProduct productOne;
	CProduct productTwo(19463, 6597, 13.64, .15);
	unsigned pID, maID;
	double wPrice, markup;

	cout << "The two CProduct objects, the first: " << endl;
	cout << productOne;
	cout << "And the second: " << endl;
	cout << productTwo;

	cout << "You will now be prompted to enter your own values for the first product." << endl;
	cout << "Please enter the Product ID (5 digits): ";
	cin >> pID;
	cout << "Please enter the Manufacturer ID (4 digits): ";
	cin >> maID;
	cout << "Please enter the Wholesale Price: ";
	cin >> wPrice;
	cout << "Please enter the markup value (11 percent typed as 0.11): ";
	cin >> markup;

	productOne.setCProduct(pID, maID, wPrice, markup);
	cout << "Your new product is: " << endl;
	cout << productOne;

	if (productOne == productTwo)
		cout << "The first and second products are the same." << endl;
	else
		cout << "The first and second products are NOT the same." << endl;

	CProduct productThree;

	cout << "You will now be prompted to enter values for the third product: " << endl;
	cin >> productThree;
	cout << "The third CProduct object: " << endl;
	cout << productThree;

	return 0;
}
