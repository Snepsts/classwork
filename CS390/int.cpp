#include <iostream>

int main()
{
	int first, second;

	std::cout << "Please enter light states for the following two variables\n"
	          << "0: OFF\n1: ON\n";
	//enter first
	do {
		std::cout << "Enter the first: ";
		std::cin >> first;

		if (first != 0 && first != 1)
			std::cout << "Wrong value, try again.\n";
	} while (first != 0 && first != 1);

	//enter second
	do {
		std::cout << "Enter the second: ";
		std::cin >> second;

		if (second != 0 && second != 1)
			std::cout << "Wrong value, try again.\n";
	} while (second != 0 && second != 1);

	if (first == second) {
		//only have to check one since they're both the same
		if (first == 1)
			std::cout << "Both lights are on!\n";
		if (first == 0)
			std::cout << "Both lights are off!\n";
	} else if (first == 1) {
		//first is not second and first == ON, then second == OFF
		std::cout << "The first light is on and the second light is off!\n";
	} else {
		//first is not second and first == OFF, then second == ON
		std::cout << "The first light is off and the second light is on!\n";
	}

	return 0;
}
