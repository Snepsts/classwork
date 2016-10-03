#include <stdio.h>

int main(){
	int decnum;
	long long binnum, bxnum, renum;

	printf("Enter any binary number: ");
	scanf("%lld", &binnum);
	bxnum = binnum;

	while(bxnum != 0){
		for(int i = 1; i <= 32768; i *= 2){
			renum = bxnum % 10;
			bxnum /= 10;
			decnum += renum * i;
		}
	}
	printf("The binary number %lld is %d in decimal\n", binnum, decnum);

	return 0;
}
