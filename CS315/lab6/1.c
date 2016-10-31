#include <stdio.h>

int main(){
	//$200 per week + 9% of their sales
	int workers[50]; //assume there's max 50 salespeople
	int counter[9] = {0}; //9 groups to sort them into
	int no_of_workers;
	double weekly_sales;

	printf("Please enter the amount of salespeople (max 50): ");
	do{
		scanf("%d", &no_of_workers);
	}while(no_of_workers > 50 || no_of_workers < 1);

	for (size_t i = 0; i < no_of_workers; i++){
		printf("Please enter the weekly sales for sales person number %lu\n", i+1);
		scanf("%lf", &weekly_sales);
		workers[i] = 200 + weekly_sales * .09; //salary for the week is 200 + 9% of weekly sales
		printf("The weekly income for that worker is %d\n", workers[i]);
	}

	for (size_t i = 0; i < no_of_workers; i++){
		if(workers[i] < 300)
			counter[0]++;
		else if(workers[i] >= 300 && workers[i] < 400)
			counter[1]++;
		else if(workers[i] >= 400 && workers[i] < 500)
			counter[2]++;
		else if(workers[i] >= 500 && workers[i] < 600)
			counter[3]++;
		else if(workers[i] >= 600 && workers[i] < 700)
			counter[4]++;
		else if(workers[i] >= 700 && workers[i] < 800)
			counter[5]++;
		else if(workers[i] >= 800 && workers[i] < 900)
			counter[6]++;
		else if(workers[i] >= 900 && workers[i] < 1000)
			counter[7]++;
		else if(workers[i] >= 1000)
			counter[8]++;
	}

	printf("# of workers making $200 - $299: %d\n", counter[0]);
	printf("# of workers making $300 - $399: %d\n", counter[1]);
	printf("# of workers making $400 - $499: %d\n", counter[2]);
	printf("# of workers making $500 - $599: %d\n", counter[3]);
	printf("# of workers making $600 - $699: %d\n", counter[4]);
	printf("# of workers making $700 - $799: %d\n", counter[5]);
	printf("# of workers making $800 - $899: %d\n", counter[6]);
	printf("# of workers making $900 - $999: %d\n", counter[7]);
	printf("# of workers making > $1000: %d\n", counter[8]);

	return 0;
}

/* Output:
Please enter the amount of salespeople (max 50): 15
Please enter the weekly sales for sales person number 1
3000
The weekly income for that worker is 470
Please enter the weekly sales for sales person number 2
4000
The weekly income for that worker is 560
Please enter the weekly sales for sales person number 3
5000
The weekly income for that worker is 650
Please enter the weekly sales for sales person number 4
6000
The weekly income for that worker is 740
Please enter the weekly sales for sales person number 5
7000
The weekly income for that worker is 830
Please enter the weekly sales for sales person number 6
8000
The weekly income for that worker is 920
Please enter the weekly sales for sales person number 7
9000
The weekly income for that worker is 1010
Please enter the weekly sales for sales person number 8
1234
The weekly income for that worker is 311
Please enter the weekly sales for sales person number 9
1000
The weekly income for that worker is 290
Please enter the weekly sales for sales person number 10
0
The weekly income for that worker is 200
Please enter the weekly sales for sales person number 11
5678
The weekly income for that worker is 711
Please enter the weekly sales for sales person number 12
1234567
The weekly income for that worker is 111311
Please enter the weekly sales for sales person number 13
7634
The weekly income for that worker is 887
Please enter the weekly sales for sales person number 14
931
The weekly income for that worker is 283
Please enter the weekly sales for sales person number 15
53421
The weekly income for that worker is 5007
# of workers making $200 - $299: 3
# of workers making $300 - $399: 1
# of workers making $400 - $499: 1
# of workers making $500 - $599: 1
# of workers making $600 - $699: 1
# of workers making $700 - $799: 2
# of workers making $800 - $899: 2
# of workers making $900 - $999: 1
# of workers making > $1000: 3
*/
