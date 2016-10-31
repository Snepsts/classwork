#include <stdio.h>

int main(){
	int num[5];
	int x;
	for(int i = 0; i < 5; ++i){
		printf("Please enter value number %d\n", i+1);
		do {
			scanf("%d", &x);

			if(1 > x || x > 30)
				printf("Sorry, please try again.\n");
			else
				num[i] = x;
		} while(1 > x || x > 30);
	}

	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < num[i]; j++)
			printf("%s", "*");
		printf("\n"); //newline at the end of each bar graph
	}

	return 0;
}

/* Output:
Please enter value number 1
0
Sorry, please try again.
31
Sorry, please try again.
1
Please enter value number 2
7
Please enter value number 3
27
Please enter value number 4
14
Please enter value number 5
19
*
*******
***************************
**************
*******************
*/
