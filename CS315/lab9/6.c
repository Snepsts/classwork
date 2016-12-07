#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int a;
	char *s = "\0";

	if (argc != 3){
		printf("You should enter the program like this:\n %s file1 file2\n", argv[0]);
		return 1;
	}

	FILE *fin = fopen(argv[1], "r");
	if(fin == NULL){
		printf("%s does not exist as a file.\n", argv[1]);
		return 1;
	}

	FILE *fout = fopen(argv[2], "a");
	if(fout == NULL){
		printf("%s does not exist as a file\n", argv[2]);
	}

	fseek(fin, 0, SEEK_END);
	int finlen = ftell(fin);

	for(int i = finlen; i >= 0; i--)
	{
    	fseek(fin, i, SEEK_SET);
    	fputc(fgetc(fin), fout);
	}

	fclose(fin);
	fclose(fout);

	printf("Done!\n");

	return 0;
}

/* Output:
snepsts@michael-laptop:~/classwork/CS315/lab9$ ./a.out input.txt output.txt
Done! */

/* input.txt:
I do rather enjoy a good dolphin.
However, I also enjoy a rather good seagull.
I do not enjoy any cats though. They suck. */

/* output.txt:
.kcus yehT .hguoht stac yna yojne ton od I
.llugaes doog rehtar a yojne osla I ,revewoH
.nihplod doog a yojne rehtar od I */
