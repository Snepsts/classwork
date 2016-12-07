#include <stdio.h>

int main(){
	float number1 = 7.3, number2;
	float *fPtr;

	fPtr = &number1;

	printf("%f\n", *fPtr);

	fPtr = &number2;

	printf("%f\n", number2);

	printf("%p\n", &number1);

	printf("%p\n", fPtr);

	return 0;
}
