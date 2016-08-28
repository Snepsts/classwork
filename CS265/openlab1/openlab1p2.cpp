/*
	Author: Michael Ranciglio
	Date: 1/27/2016
	Purpose: To preform various tasks related to structure declaration
*/

#include <iostream>

using namespace std;

struct Rectangle
{
	unsigned length;
	unsigned width;
};

void rectanglefunction(Rectangle& r1);

void displayrectangle(Rectangle r);

Rectangle returnrectangle();

int main()
{
	Rectangle r1, r2;

	rectanglefunction(r1);
	displayrectangle(r1);

	r2 = returnrectangle();
	cout << "The length for your new rectangle is: " << r2.length << endl;
	cout << "The width for your new rectangle is: " << r2.width << endl;

	return 0;
}

/*
	Function rectanglefunction
	Purpose: To accept user input to function values w/o return value.
	Preconditions: None
	Postconditions: Takes user input and defines length and width of the
					rectangles.
*/

void rectanglefunction(Rectangle& r1)
{
	cout << "Please input a value for the length of the rectangle: ";
	cin.clear();
	cin >> r1.length;
	cout << "Please input a value for the width of the rectangle: ";
	cin.clear();
	cin >> r1.width;
}

/*
	Function displayrectangle
	Purpose: To display the contents of a rectangle
	Preconditions: The argument passed should have values already stored in it
	Postconditions: None
*/

void displayrectangle(Rectangle r)
{
	cout << "Length: " << r.length << endl;
	cout << "Width: " << r.width << endl;
}

/*
	Function returnrectangle
	Purpose: To return struct type Rectangle with user-defined traits to main
	Preconditions: None
	Postconditions: Rectangle r1 will have values in it, but only in this scope
*/

Rectangle returnrectangle()
{
	Rectangle r1;

	cout << "Please enter the length for a rectangle: ";
	cin.clear();
	cin >> r1.length;
	cout << "Please enter the width for a rectangle: ";
	cin.clear();
	cin >> r1.width;

	return r1;
}
