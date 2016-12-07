#include <stdio.h>
#include <stdarg.h>

int product(int x, ...);

int main(){
	printf("First run with 5 args (1-5): %d\n", product(5, 1, 2, 3, 4, 5));
	printf("Second run with 3 args (1,3,5): %d\n", product(3, 1, 3, 5));
	printf("Third run with 7 args (1-7): %d\n", product(7, 1, 2, 3, 4, 5, 6, 7));

	return 0;
}

int product(int x, ...){
	int product = 0;
	va_list args;
	va_start(args, x);

	for(int i = 0; i < x; i++){
		product += va_arg(args, int);
	}

	va_end(args);

	return product;
}

/* Output:
First run with 5 args (1-5): 15
Second run with 3 args (1,3,5): 9
Third run with 7 args (1-7): 28 */
