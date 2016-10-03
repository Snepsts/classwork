#include <stdio.h>

int main()
{
	int x, y;
	printf("Please enter two numbers:\n");
	scanf("%d%d", &x, &y);
	printf("%d + %d = %d\n", x, y, x + y);
	printf("%d x %d = %d\n", x, y, x * y);
	printf("%d - %d = %d\n", x, y, x - y);
	printf("%d / %d = %d\n", x, y, x / y);
	printf("%d %% %d = %d\n", x, y, x % y);

	return 0;
}
