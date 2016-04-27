/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 4/26/16
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

template <typename T>
bool ValidateType(T *&item, std::ifstream& fin);

using namespace std;

int main()
{
	int* iPtr;
	double* dPtr;
	string* stPtr;
	char typething;
	bool whilevar = true;
	double *dTotal = new double;
	int *iTotal = new int;
	string *stTotal = new string;

	ifstream fin;
	fin.open("clab12.txt");
	if (fin.fail())
	{ //Check for failure
		cerr << "Well you fucking suck, you forgot clab12.txt\n"; //Change this before I turn it in
		exit(1);
	}

	while (whilevar)
	{
		fin >> typething;

		switch(typething)
		{
		case 'd':
			//double
			dPtr = new double;
			if (ValidateType<double>(dPtr, fin))
			{
				cout << *dPtr << " " << dPtr << endl;
				*dTotal = *dTotal + *dPtr;
			}
			else
				cerr << "[error]: char input 'd' but type following not type \"double\"\n";
			delete dPtr;
			break;

		case 'i':
			//integer
			iPtr = new int;
			if (ValidateType<int>(iPtr, fin))
			{
				cout << *iPtr << " " << iPtr << endl;
				*iTotal = *iTotal + *iPtr;
			}
			else
				cerr << "[error]: char input 'i' but type following not type \"integer\"\n";
			delete iPtr;
			break;

		case 'q':
			//quit
			cout << "Type: Sum | Address\n";
			cout << "Double: " << *dTotal << " | " << dTotal << endl;
			cout << "Integer: " << *iTotal << " | " << iTotal << endl;
			cout << "String: " << *stTotal << " | " << stTotal << endl;
			whilevar = false;
			break;

		case 's':
			//string
			stPtr = new string;
			if (ValidateType<string>(stPtr, fin))
			{
				cout << *stPtr << " " << stPtr << endl;
				*stTotal = *stTotal + *stPtr;
			}
			else
				cerr << "[error]: char input 's' but type following not type \"string\"\n";
			delete stPtr;
			break;

		default:
			//catch errors
			cerr << "Illegal character detected. Clearing next input.\n";
			fin.ignore(256, '\n');
			break;
		}
	}
	fin.close();

	return 0;
}

template <typename T>
bool ValidateType(T *&item, ifstream& fin)
{
	return (fin >> *item);
}
