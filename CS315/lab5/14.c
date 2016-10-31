#include <stdio.h>
#include <math.h>

double calculateCharge(double hours);

const int AMOUNT_OF_CUSTOMERS = 3; //doing program for 3 customers in this example

int main(){
	double hours[AMOUNT_OF_CUSTOMERS];
	double totalHours = 0, totalCharge = 0;

	printf("Enter the hours parked for %d customer(s)\n", AMOUNT_OF_CUSTOMERS);

	for(int i = 0; i < AMOUNT_OF_CUSTOMERS; i++){
		scanf("%lf", &hours[i]);
	}

	printf("Car\t\tHours\t\tCharge\n");
	for(int i = 0; i < AMOUNT_OF_CUSTOMERS; i++){
		printf("%d\t\t%.1f\t\t%.2f\n", i+1, hours[i], calculateCharge(hours[i]));
		totalHours += hours[i];
		totalCharge += calculateCharge(hours[i]);
	}

	printf("TOTAL\t\t%.1f\t\t%.2f\n", totalHours, totalCharge);

	return 0;
}

double calculateCharge(double hours){
	if(hours <= 3.0)
		return 2.00;
	else if(hours > 3.0 && hours <= 18){
		hours -= 3;
		hours = ceil(hours);
		return (hours * .50 + 2.00);
	}
	else
		return 10.00;
}

/* Output:
Enter the hours parked for 3 customer(s)
22
2.9
17.6
Car		Hours		Charge
1		22.0		10.00
2		2.9		2.00
3		17.6		9.50
TOTAL		42.5		21.50
*/
