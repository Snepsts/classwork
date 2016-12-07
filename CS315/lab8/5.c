#include <stdio.h>
#include <string.h>

const char *byte_to_binary(int x);

int main(){
	int x = 15; //1, 2, 4, and 8 = 1111 in bits
	printf("%s\n", byte_to_binary(x));

	x >>= 4;

	printf("%s\n", byte_to_binary(x));

	return 0;
}

const char *byte_to_binary(int x){
	static char c[9];
	c[0] = '\0';

	for(int i = 128; i > 0; i >>= 1){
		strcat(c, ((x & i) == i) ? "1" : "0");
	}

	return c;
}

/* Output:
00001111
00000000
*/

/* Observation:
It would seem my system replaces the vacant bits with 0s. As they go from 00001111 to 00000000.
*/
