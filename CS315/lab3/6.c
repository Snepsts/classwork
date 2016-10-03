#include <stdio.h>

int main()
{
	double miles, cpg, mpg, pfd, tpd, no_fam;
	printf("Please enter the miles driven per day: ");
	scanf("%lf", &miles);
	printf("Please enter the cost per gallon: ");
	scanf("%lf", &cpg);
	printf("Please enter the average miles per gallon: ");
	scanf("%lf", &mpg);
	printf("Please enter the parking fees per day: ");
	scanf("%lf", &pfd);
	printf("Please enter the tolls per day: ");
	scanf("%lf", &tpd);
	printf("Please enter the number of families you will be carpooling with (must be more than 1): ");
	scanf("%lf", &no_fam);

	printf("You will save %f per day with carpooling.\n", ((miles / mpg * cpg) + pfd + tpd) / (no_fam - 1));

	return 0;
}
