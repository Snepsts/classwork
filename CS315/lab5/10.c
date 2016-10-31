#include <stdio.h>

int factorial(int n);

int main(){
	printf("%d\t", factorial(1));
	printf("%d\t", factorial(2));
	printf("%d\t", factorial(3));
	printf("%d\t", factorial(4));
	printf("%d\t", factorial(5));
	printf("\n");

	return 0;
}

int factorial(int n){
	if(n > 1)
		return n * factorial(n-1);
	else
		return n;
}

/* Output:
1	2	6	24	120
*/
