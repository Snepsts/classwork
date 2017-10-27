#include <stdio.h>
#include <string.h>

/*10.14. (Reversing the Order of an Integer’s Bits) Write a program that reverses
the order of the bits in an unsigned int value. The program should input the value
from the user and call function reverseBits to print the bits in reverse order.
Print the value in bits both before and after the bits are reversed to confirm that
the bits are reversed properly.*/

const char *byte_to_binary_u(unsigned x);
const char *reverseBits(unsigned x);

int main()
{
	unsigned bitNum;
	printf("Please enter a number lower than or equal to 4,294,967,295: ");
	scanf("%u", &bitNum);

	printf("This is the binary representation of your number:\n%s\n", byte_to_binary_u(bitNum));
	printf("This is the binary representation of your number in reverse:\n%s\n", reverseBits(bitNum));

	return 0;
}

const char *byte_to_binary_u(unsigned x) {
	static char c[33];
	c[0] = '\0';

	for(unsigned i = 2147483648; i > 0; i >>= 1) { //2147483648 allows us to see up to 32 bits
		strcat(c, ((x & i) == i) ? "1" : "0");
	}

	return c;
}

const char *reverseBits(unsigned x){
	const char *c = byte_to_binary_u(x);
	static char rc[33];

	rc[0] = '\0';

	for (size_t i = 31; i > 0; i--) {
		strcat(rc, (c[i] == '1') ? "1" : "0");
	}

	strcat(rc, (c[0] == '1') ? "1" : "0");

	return rc;
}

/* Output:
Please enter a number lower than or equal to 4,294,967,295: 3412468323
This is the binary representation of your number:
11001011011001100010001001100011
This is the binary representation of your number in reverse:
11000110010001000110011011010011
*/
