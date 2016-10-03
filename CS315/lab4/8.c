#include <stdio.h>

int main(){
	printf("A\tA+2\tA+3\tA+6\n");
	for(int i = 3; i <= 15; i += 3){
		printf("%d\t%d\t%d\t%d\t\n", i, i+2, i+3, i+6);
	}
	return 0;
}
