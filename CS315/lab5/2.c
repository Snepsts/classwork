#include <stdio.h>

int main(){
	int intVal;
	char charVal;

	scanf( "%d", &intVal );
	do {
		charVal = getchar();
	} while(charVal == ' ');
	printf( "Integer: %d\nCharacter: %c\n", intVal, charVal );

	return 0;
}
