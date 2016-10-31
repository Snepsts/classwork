#include <stdio.h>

int main(){
	int donewithfirstline = 0; //this is for the "and" for the last statement

	for(int i = 1; i <= 12; ++i){
		printf("On the ");
		switch (i) {
			case 1:
				printf("first ");
				break;
			case 2:
				printf("second ");
				break;
			case 3:
				printf("third ");
				break;
			case 4:
				printf("fourth ");
				break;
			case 5:
				printf("fifth ");
				break;
			case 6:
				printf("sixth ");
				break;
			case 7:
				printf("seventh ");
				break;
			case 8:
				printf("eighth ");
				break;
			case 9:
				printf("ninth ");
				break;
			case 10:
				printf("tenth ");
				break;
			case 11:
				printf("eleventh ");
				break;
			case 12:
				printf("twelfth ");
				break;
		} //end of switch

		printf("day of Christmas, my true love gave to me ");

		switch (i) {
			case 12:
				printf("twelve drummers drumming, ");
			case 11:
				printf("eleven pipers piping, ");
			case 10:
				printf("ten lords a leaping, ");
			case 9:
				printf("nine ladies dancing, ");
			case 8:
				printf("eight maids a milking, ");
			case 7:
				printf("seven swans a swimming, ");
			case 6:
				printf("six geese a laying, ");
			case 5:
				printf("five golden rings, ");
			case 4:
				printf("four calling birds, ");
			case 3:
				printf("three French hens, ");
			case 2:
				printf("two turtle doves, ");
			case 1:
				if (donewithfirstline)
					printf("and ");
				printf("a partridge on a pear tree.\n");
				break;
		} //end of switch
		donewithfirstline = 1;
	}

	return 0;
}

/* Output:
On the first day of Christmas, my true love gave to me a partridge on a pear tree.
On the second day of Christmas, my true love gave to me two turtle doves, and a partridge on a pear tree.
On the third day of Christmas, my true love gave to me three French hens, two turtle doves, and a partridge on a pear tree.
On the fourth day of Christmas, my true love gave to me four calling birds, three French hens, two turtle doves, and a partridge on a pear tree.
On the fifth day of Christmas, my true love gave to me five golden rings, four calling birds, three French hens, two turtle doves, and a partridge on a pear tree.
On the sixth day of Christmas, my true love gave to me six geese a laying, five golden rings, four calling birds, three French hens, two turtle doves, and a partridge on a pear tree.
On the seventh day of Christmas, my true love gave to me seven swans a swimming, six geese a laying, five golden rings, four calling birds, three French hens, two turtle doves, and a partridge on a pear tree.
On the eighth day of Christmas, my true love gave to me eight maids a milking, seven swans a swimming, six geese a laying, five golden rings, four calling birds, three French hens, two turtle doves, and a partridge on a pear tree.
On the ninth day of Christmas, my true love gave to me nine ladies dancing, eight maids a milking, seven swans a swimming, six geese a laying, five golden rings, four calling birds, three French hens, two turtle doves, and a partridge on a pear tree.
On the tenth day of Christmas, my true love gave to me ten lords a leaping, nine ladies dancing, eight maids a milking, seven swans a swimming, six geese a laying, five golden rings, four calling birds, three French hens, two turtle doves, and a partridge on a pear tree.
On the eleventh day of Christmas, my true love gave to me eleven pipers piping, ten lords a leaping, nine ladies dancing, eight maids a milking, seven swans a swimming, six geese a laying, five golden rings, four calling birds, three French hens, two turtle doves, and a partridge on a pear tree.
On the twelfth day of Christmas, my true love gave to me twelve drummers drumming, eleven pipers piping, ten lords a leaping, nine ladies dancing, eight maids a milking, seven swans a swimming, six geese a laying, five golden rings, four calling birds, three French hens, two turtle doves, and a partridge on a pear tree.
*/
