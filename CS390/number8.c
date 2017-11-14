#include <stdio.h>

int fun(int *num);

int main()
{
	int a, b;

	a = 10;
	b = a + fun(&a);

	printf("With the function call on the right, ");
	printf(" b is: %d\n", b);

	a = 10;
	b = fun(&a) + a;
	printf("With the function call on the left, ");
	printf(" b is: %d\n", b);

	return 0;
}

int fun(int *num)
{
	*num += 10;

	return 10;
}
