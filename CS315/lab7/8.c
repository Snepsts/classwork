#include <stdio.h>

#define PI 3.14159265359

void display_choices();
void circumference(double x);
void area(double x);
void volume(double x);

int main(){
	int choice;
	double x;

	void(*f[3])(double) = {circumference, area, volume};

	printf("What would you like to do?\n");

	do{
		display_choices();
		scanf("%d", &choice);
		if(choice >= 0 && choice <= 2){
			printf("Please enter the radius for the circle: ");
			scanf("%lf", &x);
			(*f[choice])(x);
		}
	}while(choice != 3);

	return 0;
}

void display_choices(){
	printf("0 - Circumference\n");
	printf("1 - Area\n");
	printf("2 - Volume of a Sphere\n");
	printf("3 - Quit\n");
}

void circumference(double x){
	printf("The circumference of a circle with a radius %f is %f\n", x, 2 * PI * x);
}

void area(double x){
	printf("The area of a circle with a radius of %f is %f\n", x, x * x * PI);
}

void volume(double x){
	printf("The volume of a sphere with a radius of %f is %f\n", x, x * x * x * (4 / 3) * PI);
}
