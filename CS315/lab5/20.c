#include <stdio.h>

void tower_of_hanoi(int n, int one, int two, int three);

int main(){
	int n;

	printf("Enter how many disks you would like to sort.\n");
	scanf("%d", &n);

	printf("Here are the necessary steps to solve the tower of hanoi problem with %d disks\n", n);

	tower_of_hanoi(n, 1, 2, 3);

	printf("Congratulations, you have completed the tower of hanoi problem!\n");

	return 0;
}

void tower_of_hanoi(int n, int one, int two, int three){
	if(n == 1){
		printf("%d -> %d\n", one, two);
		return;
	}

	tower_of_hanoi(n - 1, one, three, two);
	printf("%d -> %d\n", one, two);
	tower_of_hanoi(n - 1, three, two, one);
}
