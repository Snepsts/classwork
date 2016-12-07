#include <stdio.h>
#include <string.h> //strlen

struct user{
	int accNum;
	char name[31];
	int bal;
} u;
struct transUser{
	int accNum;
	int transBal;
} t;

int main(){

	FILE *fPtr, *fPtr2;
	if((fPtr = fopen("masterfile.txt", "w")) == NULL){
		printf("Sorry, but the action of creating/opening \"masterfile.txt\" failed.\n");
	}else if((fPtr2 = fopen("transactionfile.txt", "w")) == NULL){
		printf("Sorry, but the action of creating/opening \"transactionfile.txt\" failed.\n");
	}else{
		fprintf(fPtr, "Account Number\tName\t\t\t\tBalance\n");
		fprintf(fPtr2, "Account Number\tTransaction Balance\n");
		printf("Enter 0 on the Account Number prompt to end the program.\n");
		do{
			printf("Please enter the account number: ");
			scanf("%d", &u.accNum);
			if(u.accNum == 0)
				printf("Zero entered and acknowledged.\n");
			else{
				t.accNum = u.accNum;
				printf("Please enter the name of the user: ");
				scanf("%s", u.name);
				printf("Please enter the balance on the user's account: ");
				scanf("%d", &u.bal);
				printf("Please enter the transaction balance on the user's account: ");
				scanf("%d", &t.transBal);

				//write user information to record
				if(t.accNum > 9999999)
					fprintf(fPtr, "%d\t", u.accNum);
				else
					fprintf(fPtr, "%d\t\t", u.accNum);

				if(strlen(u.name) > 24)
					fprintf(fPtr, "%s\t", u.name);
				else if(strlen(u.name) > 15)
					fprintf(fPtr, "%s\t\t", u.name);
				else if(strlen(u.name) > 7)
					fprintf(fPtr, "%s\t\t\t", u.name);
				else
					fprintf(fPtr, "%s\t\t\t\t", u.name);

				fprintf(fPtr, "%d\n", u.bal);

				//write transaction information to record
				if(t.accNum > 9999999)
					fprintf(fPtr2, "%d\t", t.accNum);
				else
					fprintf(fPtr2, "%d\t\t", t.accNum);
				fprintf(fPtr2, "%d\n", t.transBal);
			}
		}while(u.accNum != 0);
		fclose(fPtr); //close user record
		fclose(fPtr2); //close transaction record
	}
	return 0;
}
