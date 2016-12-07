#include <stdio.h>
#define SIZE 10

int main(){
	float numbers[SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
	float *nPtr;
	size_t i;

	for(i = 0; i < SIZE; i++)
		printf("%.1f\n", numbers[i]);

	nPtr = numbers; //first way to make ptr equal to 1st array position
	nPtr = &numbers[0]; //second way

	for(i = 0; i < SIZE; i++)
		printf("%.1f\n", *(nPtr + i));

	for(i = 0; i < SIZE; i++)
		printf("%.1f\n", *(numbers + i));

	for(i = 0; i < SIZE; i++)
		printf("%.1f\n", nPtr[i]);

	printf("%.1f %.1f %.1f %.1f\n", numbers[3], *(numbers + 3), nPtr[3], *(nPtr + 3));

	nPtr = &numbers[5];
	printf("%p\n", nPtr);
	nPtr -= 4;
	printf("%p\n", nPtr);
	printf("%.1f\n", *nPtr);

	return 0;
}
