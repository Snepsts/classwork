#include <iostream> //cin & cout

enum light_switch_state { DOWN, UP }; //DOWN = 0, UP = 1
enum light_bulb_state { OFF, ON, BROKEN = -1 }; //OFF = 0, ON = 1, BROKEN = -1
typedef light_switch_state lss; //for casting readability

int main()
{
	light_switch_state first_switch, second_switch;
	int temp;

	std::cout << "Please enter light states for the following two variables\n"
	          << "0: DOWN\n1: UP\n";
	//enter first switch
	do {
		std::cout << "Enter the first: ";
		std::cin >> temp;

		if (temp != 0 && temp != 1)
			std::cout << "Wrong value, try again.\n";
	} while (temp != 0 && temp != 1);
	first_switch = (lss)temp;

	//enter second switch
	do {
		std::cout << "Enter the second: ";
		std::cin >> temp;

		if (temp != 0 && temp != 1)
			std::cout << "Wrong value, try again.\n";
	} while (temp != 0 && temp != 1);
	second_switch = (lss)temp;

	light_bulb_state first_bulb, second_bulb;
	char a;

	//enter first bulb
	std::cout << "Is first broken? (y/n): ";
	std::cin >> a;
	if (a == 'y')
		first_bulb = BROKEN;
	else
		first_bulb = ON; //placeholder

	//enter second bulb
	std::cout << "Is second broken? (y/n): ";
	std::cin >> a;
	if (a == 'y')
		second_bulb = BROKEN;
	else
		second_bulb = OFF; //placeholder

	if (first_switch == second_switch) {
		//only have to check one since they're both the same
		if (first_switch == UP)
			std::cout << "Both light switches are up!\n";
		if (first_switch == DOWN)
			std::cout << "Both light switches are down!\n";
	} else if (first_switch == UP) {
		//first is not second and first == UP, then second == DOWN
		std::cout << "The first switch is up and the second switch is down!\n";
	} else {
		//first is not second and first == DOWN, then second == UP
		std::cout << "The first switch is down and the second switch is up!\n";
	}

	if (first_switch == UP) {
		if (first_bulb != BROKEN)
			first_bulb = ON;
		//else it's already broken, no need to set again
	} else { //first_switch == DOWN
		first_bulb = OFF; //we want the bulb to report OFF even if it isn't broken
		                  //because how do you know a bulb is broken if the switch is down?
	}

	if (second_switch == UP) {
		if (second_bulb != BROKEN)
			second_bulb = ON;
		//else it's already broken, no need to set again
	} else { //first_switch == DOWN
		second_bulb = OFF; //we want the bulb to report OFF even if it isn't broken
		                   //because how do you know a bulb is broken if the switch is down?
	}

	if (first_bulb == second_bulb) {
		//only have to check one since they're both the same
		if (first_bulb == ON)
			std::cout << "Both light bulbs are on!\n";
		else if (first_bulb == OFF)
			std::cout << "Both light bulbs are off!\n";
		else //BROKEN
			std::cout << "Both light bulbs are broken!\n";
	} else if (first_bulb == ON) {
		//first is not second and first == ON, then second == OFF or BROKEN
		if (second_bulb == OFF)
			std::cout << "The first bulb is on and the second bulb is off!\n";
		else
			std::cout << "The first bulb is on and the second bulb is broken!\n";
	} else if (first_bulb == OFF) {
		//first is not second and first == OFF, then second == ON or BROKEN
		if (second_bulb == ON)
			std::cout << "The first bulb is off and the second bulb is on!\n";
		else
			std::cout << "The first bulb is off and the second bulb is broken!\n";
	} else { //first == BROKEN
		//first is not second and first == BROKEN, then second == ON or OFF
		if (second_bulb == ON)
			std::cout << "The first bulb is broken and the second bulb is on!\n";
		else
			std::cout << "The first bulb is broken and the second bulb is off!\n";
	}

	return 0;
}
