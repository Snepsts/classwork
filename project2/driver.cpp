#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include "Stack.h"
#include "CharStack.h"

using namespace std; //introduces namespace std

int main ( void )
{
	ifstream in;
	string fileName, line[30];
	int i = 0;

	CharStack N, M, P;

	cout << "Enter file name for palindrome check: ";
	cin >> fileName;

	in.open(fileName.c_str());
	assert(in.is_open());

	while (!in.eof())
	{
		getline(in, line[i]);

		if (line[i] != "") //added by author, checks for the empty last line that is often auto added to all my files by default
		{
			N.StringToStack(line[i]);
			cout << N << endl;

			P = N;
			M = N.Reverse();

			if (P.IsEqual(M))
				cout << "This line is a palindrome line" << endl;
			else
				cout << "This line is not a palindrome line" << endl;

			i++;
		}
	}

	cout << "\nProgram ended normally.\n";

	return 0;
}
