#include <stdio.h>

int main(){
	int a = 0, b = 0;

	printf("Enter any number that isn't 0: ");
	scanf("%d", &a);
	if(a == 0){
		printf("Invalid type, terminating program.\n");
		return 1;
	}

	printf("Enter any number that isn't 0: ");
	scanf("%d", &b);
	if(b == 0){
		printf("Invalid type, terminating program.\n");
		return 1;
	}
	printf("%d + %d = %d\n", a, b, a + b);

	return 0;
}
