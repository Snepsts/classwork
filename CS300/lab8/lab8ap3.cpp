/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
Date: 8/5/16 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include "split.h"

using std::cout;
using std::string;
using std::vector;

void stringtolower(string& word);

bool isnotIgnore(vector<string> ignore_list, const string& word);

int main(int argc, char** argv){
	int count = 0;
	vector<string> v, vf;
	string line, word;
	std::map<string, vector<int>> m;
	std::ifstream fin;

	fin.open("ignore.txt");
	if(fin.fail()){
		cout << "ignore.txt opening failed\n";
		fin.close();
		return 1;
	}

	while(fin >> word)
		vf.push_back(word); //vf = ignore_list

	while(getline(std::cin, line)){
		count++;
		v = csplit(line);
		for(auto word : v){
			stringtolower(word);
			if(isnotIgnore(vf, word))
				m[word].push_back(count);
		}
	}

	for(auto q : m){
		cout << q.first << ": ";
		int old = 0;
		for(auto q2 : q.second){
			if(q2 != old)
				cout << q2 << " ";
			old = q2;
		}
		cout << '\n';
	}

	return 0;
}

void stringtolower(string& word){
	for(unsigned i = 0; i < word.length(); i++)
		word[i] = tolower(word[i]);
}

bool isnotIgnore(vector<string> ignore_list, const string& word){
	for(auto q : ignore_list){
		if(word == q)
			return false;
	}
	return true;
}

/* Output:
absolutely: 5
according: 7
aeons: 1
against: 6
ago: 1
alone: 4
back: 10
begin: 3
can: 17
cohen: 7
companion: 11
comprehend: 3
conceive: 4
could: 3
discernible: 5
distant: 2
dog: 16 17
down: 12
effect: 5
elephant: 12
even: 4
frog: 7
from: 12
fullnes: 5
go: 15
had: 3
has: 16
have: 5
his: 11
if: 15
indian: 11
intelligence: 2
it: 15
jokes: 12
knight: 17
leonard: 7
let: 4
like: 17
line: 16
meanwhile: 10
mistaking: 11
much: 2
next: 15
no: 5
not: 3
now: 15
once: 1
orbiting: 1
own: 2
pond: 8
punch: 16
ranch: 10
sent: 17
shaggy: 16
sky: 6
so: 6
stars: 7
step: 12
story: 16
sun: 2
tell: 16
that: 16
this: 17
thought: 3
time: 1 5 15
tonto: 11
trust: 11
understand: 4
unlike: 2
upon: 1
verily: 7
very: 2 8
well: 15
which: 4
would: 4
*/
