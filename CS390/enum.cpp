#include <iostream>

enum light_switch_state { OFF, ON }; //OFF = 0, ON = 1
typedef light_switch_state lss; //for casting readability

int main()
{
	light_switch_state first, second;
	int temp;

	std::cout << "Please enter light states for the following two variables\n"
	          << "0: OFF\n1: ON\n";
	//enter first
	do {
		std::cout << "Enter the first: ";
		std::cin >> temp;

		if (temp != 0 && temp != 1)
			std::cout << "Wrong value, try again.\n";
	} while (temp != 0 && temp != 1);
	first = (lss)temp;

	//enter second
	do {
		std::cout << "Enter the second: ";
		std::cin >> temp;

		if (temp != 0 && temp != 1)
			std::cout << "Wrong value, try again.\n";
	} while (temp != 0 && temp != 1);
	second = (lss)temp;

	if (first == second) {
		//only have to check one since they're both the same
		if (first == ON)
			std::cout << "Both lights are on!\n";
		if (first == OFF)
			std::cout << "Both lights are off!\n";
	} else if (first == ON) {
		//first is not second and first == ON, then second == OFF
		std::cout << "The first light is on and the second light is off!\n";
	} else {
		//first is not second and first == OFF, then second == ON
		std::cout << "The first light is off and the second light is on!\n";
	}

	return 0;
}
