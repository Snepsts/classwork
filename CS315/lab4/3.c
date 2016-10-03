#include <stdio.h>

int main(){
	int accnum;
	double bb, tch, tcr, cl, b;

	while(accnum != -1){
		b = 0;
		printf("Enter account number (-1 to end): ");
		scanf("%d", &accnum);

		if(accnum == -1){
			return 0;
		}

		printf("Enter beginning balance: ");
		scanf("%lf", &bb);
		b += bb;
		printf("Enter total charges: ");
		scanf("%lf", &tch);
		b += tch;
		printf("Enter total credits: ");
		scanf("%lf", &tcr);
		b -= tcr;
		printf("Enter credit limit: ");
		scanf("%lf", &cl);

		if(b > cl){
			printf("Account: %d\n", accnum);
			printf("Credit limit: %f\n", cl);
			printf("Balance: %f\n", b);
			printf("Credit Limit Exceeded\n");
		}
		printf("\n");
	}

	return 0;
}
