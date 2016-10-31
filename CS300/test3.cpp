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

bool ignore_words(const string& word);

int main(int argc, char** argv){
	int count = 0;
	vector<string> v, vf;
	string line;
	std::map<string, vector<int>> m;
	std::ifstream fin;

	fin.open("ignore.txt"){
		
	}

	while(getline(std::cin, line)){
		count++;
		v = csplit(line);
		for(auto word : v){
			stringtolower(word);
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

bool ignore_words(vector<string> v, const string& word){
	for(auto q : v){
		if(word == q)
			return false;
	}
	return true;
}
