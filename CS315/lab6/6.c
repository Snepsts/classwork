#include <stdio.h>

void reverseString(const char a[], int size);

int main( void )
{
	int size = 6;
	char a[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

	printf("%s backwards is: ", a);
	reverseString(a, size);
	printf("\n");

	return 0;
}

void reverseString(const char a[], int size)
{
	if(size > 0){
		reverseString(a, size - 1);
		printf("%c", a[size - 1]);
	}
}
