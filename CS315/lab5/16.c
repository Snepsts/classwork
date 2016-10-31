#include <stdio.h>
#include <time.h>
#include <math.h>

int secondsfromtwelve(int hour, int minute, int second);

int main(){
	int hour1, minute1, second1, hour2, minute2, second2;

	printf("Please enter two times that are within 12 hours of each other\n");
	printf("First time: hours minutes seconds\n");
	do {
		scanf("%d%d%d", &hour1, &minute1, &second1);
	} while(hour1 > 23 || hour1 < 0 || minute1 > 59 || minute1 < 0 || second1 > 59 || second1 < 0);
	printf("Second time: hours minutes seconds\n");
	do {
		scanf("%d%d%d", &hour2, &minute2, &second2);
	} while(hour2 > 23 || hour2 < 0 || minute2 > 59 || minute2 < 0 || second2 > 59 || second2 < 0);

	printf("The time between the two times entered in seconds is %f\n", fabs(secondsfromtwelve(hour1, minute1, second1) - secondsfromtwelve(hour2, minute2, second2)));

	return 0;
}

int secondsfromtwelve(int hour, int minute, int second){
	int totalSeconds = (second + (minute * 60) + (hour * 3600));
	if (hour >= 12) //if it's past 12 o'clock (military time) or if it just is 12 o'clock
		totalSeconds -= 43200; //43200 is how many seconds are elapsed in 12 hours.
	return totalSeconds;
}

/* Output:
First time: hours minutes seconds
23
43
38
Second time: hours minutes seconds
44
32
66
23
51
32
The time between the two times entered in seconds is 474.000000
*/
