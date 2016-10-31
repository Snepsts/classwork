#include <stdio.h>

int main(){
	int counter = 2;
	do {
		if ( counter % 2 == 0 ) {
			printf( "%u\n", counter );
		}
		counter += 2;
	} while ( counter <= 100 );

	return 0;
}
