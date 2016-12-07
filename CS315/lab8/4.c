#include <stdio.h>

union floatingPoint{
	float f;
	double d;
	long double x;
};

void printunion(union floatingPoint floatin);

int main(){
	union floatingPoint fl;

	printf("Please enter a float: ");
	scanf("%f", &fl.f);
	printunion(fl);

	printf("Please enter a double: ");
	scanf("%lf", &fl.d);
	printunion(fl);

	printf("Please enter an long double: ");
	scanf("%Lf", &fl.x);
	printunion(fl);

	return 0;
}

void printunion(union floatingPoint floatin){
	printf("As a float: %f\n", floatin.f);
	printf("As a double: %f\n", floatin.d);
	printf("As an long double: %Lf\n", floatin.x);
}

/* Output:
Please enter a float: 1
As a float: 1.000000
As a double: 0.000000
As an long double: nan
Please enter a double: 1
As a float: 0.000000
As a double: 1.000000
As an long double: nan
Please enter an long double: 1
As a float: 0.000000
As a double: -0.000000
As an long double: 1.000000
*/

/* Observation:
It seems as though float, double, and long double don't play so well together.
I can't tell why, but I assume the conversion between the three isn't perfect, esp long double.
*/
