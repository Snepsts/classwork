#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "split.h"

int main()
{
	std::string line;
	std::vector<std::string> vst;

	ifstream fin;
	fin.open("shortstory.txt");
	if (fin.fail())
	{
		cerr << "ERROR: \"shortstory.txt\" failed to open.\n";
		//exit(1);
	}

	while (getline(fin, line))
	{
		vst = split(line);
		for (std::vector<string>::reverse_iterator vit = vst.rend() - 1; vit != vst.rbegin() -1; vit--)
			cout << *vit << "/";
		cout << "\n";
	}

	return 0;
}
