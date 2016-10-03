#include <stdio.h>

int main()
{
	const double PI = 3.14159; //pi is about 3.14159
	double radius;

	printf("Please enter the radius of the circle: ");
	scanf("%lf", &radius);
	printf("The diameter of the circle is: %f\n", radius * 2);
	printf("The circumference of the circle is: %f\n", 2 * PI * radius);
	printf("The area of the circle is: %f\n", radius * radius * PI);

	return 0;
}
