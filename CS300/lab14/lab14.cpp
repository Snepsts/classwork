/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
*/

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <string>
#include <vector>
#include <unistd.h>

using std::string;

/* Each number in the diceware equals a word, numbers are 5 chars
long (11111, 11112) you run it three times and combine the three
words into one and print it out. Use random distribution engine
with a range of (1,6) and have it generate five numbers
*/

string getstr(string s);

int main(int argc, char* argv[])
{
	bool set_count = false;
	bool set_length = false;
	string number, word, c;
	std::vector<string> v;
	std::default_random_engine dre;
	dre.seed(time(nullptr));
	std::uniform_int_distribution<int> dr(1, 6);
	size_t count;
	size_t length;

	if (argc > 2) {
		count = std::stoi(argv[1]);
		length = std::stoi(argv[2]);
	} else if (argc > 1) {
		count = std::stoi(argv[1]);
		set_length = true;
	} else {
		set_count = true;
		set_length = true;
	}

	if (set_count) {
		std::cout << "How many runs would you like?\n";
		std::cin >> count;
	}

	if (set_length) {
		std::cout << "How many words per run would you like?\n";
		std::cin >> length;
	}

	for (size_t i = 0; i < count; i++) {
		for (size_t j = 0; j < length; j++) {
			for (size_t t = 0; t < 5; t++) {
				int x = dr(dre);
				c = std::to_string(x);
				std::cout << x << '\n';
				number += c;
			}
			//std::cout << number << '\n';
			word += getstr(number);
			number.clear();
		}
		v.push_back(word);
		word.clear();
	}

	for(auto q : v){
		std::cout << q << '\n';
	}

	return 0;
}

string getstr(string s){
	string r;

	std::ifstream fin;
	fin.open("diceware.txt");
	if(fin.fail()){
		std::cerr << "diceware.txt failed to open\n";
		return "failure";
	}

	while(r != s){
		fin >> r;
	}

	fin >> r;
	fin.close();

	return r;
}

/* Output:
snepsts@michael-laptop:~/classwork/CS300/lab14$ ./lab14.out
How many runs would you like?
4
yaltajerseytunnel
moneyteachpablo
beadstonepyre
embrash84th
snepsts@michael-laptop:~/classwork/CS300/lab14$ ./lab14.out 5
ugstankdido
sapcometsarah
luckofferbroke
sheerslam333
danteginocanoe
*/
