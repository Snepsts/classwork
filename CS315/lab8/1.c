#include <stdio.h>

struct inventory{
	char partName[30];
	int partNumber;
	float price;
	int stock;
	int reorder;
};

union data{
	char c;
	short s;
	long b;
	float f;
	double d;
};

struct address{
	char streetAddress[25];
	char city[20];
	char state[3];
	char zipCode[6];
};

struct student{
	char firstName[15];
	char lastName[15];
	address homeAddress;
};

struct test{
	unsigned a : 1;
	unsigned b : 1; //2
	unsigned c : 1;
	unsigned d : 1; //4
	unsigned e : 1;
	unsigned f : 1;
	unsigned g : 1;
	unsigned h : 1; //8
	unsigned i : 1;
	unsigned j : 1;
	unsigned k : 1;
	unsigned l : 1;
	unsigned m : 1;
	unsigned n : 1;
	unsigned o : 1;
	unsigned p : 1; //16
};

int main(){


	return 0;
}
