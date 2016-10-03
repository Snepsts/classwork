#include <stdio.h>

int main()
{
	int x, y, z;
	printf("Enter three different integers: ");
	scanf("%d %d %d", &x, &y, &z);
	printf("Sum is %d\n", x + y + z);
	printf("Average is %d\n", (x + y + z) / 3);
	printf("Product is %d\n", x * y * z);

	if(x < y && x < z) //find the smallest value
		printf("Smallest is %d\n", x);
	else if(y < x && y < z)
		printf("Smallest is %d\n", y);
	else if(z < x && z < y)
		printf("Smallest is %d\n", z);
	else
		printf("No smallest value found.\n");

	if(x > y && x > z) //find the largest value
		printf("Largest is %d\n", x);
	else if(y > x && y > z)
		printf("Largest is %d\n", y);
	else if(z > x && z > y)
		printf("Largest is %d\n", z);
	else
		printf("No largest value found.\n");

	return 0;
}
