#include <iostream> //cin & cout

int main()
{
	int first_switch, second_switch;

	std::cout << "Please enter light states for the following two variables\n"
	          << "0: DOWN\n1: UP\n";
	//enter first
	do {
		std::cout << "Enter the first: ";
		std::cin >> first_switch;

		if (first_switch != 0 && first_switch != 1)
			std::cout << "Wrong value, try again.\n";
	} while (first_switch != 0 && first_switch != 1);

	//enter second
	do {
		std::cout << "Enter the second: ";
		std::cin >> second_switch;

		if (second_switch != 0 && second_switch != 1)
			std::cout << "Wrong value, try again.\n";
	} while (second_switch != 0 && second_switch != 1);

	int first_bulb, second_bulb; //-1 = BROKEN, 0 = OFF, 1 = ON
	char a;

	//enter first bulb
	std::cout << "Is first broken? (y/n): ";
	std::cin >> a;
	if (a == 'y')
		first_bulb = -1;
	else
		first_bulb = 1; //placeholder

	//enter second bulb
	std::cout << "Is second broken? (y/n): ";
	std::cin >> a;
	if (a == 'y')
		second_bulb = -1;
	else
		second_bulb = 0; //placeholder

	if (first_switch == second_switch) {
		//only have to check one since they're both the same
		if (first_switch == 1)
			std::cout << "Both light switches are up!\n";
		if (first_switch == 0)
			std::cout << "Both light switches are down!\n";
	} else if (first_switch == 1) {
		//first is not second and first == UP, then second == DOWN
		std::cout << "The first switch is up and the second switch is down!\n";
	} else {
		//first is not second and first == DOWN, then second == UP
		std::cout << "The first switch is down and the second switch is up!\n";
	}

	if (first_switch == 1) {
		if (first_bulb != -1)
			first_bulb = 1;
		//else it's already broken, no need to set again
	} else { //first_switch == DOWN
		first_bulb = 0; //we want the bulb to report OFF even if it isn't broken
		                //because how do you know a bulb is broken if the switch is down?
	}

	if (second_switch == 1) {
		if (second_bulb != -1)
			second_bulb = 1;
		//else it's already broken, no need to set again
	} else { //first_switch == DOWN
		second_bulb = 0; //we want the bulb to report OFF even if it isn't broken
		                   //because how do you know a bulb is broken if the switch is down?
	}

	if (first_bulb == second_bulb) {
		//only have to check one since they're both the same
		if (first_bulb == 1)
			std::cout << "Both light bulbs are on!\n";
		else if (first_bulb == 0)
			std::cout << "Both light bulbs are off!\n";
		else //BROKEN
			std::cout << "Both light bulbs are broken!\n";
	} else if (first_bulb == 1) {
		//first is not second and first == ON, then second == OFF or BROKEN
		if (second_bulb == 0)
			std::cout << "The first bulb is on and the second bulb is off!\n";
		else
			std::cout << "The first bulb is on and the second bulb is broken!\n";
	} else if (first_bulb == 0) {
		//first is not second and first == OFF, then second == ON or BROKEN
		if (second_bulb == 1)
			std::cout << "The first bulb is off and the second bulb is on!\n";
		else
			std::cout << "The first bulb is off and the second bulb is broken!\n";
	} else { //first == BROKEN
		//first is not second and first == BROKEN, then second == ON or OFF
		if (second_bulb == 1)
			std::cout << "The first bulb is broken and the second bulb is on!\n";
		else
			std::cout << "The first bulb is broken and the second bulb is off!\n";
	}

	return 0;
}
