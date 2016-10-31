// ex06_17.c
// What does this program do?
#include <stdio.h>
#define SIZE 10

int whatIsThis( const int b[], size_t p ); // function prototype

// function main begins program execution
int main( void )
{
	int x; // holds return value of function whatIsThis

	// initialize array a
	int a[ SIZE ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	x = whatIsThis( a, SIZE );

	printf( "Result is %d\n", x );

	return 0;
} // end main

// what does this function do?
int whatIsThis( const int b[], size_t p )
{
	// base case
	if ( 1 == p ) {
		return b[ 0 ];
	} // end if
	else { // recursion step
		return b[ p - 1 ] + whatIsThis( b, p - 1 );
	} // end else
} // end function whatIsThis
