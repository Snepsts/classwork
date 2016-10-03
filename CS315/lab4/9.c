#include <stdio.h>

int main(void)
{
	unsigned int count = 1; //initialize count

	while (count <= 10) { //loop 10 times

		//output line of text
		puts(count % 2 ? "****" : "++++++++");
		++count; //increment count
	} //end while
} //end function main
