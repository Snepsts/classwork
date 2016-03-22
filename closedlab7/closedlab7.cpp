/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/22/16
*/

#include <iostream>
#include <string>
#include "triplet.h"

using namespace std;

/* function enterElement
	Purpose: To be able to call the same prompt to enter triplet information
	Receives: Type T first, second, and third
	Preconditions: Must be passed with variables to modify
	Postconditions: first second and third are changed to user defined variables */
template <typename T>
void enterElement(T& first, T& second, T& third);

int main()
{
	string firsts, seconds, thirds;
	int firsti, secondi, thirdi;
	triplet<string> tStr2;
	triplet<int> tInt2;

	cout << "You will now be prompted to initialize the first string triplet.\n";
	enterElement<string>(firsts, seconds, thirds);

	triplet<string> tStr(firsts, seconds, thirds);

	cout << "You will now be prompted to initialize the second string triplet.\n";
	enterElement<string>(firsts, seconds, thirds);
	tStr2.setTriplet(firsts, seconds, thirds);

	if (tStr == tStr2)
		cout << "The first and second string triplets are the same." << endl;
	else
		cout << "The first and second string triplets are different." << endl;

	cout << "The max value in the first string triplet is: " << tStr.find_max() << endl;
	cout << "The min value in the first string triplet is: " << tStr.find_min() << endl;
	cout << "The max value in the second string triplet is: " << tStr2.find_max() << endl;
	cout << "The min value in the second string triplet is: " << tStr2.find_min() << endl;

	tStr.sort_ascending();
	cout << "The first string triplet in ascending order:\n" << tStr;
	tStr.sort_descending();
	cout << "The first string triplet in descending order:\n" << tStr;
	tStr2.sort_ascending();
	cout << "The second string triplet in ascending order:\n" << tStr2;
	tStr2.sort_descending();
	cout << "The second string triplet in descending order:\n" << tStr2;

	cout << "You will now be prompted to initialize the first integer triplet.\n";
	enterElement<int>(firsti, secondi, thirdi);

	triplet<int> tInt(firsti, secondi, thirdi);

	cout << "You will now be prompted to initialize the second integer triplet.\n";
	enterElement<int>(firsti, secondi, thirdi);
	tInt2.setTriplet(firsti, secondi, thirdi);

	if (tInt == tInt2)
		cout << "The first and second integer triplets are the same." << endl;
	else
		cout << "The first and second integer triplets are different." << endl;

	cout << "The max value in the first integer triplet is: " << tInt.find_max() << endl;
	cout << "The min value in the first integer triplet is: " << tInt.find_min() << endl;
	cout << "The max value in the second integer triplet is: " << tInt2.find_max() << endl;
	cout << "The min value in the second integer triplet is: " << tInt2.find_min() << endl;

	tInt.sort_ascending();
	cout << "The first integer triplet in ascending order:\n" << tInt;
	tInt.sort_descending();
	cout << "The first integer triplet in descending order:\n" << tInt;
	tInt2.sort_ascending();
	cout << "The second integer triplet in ascending order:\n" << tInt2;
	tInt2.sort_descending();
	cout << "The second integer triplet in descending order:\n" << tInt2;

	return 0;
}

template <typename T>
void enterElement(T& first, T& second, T& third)
{
	cout << "Please enter your 1st element: ";
	cin >> first;
	cout << "Please enter your 2nd element: ";
	cin >> second;
	cout << "Please enter your 3rd element: ";
	cin >> third;
}
