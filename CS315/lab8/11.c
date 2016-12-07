#include <stdio.h>

struct hardware{
	int num;
	char name[30];
	int quantity;
	double cost;
} h[100];

int main(){
	FILE *fPtr;
	int whilevar = 0;
	int choicevar;

	fPtr = fopen("hardware.dat", "w+");
	fprintf(fPtr, "Record # Name\t\tQuantity Cost\n");

	for(size_t i = 0; i < 100; i++){
		h[i].num = (int)i+1;
		*h[i].name = '\0';
		h[i].quantity = 0;
		h[i].cost = 0.0;
		fwrite(&h[i], sizeof(struct hardware), 1, fPtr);
	}

	while(!whilevar){
		printf("Choose something:\n");
		printf("1 - Add an item\n");
		printf("2 - Remove an item\n");
		printf("3 - Print the file\n");
		printf("Anything else - Exit\n");

		scanf("%d", &choicevar);
		int i;
		char buf[4096];

		switch(choicevar){
			case 1:
				printf("Please enter the item you'd like to edit (1 - 100): ");
				scanf("%d", &i); i--;

				printf("Please enter the name: ");
				scanf("%s", h[i].name);
				printf("Please enter the quantity: ");
				scanf("%d", &h[i].quantity);
				printf("Plesae enter the cost: ");
				scanf("%lf", &h[i].cost);

				// seek position in file to user-specified record
				fseek(fPtr, (h[i].num - 1) * sizeof(struct hardware), SEEK_SET);
				// write user-specified information in file
				fwrite(&h[i], sizeof(struct hardware), 1, fPtr);
				break;

			case 2:
				printf("Please enter the item you'd like to edit (1 - 100): ");
				scanf("%d", &i); i--;

				*h[i].name = '\0';
				h[i].quantity = 0;
				h[i].cost = 0.0;

				// seek position in file to user-specified record
				fseek(fPtr, (h[i].num - 1) * sizeof(struct hardware), SEEK_SET);
				// write user-specified information in file
				fwrite(&h[i], sizeof(struct hardware), 1, fPtr);
				break;

			case 3:
				fseek(fPtr, 0, SEEK_SET);
				while(!feof(fPtr)){
					fputs(buf, fPtr);
					puts(buf);
				}
				break;

			default:
				whilevar = 1;
		}
	}
	fclose(fPtr);
	return 0;
}
