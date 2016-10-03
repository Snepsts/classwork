#include <stdio.h>

int main(){
	double principal = 0, rate, days, interest;

	while(principal != -1){
		printf("Enter loan principal (-1 to end): ");
		scanf("%lf", &principal);

		if(principal == -1)
			return 0;

		printf("Enter interest rate: ");
		scanf("%lf", &rate);
		printf("Enter term of the loan in days: ");
		scanf("%lf", &days);

		interest = principal * rate * days / 365;
		printf("Interest charge is: %f\n\n", interest);
	}

	return 0;
}
