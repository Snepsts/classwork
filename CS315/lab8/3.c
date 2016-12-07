#include <stdio.h>

union integer{
	char c;
	short s;
	int i;
	long b;
};

void printunion(union integer integ);

int main(){
	union integer in;

	printf("Please enter a character: ");
	scanf("%c", &in.c);
	printunion(in);

	printf("Please enter a short: ");
	scanf("%hd", &in.s);
	printunion(in);

	printf("Please enter an integer: ");
	scanf("%d", &in.i);
	printunion(in);

	printf("Please enter a long: ");
	scanf("%ld", &in.b);
	printunion(in);

	return 0;
}

void printunion(union integer integ){
	printf("As a character: %c\n", integ.c);
	printf("As a short: %hd\n", integ.s);
	printf("As an integer: %d\n", integ.i);
	printf("As a long: %ld\n", integ.b);
}

/* Output:
Please enter a character: c
As a character: c
As a short: -13469
As an integer: 582732643
As a long: 140729481153379
Please enter a short: 12345
As a character: 9
As a short: 12345
As an integer: 582692921
As a long: 140729481113657
Please enter an integer: 123456789
As a character: 
As a short: -13035
As an integer: 123456789
As a long: 140729021877525
Please enter a long: 123456789011120
As a character: �
As a short: -9552
As an integer: -2045912400
As a long: 123456789011120
*/
