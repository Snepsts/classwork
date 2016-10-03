#include <stdio.h>

int main(){
	double hours = 0, rate, salary;

	while(hours != -1){
		printf("Enter # of hours worked (-1 to end): ");
		scanf("%lf", &hours);

		if(hours == -1)
			return 0;

		printf("Enter hourly rate of the worker ($00.00): ");
		scanf("%lf", &rate);

		if(hours < 40)
			salary = rate * hours;
		else{
			hours -= 40;
			salary = (40 * rate) + (hours * rate * 1.5);
		}
		printf("Salary is %f\n\n", salary);
	}
	return 0;
}
