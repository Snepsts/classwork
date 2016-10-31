/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
Date: 10/17/16 */

/*DESCRIPTION:
Using this program requires command line parameters.
Either use standard input to give the program text OR use a file as the first parameter.
If you want to use sort or only see a certain amount of numbers, you'll need to pass a second parameter.
-s | s = sort
10 = first 10 lines
-10 = last 10 lines
If you want to use standard input AND sort or filter you'll need to pass a filler first parameter:
./lab10.out < text.txt filler -s
That's all there is to it, enjoy!
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>

using std::string;
using std::cin;
using std::cout;

bool isNumber(char number[]); //basically isdigit() for argv[2], our second parameter
bool isS(char s[]); //check if an s or -s is passed

int main(int argc, char** argv){
	std::ostream_iterator<string> ost(std::cout, "\n"); //stdout, and also a newline after each print
	std::istream_iterator<char> eof; //blank input iterator
	std::vector<string> v; //vector for storing lines/words
	string line; //string for various lines
	string word; //string for various words
	unsigned int linecount = 0;

	bool isNum = false; //by default there is no number parameter
	bool isSort = false; //by default we do not sort
	int Num; //value for placing a number into the

	std::ifstream ifstr;

	noskipws(ifstr); //ensure ifstream works properly with our code
	noskipws(cin); //ensure cin works properly with the code

	if(argc > 1)
		ifstr.open(argv[1]); //attempt to open the file

	if(argc > 2){ //check if there is a numeric value for the lines we want to read in
		if(isNumber(argv[2]) && argv[2] != 0){
			isNum = true; //we are limiting how many lines we print
			Num = std::stoi(argv[2]); //convert the argv to an actual value
		}
		else if(isS(argv[2])) //if the second parameter passes -s or s
			isSort = true; //then we are sorting the input into ascending order
	} //end if(argc > 2)

	std::istream& in = ((argc > 1) && ifstr.good()) ? ifstr : cin; /*is only true if the file is opened
	                                                   True : False */
	if(!isSort){ //Do it by lines if we're not sorting the input
		for(std::istream_iterator<char> ist(in); ist != eof; ist++){
			if(*ist == '\n'){ //if it's the end of the line
				linecount++; //keep track of the number of lines
				v.push_back(line); //push back string so the entire line is recorded
				line.clear(); //clear the line string so we can use it again
			}
			else
				line += *ist; //add the character to the line
		} //end for
	} //end if
	else{ //isSort is true
		for(std::istream_iterator<char> ist(in); ist != eof; ist++){
			if(*ist == '\n' || *ist == ' '){ //if it's the end of the line
				v.push_back(word); //push back word so it's in the vector for sorting
				word.clear(); //clear the word string so we can reuse it
			}
			else
				word += *ist; //add the character to the line
		} //end for
		std::sort(v.begin(), v.end());
	} //end else

	if(isNum){
		if(Num > 0){ //if it's positive, we want to see it from the top
			for(; linecount > Num; linecount--)
				v.pop_back();
		}
		if(Num < 0){ //if it's negative, we want to see it from the bottom
			int Num2 = Num * 2;
			Num -= Num2; //make Num positive
			for(; linecount > Num; linecount--)
				v.erase(v.begin());
		}
	}

	copy(v.begin(), v.end(), ost); //output

	return 0;
}

bool isNumber(char number[]){
	unsigned i = 0;

	if(number[0] == '-')
		i = 1; //skip the '-' for negative numbers

	for(; number[i] != 0; i++){
		if(!isdigit(number[i]))
			return false;
	}

	return true;
}

bool isS(char s[]){
	unsigned i = 0;
	bool retval;

	if(s[0] == '-')
		i = 1; //skip the '-' for passing -s

	for(; s[i] != ' ' && s[i] != '\0' && s[i] != '\n'; i++){
		if(s[i] == 's')
			retval = true;
		else
			retval = false;
	}

	return retval;
}

/* text.txt
This is a line of text
This is another line of text
This is ALL OF THE TEXT
This is part of the text
I have some of the text right here
This is the sixth line
There is not much text left
Sometimes there isn't any text at all
However right now there is still some text
I hate writing .txt files
Skip line!
This is the twelfth line
This is the last line
*/

/* Output:
snepsts@michael-laptop:~/classwork/CS300/lab10$ ./lab10.out text.txt
This is a line of text
This is another line of text
This is ALL OF THE TEXT
[...]
Skip line!
This is the twelfth line
This is the last line

snepsts@michael-laptop:~/classwork/CS300/lab10$ ./lab10.out < text.txt
This is a line of text
This is another line of text
This is ALL OF THE TEXT
[...]
Skip line!
This is the twelfth line
This is the last line

snepsts@michael-laptop:~/classwork/CS300/lab10$ ./lab10.out text.txt -s
.txt
ALL
However
I
I
OF
[...]
the
the
there
there
twelfth
writing

snepsts@michael-laptop:~/classwork/CS300/lab10$ ./lab10.out text.txt 10
This is a line of text
This is another line of text
This is ALL OF THE TEXT
This is part of the text
I have some of the text right here
This is the sixth line
There is not much text left
Sometimes there isn't any text at all
However right now there is still some text
I hate writing .txt files

snepsts@michael-laptop:~/classwork/CS300/lab10$ ./lab10.out text.txt -10
This is part of the text
I have some of the text right here
This is the sixth line
There is not much text left
Sometimes there isn't any text at all
However right now there is still some text
I hate writing .txt files
Skip line!
This is the twelfth line
This is the last line
*/
