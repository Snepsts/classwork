#include <stdio.h>

int main(){
	int numbers[7];

	for (size_t i = 0; i < 7; i++) {
		scanf("%d", &numbers[i]);
	}

	char c = 'a';
	c++;
	printf("%c\n", c);

	FILE *fPtr = fopen("numbers.txt", "w");
	char a = 'a'; char b = 'a'; char c = 'a'; char d = 'a'; char e = 'a'; char f = 'a'; char g = 'a';
	for (size_t i = 0; i < count; i++){
		fprintf(fPtr, a);
		for (size_t i = 0; i < count; i++){
			fprintf(fPtr, b);
			for (size_t i = 0; i < count; i++){
				fprintf(fPtr, c);
				for (size_t i = 0; i < count; i++){
					fprintf(fPtr, d);
					for (size_t i = 0; i < count; i++){
						fprintf(fPtr, e);
						for (size_t i = 0; i < count; i++){
							fprintf(fPtr, f);
							for (size_t i = 0; i < count; i++){
								fprintf(fPtr, g);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
//nevermind fuck this I give up
