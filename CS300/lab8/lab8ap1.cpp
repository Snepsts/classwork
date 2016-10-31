/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
Date: 9/26/16 */

#include <iostream>
#include <cmath>

double f(const double& x);

int main(){
	double x = 56.4357;
	double c;
	c = f(x);
	std::cout << "The f of " << x << " is " << c << '\n';

	return 0;
}

double f(const double& x){
	double y;
	y = cos(exp(sin(x*x)));
	return y;
}

/* Output:
The f of 56.4357 is 0.839269
*/
