#include <stdio.h>

unsigned long long fibonacci(unsigned n);

int main(){
	unsigned n;

	printf("Enter a number please.\n");
	scanf("%u", &n);

	printf("Iteration #%u of the fibonacci sequence is %lld\n", n, fibonacci(n));

	return 0;
}

unsigned long long int fibonacci(unsigned n){
	unsigned long long z;
	unsigned long long x = 0; //i = 0
	unsigned long long y = 1; //i = 1

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	for(unsigned i = 2; i <= n; i++){
		z = x + y; //add the two together for the next number in the fib seq
		x = y; //advance x to the next number (which is y)
		y = z; //advance y to the next number (which is z)
	}

	return z;
}
