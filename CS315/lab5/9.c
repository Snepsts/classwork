#include <stdio.h>

int main(){
	int total = 0;
	for(int i = 2; i <= 30; i += 2){
		total += i;
	}

	printf("%d\n", total);

	return 0;
}

/* Output:
240
*/
