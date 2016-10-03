#include <stdio.h>

int main(){
	double totalg = 0, totalm = 0, gallon = 0, mile = 0;

	while(gallon != -1){
		printf("Enter the gallons used (-1 to end): ");
		scanf("%lf", &gallon);

		if(gallon == -1){
			printf("The overall average miles/gallon was %f\n", totalm / totalg);
			return 0;
		}

		totalg += gallon; //add gallon to the total gallons
		printf("Enter the miles driven: ");
		scanf("%lf",  &mile);
		totalm += mile; //add mile to the total miles

		printf("The miles/gallon for this tank was %f\n", mile / gallon);
	}

	return 0;
}
