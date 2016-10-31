#include <stdio.h>

int main(){
	int count = 1; //start at 1 because the first iteration will be the first count
	const int TABLE_ROW_NUM = 5; //number of rows
	const int NUM_NUMERALS = 100; //number of numerals we want to print in order

	for(int i = 1; i <= NUM_NUMERALS; ++i){
		int j = i;
		int num_chars = 0; //for counting how many I's, X's, etc are printed to determine num of tabs needed

		while (j > 0) {
			if(j - 100 >= 0){
				printf("C");
				j -= 100;
			}
			else if(j - 50 >= 0){
				printf("L");
				j -= 50;
			}
			else if(j - 10 >= 0){
				printf("X");
				j -= 10;
			}
			else if(j - 5 >= 0){
				printf("V");
				j -= 5;
			}
			else{
				printf("I");
				j -= 1;
			}
		++num_chars;
		} //end of while

		if(count % TABLE_ROW_NUM == 0){
			printf("\n");
			count = 0;
		}
		else if (num_chars <= 7)
			printf("\t\t");
		else
			printf("\t");

		++count;
	} //end of for loop

	return 0;
}

/* Output:
I		II		III		IIII		V
VI		VII		VIII		VIIII		X
XI		XII		XIII		XIIII		XV
XVI		XVII		XVIII		XVIIII		XX
XXI		XXII		XXIII		XXIIII		XXV
XXVI		XXVII		XXVIII		XXVIIII		XXX
XXXI		XXXII		XXXIII		XXXIIII		XXXV
XXXVI		XXXVII		XXXVIII		XXXVIIII	XXXX
XXXXI		XXXXII		XXXXIII		XXXXIIII	XXXXV
XXXXVI		XXXXVII		XXXXVIII	XXXXVIIII	L
LI		LII		LIII		LIIII		LV
LVI		LVII		LVIII		LVIIII		LX
LXI		LXII		LXIII		LXIIII		LXV
LXVI		LXVII		LXVIII		LXVIIII		LXX
LXXI		LXXII		LXXIII		LXXIIII		LXXV
LXXVI		LXXVII		LXXVIII		LXXVIIII	LXXX
LXXXI		LXXXII		LXXXIII		LXXXIIII	LXXXV
LXXXVI		LXXXVII		LXXXVIII	LXXXVIIII	LXXXX
LXXXXI		LXXXXII		LXXXXIII	LXXXXIIII	LXXXXV
LXXXXVI		LXXXXVII	LXXXXVIII	LXXXXVIIII	C
*/
