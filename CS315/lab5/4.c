#include <stdio.h>

int main(){
	for ( double x = .000001; x <= .0001; x += .000001 ) {
		printf( "%.7f\n", x );
	}

	return 0;
}
