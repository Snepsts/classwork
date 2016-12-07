#include <stdio.h>

int main(int argc, char const *argv[]) {
	for (size_t i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}

	printf("\n");
	return 0;
}

/* Output:
snepsts@michael-laptop:~/classwork/CS315/lab9$ ./a.out I do rather enjoy a good dolphin
I do rather enjoy a good dolphin */
