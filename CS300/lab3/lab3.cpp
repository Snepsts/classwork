#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "split.h"

int main()
{
	std::string line;
	std::vector<std::string> vst;

	std::ifstream fin;
	fin.open("shortstory.txt");
	if (fin.fail())
	{
		std::cerr << "ERROR: \"shortstory.txt\" failed to open.\n";
		//exit(1);
	}

	std::cout << "Using split:\n";

	while (getline(fin, line))
	{
		vst = split(line);
		for (std::vector<std::string>::reverse_iterator vit = vst.rbegin(); vit != vst.rend(); vit++)
			std::cout << *vit << "/";
		std::cout << "\n";
	}

	std:: cout << "\n\n\n"; //give a big line break between split and csplit

	fin.close();

	fin.open("shortstory.txt");
	if (fin.fail())
	{
		std::cerr << "ERROR: \"shortstory.txt\" failed to open.\n";
		//exit(1);
	}

	std::cout << "Using csplit:\n";

	while (getline(fin, line))
	{
		vst = csplit(line);
		for (std::vector<std::string>::reverse_iterator vit = vst.rbegin(); vit != vst.rend(); vit++)
			std::cout << *vit << "/";
		std::cout << "\n";
	}

	fin.close();

	return 0;
}
