#include <stdio.h>
#include <string.h>

#define AMOUNT 10

void ascending(int x[]);
void descending(int x[]);

int main(int argc, char const *argv[]) {
	int isA = 0, isD = 0;
	int array[AMOUNT] = {5, 3, 8, 15, 1, 7, 6, 17, 2, 10};

	if(argc <= 1){
		printf("No command-line arguments found, exiting program.\n");
		return 1;
	}

	if(!strcmp(argv[1], "-a"))
		ascending(array);
	else if(!strcmp(argv[1], "-d"))
		descending(array);
	else{
		printf("Incorrect args found, exiting.\n");
		return 1;
	}

	printf("Sorted array: ");

	for (size_t i = 0; i < AMOUNT; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}

void ascending(int x[]){
	int temp;

	for(size_t i = 0; i < AMOUNT; i++){
		for(size_t j = i; j < AMOUNT; j++){
			if(x[j] < x[i]){
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
}

void descending(int x[]){
	int temp;

	for(size_t i = 0; i < AMOUNT; i++){
		for(size_t j = i; j < AMOUNT; j++){
			if(x[j] > x[i]){
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
}

/* Output:
snepsts@michael-laptop:~/classwork/CS315/lab9$ ./a.out -a
Sorted array: 1 2 3 5 6 7 8 10 15 17
snepsts@michael-laptop:~/classwork/CS315/lab9$ ./a.out -d
Sorted array: 17 15 10 8 7 6 5 3 2 1 */
