#include <stdio.h>
#include <string.h>

/*(Left Shifting Integers) Left shifting an unsigned int by 1 bit is equivalent
to multiplying the value by 2. Write function power2 that takes two integer arguments
number and pow and calculates
"number * 2 pow"
Use the shift operator to calculate the result. Print the values as integers and as bits.
*/

const char *byte_to_binary(int x);
unsigned power2(unsigned number, unsigned pow);

int main(){
	unsigned x = 15; //1, 2, 4, and 8 = 1111 in bits
	unsigned y = 20;
	//the result should be x * 2 * y
	printf("%s\n", byte_to_binary(power2(x, y)));
	printf("%u\n", power2(x,y));

	return 0;
}

const char *byte_to_binary(int x){
	static char c[9];
	c[0] = '\0';

	for(int i = 32768; i > 0; i >>= 1){ //32768 allows us to see up to 16 bits
		strcat(c, ((x & i) == i) ? "1" : "0");
	}

	return c;
}

unsigned power2(unsigned number, unsigned pow){
	return ((number * pow) << 1);
}

/* Output:
0000001001011000
600
*/
