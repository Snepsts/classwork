#include <stdio.h>

int main(){
	double salary, sales = 0;

	while(sales != -1){
		printf("Enter sales in dollars (-1 to end): ");
		scanf("%lf", &sales);

		if(sales == -1)
			return 0;

		salary = sales * .09 + 200;
		printf("Salary is: %f\n\n", salary);
	}

	return 0;
}
