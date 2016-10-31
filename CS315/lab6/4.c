#include <stdio.h>

int main(){
	int numbers[20] = {0};
	int numbercheck[20] = {0};
	int count = 0;
	int isSame;

	printf("Please enter 20 numbers between 10-100\n");
	for (size_t i = 0; i < 20; i++) {
		do {
			scanf("%d", &numbers[i]);
		} while(numbers[i] < 10 || numbers[i] > 100);
	}

	printf("Output: \n");

	for (size_t i = 0; i < 20; i++) {
		count++;
		isSame = 0;
		for (size_t j = 0; j < count; j++) {
			if (numbers[i] == numbercheck[j])
				isSame = 1;
		}
		if (!isSame)
			printf("%d ", numbers[i]);
		numbercheck[count - 1] = numbers[i];
	}

	printf("\n");

	return 0;
}

/* Output:
Please enter 20 numbers between 10-100
10 11 12 13 14 15 16 17 18 19 20 11 15 16 18 14 56 21 47 90
Output:
10 11 12 13 14 15 16 17 18 19 20 56 21 47 90
*/
