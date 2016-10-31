#include <stdio.h>

int main(){
	int num_numbers;
	int smallest = 200; //initialize to the largest int
	int numbers[100]; //assume they won't enter more than 100

	printf("Enter how many numbers you're entering, then enter said numbers: \n");
	scanf("%d", &num_numbers);

	if(num_numbers > 100){ //check that the value isn't over our assumed limit
		printf("Sorry, that's too many numbers.\n");
		return 1;
	}

	for(int i = 0; i < num_numbers; ++i){
		scanf("%d", &numbers[i]);
	}

	for(int i = 0; i < num_numbers; ++i){ //for each i, we compare to the whole array
		for (int j = 0; j < num_numbers; ++j) { //j is what we use to run through the whole array to compare
			if(numbers[i] <= numbers[j] && numbers[i] <= smallest){ //if it's smaller then it's obviously the smallest
				smallest = numbers[i];
			} //end the if
		} //end the for j loop
	} //end the for i loop

	printf("The smallest value in all of the entered values is: %d\n", smallest);

	return 0;
}

/* Output:
Enter how many numbers you're entering, then enter said numbers:
50
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 -8 50
The smallest value in all of the entered values is: -8
*/
