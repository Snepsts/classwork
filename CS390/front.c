#include <stdio.h>
#include <ctype.h>
#include <string.h>

//global variables
//variables
int char_class;
char lexeme[100];
char next_char;
int lex_len;
int token;
int next_token;
FILE *in_fp, *fopen();

//function declarations
void add_char();
void get_char();
void get_non_blank();
int lex();

//character classes
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

//token codes
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26
#define FOR 30
#define IF 31
#define ELSE 32
#define WHILE 33
#define DO 34
#define INT 35
#define FLOAT 36
#define SWITCH 37

int main()
{
	/* Open the input data file and process its contents */
	if ((in_fp = fopen("front.in", "r")) == NULL)
		printf("ERROR - cannot open front.in \n");

	else {
		get_char();

		do {
			lex();
		} while (next_token != EOF);
	}

	return 0;
}

/* lookup - a function to lookup operators and parentheses
and return the token */
int lookup(char ch)
{
	switch (ch) {
		case '(':
			add_char();
			next_token = LEFT_PAREN;
			break;
		case ')':
			add_char();
			next_token = RIGHT_PAREN;
			break;
		case '+':
			add_char();
			next_token = ADD_OP;
			break;
		case '-':
			add_char();
			next_token = SUB_OP;
			break;
		case '*':
			add_char();
			next_token = MULT_OP;
			break;
		case '/':
			add_char();
			next_token = DIV_OP;
			break;
		default:
			add_char();
			next_token = EOF;
			break;
	}

	return next_token;
}

/* add_char - a function to add next_char to lexeme */
void add_char()
{
	if (lex_len <= 98) {
		lexeme[lex_len++] = next_char;
		lexeme[lex_len] = 0;
	} else {
		printf("Error - lexeme is too long \n");
	}
}

/* get_char - a function to get the next character of input and determine its
 * character class
 */
void get_char()
{
	if ((next_char = getc(in_fp)) != EOF) {
		if (isalpha(next_char))
			char_class = LETTER;
		else if (isdigit(next_char))
			char_class = DIGIT;
		else char_class = UNKNOWN;
	} else {
		char_class = EOF;
	}
}

/* get_non_blank - a function to call get_char until it returns a non-whitespace
 * character
 */
void get_non_blank()
{
	while (isspace(next_char))
		get_char();
}

//lex - a simple lexical analyzer for arithmetic expressions
int lex()
{
	lex_len = 0;
	get_non_blank();
	switch (char_class) {
		case LETTER: //parse identifiers
			add_char();
			get_char();
			while (char_class == LETTER || char_class == DIGIT) {
				add_char();
				get_char();
			}

			if (strcmp(lexeme, "for") == 0) {
				next_token = FOR;
				break;
			} else if (strcmp(lexeme, "if") == 0) {
				next_token = IF;
				break;
			} else if (strcmp(lexeme, "else") == 0) {
				next_token = ELSE;
				break;
			} else if (strcmp(lexeme, "while") == 0) {
				next_token = WHILE;
				break;
			} else if (strcmp(lexeme, "do") == 0) {
				next_token = DO;
				break;
			} else if (strcmp(lexeme, "int") == 0) {
				next_token = INT;
				break;
			} else if (strcmp(lexeme, "float") == 0) {
				next_token = FLOAT;
				break;
			} else if (strcmp(lexeme, "switch") == 0) {
				next_token = SWITCH;
				break;
			}

			next_token = IDENT;
			break;
		case DIGIT: //parse integer literals
			add_char();
			get_char();
			while (char_class == DIGIT) {
				add_char();
				get_char();
			}
			next_token = INT_LIT;
			break;
		case UNKNOWN: // parentheses and operators
			lookup(next_char);
			get_char();
			break;
		case EOF: //End Of File
			next_token = EOF;
			lexeme[0] = 'E';
			lexeme[1] = 'O';
			lexeme[2] = 'F';
			lexeme[3] = 0;
			break;
	} //end of switch
	printf("Next token is: %d, Next lexeme is %s\n", next_token, lexeme);

	return next_token;
} //end of function lex
