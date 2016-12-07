#include <stdio.h>
#include <string.h>

/* (Unpacking Characters from an Integer) Using the right-shift operator, the bitwise
AND operator and a mask, write function unpackCharacters that takes the unsigned
int from Exercise 10.12 and unpacks it into four characters. To unpack characters
from a four-byte unsigned int , combine the unsigned int with the mask 4278190080
( 11111111 00000000 00000000 00000000 ) and right shift the result 8 bits. Assign
the resulting value to a char variable. Then combine the unsigned int with the mask
16711680 ( 00000000 11111111 00000000 00000000 ). Assign the result to another char
variable. Continue this process with the masks 65280 and 255 . The program should
print the unsigned int in bits before it’s unpacked, then print the characters in
bits to confirm that they were unpacked correctly. */

union bitCharInt{
	int i;
	char c;
} one, two, three, four;

const char *byte_to_binary(int x);
const char *byte_to_binary_u(unsigned x);
unsigned packCharacters(char a, char b, char c, char d);
void unpackCharacters(unsigned x);

int main(){
	unsigned x;

	printf("Please enter four characters without spaces or newlines between them.\n");
	scanf("%c%c%c%c", &one.c, &two.c, &three.c, &four.c);

	printf("First character is %c and in binary %s\n", one.c, byte_to_binary(one.i));
	printf("First character is %c and in binary %s\n", two.c, byte_to_binary(two.i));
	printf("First character is %c and in binary %s\n", three.c, byte_to_binary(three.i));
	printf("First character is %c and in binary %s\n", four.c, byte_to_binary(four.i));

	x = packCharacters(one.c, two.c, three.c, four.c);

	unpackCharacters(x);

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

unsigned packCharacters(char a, char b, char c, char d){
	unsigned x = 0;

	x += a; x <<= 8;
	x |= b; x <<= 8;
	x |= c; x <<= 8;
	x |= d;
	printf("All of these characters stored in one unsigned int lookes like this:\n%s\n", byte_to_binary_u(x));

	return x;
}

void unpackCharacters(unsigned x){
	char a, b, c, d;
	a = (x & 4278190080) >> 24;
	printf("The first char is %c and in binary is %s\n", a, byte_to_binary((int)a));
	b = (x & 16711680) >> 16;
	printf("The second char is %c and in binary %s\n", b, byte_to_binary((int)b));
	c = (x & 65280) >> 8;
	printf("The third char is %c and in binary is %s\n", c, byte_to_binary((int)x));
	d = (x & 255);
	printf("The fourth char is %c and in binary is %s\n", d, byte_to_binary((int)x));
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
The first char is a and in binary is 01100001
The second char is b and in binary 01100010
The third char is c and in binary is 01100100
The fourth char is d and in binary is 01100100
*/
