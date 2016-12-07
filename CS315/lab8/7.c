#include <stdio.h>
#include <string.h>

union bitCharInt{
	int i;
	char c;
} one, two, three, four;

const char *byte_to_binary(int x);
const char *byte_to_binary_u(unsigned x);
void packCharacters(char a, char b, char c, char d);

int main(){
	unsigned x;

	printf("Please enter four characters without spaces or newlines between them.\n");
	scanf("%c%c%c%c", &one.c, &two.c, &three.c, &four.c);
	printf("First character is %c and in binary %s\n", one.c, byte_to_binary(one.i));
	printf("First character is %c and in binary %s\n", two.c, byte_to_binary(two.i));
	printf("First character is %c and in binary %s\n", three.c, byte_to_binary(three.i));
	printf("First character is %c and in binary %s\n", four.c, byte_to_binary(four.i));

	packCharacters(one.c, two.c, three.c, four.c);

	return 0;
}

const char *byte_to_binary(int x){
	static char c[9];
	c[0] = '\0';

	for(int i = 128; i > 0; i >>= 1){ //128 allows us to see up to 8 bits
		strcat(c, ((x & i) == i) ? "1" : "0");
	}

	return c;
}

const char *byte_to_binary_u(unsigned x){
	static char c[33];
	c[0] = '\0';

	for(unsigned i = 2147483648; i > 0; i >>= 1){ //2147483648 allows us to see up to 32 bits
		strcat(c, ((x & i) == i) ? "1" : "0");
	}

	return c;
}

void packCharacters(char a, char b, char c, char d){
	unsigned x = 0;

	x += a; x <<= 8;
	x |= b; x <<= 8;
	x |= c; x <<= 8;
	x |= d;
	printf("All of these characters stored in one unsigned int lookes like this:\n%s\n", byte_to_binary_u(x));
}

/* Output:
Please enter four characters without spaces or newlines between them.
abcd
First character is a and in binary 01100001
First character is b and in binary 01100010
First character is c and in binary 01100011
First character is d and in binary 01100100
All of these characters stored in one unsigned int lookes like this:
01100001011000100110001101100100
*/
