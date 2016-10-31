#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){
	int x;

	srand(time(0)); //ensure number is random everytime

	for(int i = 0; i = 10; i++){
		//x = (rand() % 5 + 1) * 2; //for testing range 2, 4, 6, 8, 10
		//x = (rand() % 5 + 1) * 2 + 1; //for testing range 3, 5, 7, 9, 11
		x = (rand() % 5 + 1) * 4 + 2; //for testing range 6, 10, 14, 18, 22
		printf("%d\n", x);
		sleep(1);
	}

	return 0;
}
