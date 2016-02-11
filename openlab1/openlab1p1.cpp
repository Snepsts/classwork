/*
	Author: Michael Ranciglio
	Date: 1/27/2016
	Purpose: To preform various tasks related to structure declaration
*/

#include <iostream>
#include <string>

using namespace std;

struct movie
{
	string name;
	string director;
	unsigned yor;
};

int main()
{
	movie mov1;

	cout << "Enter the following information about your "
		<< "favorite movie.\n" << "Name: ";
	cin.clear();
	getline(cin, mov1.name);

	cout << "Director: ";
	cin.clear();
	getline(cin, mov1.director);

	cout << "Year of release: ";
	cin.clear();
	cin >> mov1.yor;

	cout << "\nHere is information on your favorite movie:\n";
	cout << "Name: " << mov1.name << endl;
	cout << "Director: " << mov1.director << endl;
	cout << "Year of release: " << mov1.yor << endl;

	return 0;
}
