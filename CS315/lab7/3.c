#include <stdio.h>

int main(){
	long value1 = 200000, value2;
	long *lPtr;

	lPtr = &value1;

	printf("%ld\n", *lPtr);

	*lPtr = value2;

	printf("%ld\n", value2);

	printf("%p\n", &value1);

	printf("%p\n", lPtr);

	return 0;
}
