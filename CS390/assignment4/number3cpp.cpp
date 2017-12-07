/*
3. Rewrite the following code segment using a multiple-selection statement in the following languages:
if ((k == 1) || (k == 2)) j = 2 * k - 1
if ((k == 3) || (k == 5)) j = 3 * k + 1
if (k == 4) j = 4 * k - 1
if ((k == 6) || (k == 7) || (k == 8)) j = k - 2
a. Fortran 95 (you’ll probably need to look this one up)
b. Ada
c. C, C++, Java, or C#
d. Python
e. Ruby
Assume all variables are integer type. Discuss the relative merits of the use of these languages for this particular code.
*/

#include <iostream>

int main()
{
	int k, j;
	bool is_valid = true;
	std::cout << "Please enter a k: ";
	std::cin >> k;

	switch (k) {
	case 1:
	case 2:
		j = 2 * k - 1;
		break;
	case 3:
	case 5:
		j = 3 * k + 1;
		break;
	case 4:
		j = 4 * k - 1;
		break;
	case 6:
	case 7:
	case 8:
		j = k - 2;
		break;
	default:
		std::cout << "Invalid Option.\n";
		is_valid = false;
	}

	if (is_valid)
		std::cout << "j evaluates to: " << j << '\n';

	return 0;
}
