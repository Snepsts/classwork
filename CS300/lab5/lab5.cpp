#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cctype>
#include <string>
#include <functional>
#include "split.h"

using std::string;
using std::vector;

void stringtolower(string& word);

int main()
{
	vector<string> vst;
	std::map<string, int> m1;
	std::map<string, vector<int>> m2, m3, m4;
	std::map<string, vector<int>>::iterator it;
	string line;
	int count = 0;

	std::ifstream fin;
	fin.open("shortstory.txt");

	if(fin.fail())
	{
		std::cerr << "shortstory.txt failed to open, does it even exist?\n";
		//exit(1)
	}

	while(getline(fin, line)) //Take care of all the calculations at once
	{
		count++;
		stringtolower(line);
		vst = csplit(line);
		//part 1 & 3.b
		for(vector<string>::iterator vit = vst.begin(); vit != vst.end(); vit++)
		{
			m1[*vit]++;
			m3[*vit].push_back(count);
		}
		//part 2 & 3.a
		for(vector<string>::iterator vit = vst.begin(); vit != vst.end(); vit++)
		{
			if((it = m2.find(*vit)) == m2.end()) //insert a new pair if the string doesn't already exist
				m2.insert(make_pair(*vit, vector<int>{count}));
			else //else add the line count to the vector
				(*it).second.push_back(count);
		}
		//part 4
		for(vector<string>::iterator vit = vst.begin(); vit != vst.end(); vit++)
		{
			if((it = m4.find(*vit)) == m4.end())
				m4.insert(make_pair(*vit, vector<int>{count}));
			else
				if((*it).second.back() != count) //only push_back if there isn't already the same count there.
					(*it).second.push_back(count);
		}
	}

	std::cout << "Part 1: \n\n\n";

	for(auto q : m1)
		std::cout << q.first << ": " << q.second << '\n';

	std::cout << "\n\n\nPart 2: \n\n\n";

	for(auto q : m2)
		std::cout << q.first << "::: " << q.second.size() << '\n';

	std::cout << "\n\n\nPart 3.a: \n\n\n";

	for(auto q : m2)
	{
		std::cout << q.first;
		for(vector<int>::iterator vit = q.second.begin(); vit != q.second.end(); vit++)
			std::cout << ": " << *vit << " ";
		std::cout << '\n';
	}

	std::cout << "\n\n\nPart 3.b: \n\n\n";

	for(auto q : m3)
	{
		std::cout << q.first;
		for(vector<int>::iterator vit = q.second.begin(); vit != q.second.end(); vit++)
			std::cout << ": " << *vit << " ";
		std::cout << '\n';
	}

	std::cout << "\n\n\nPart 4: \n\n\n";

	for(auto q : m3)
	{
		int varray[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		//assume there will be no more than 20 members of each vector
		int count = 0; //this is the count for the array checker
		               //default to 0
		bool checker = true; //this is the checker to print the vector integers
		                     //default the checker to true

		std::cout << q.first;

		for(vector<int>::iterator vit = q.second.begin(); vit != q.second.end(); vit++){
			for(int i = 0; i < 20; i++){ //if *vit has already been printed
			                             //this will prevented of being printed again
				if(varray[i] == *vit)
					checker = false;
			}

			if(checker)
				std::cout << ": " << *vit << " ";
			varray[count] = *vit;
			count++;
			checker = true;
		}
		std::cout << '\n';
	}

	std::cout << "\n\n\nPart 5: \n\n\n";

	for(auto q : m3)
	{
		int varray[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		//assume there will be no more than 20 members of each vector
		int count = 0; //this is the count for the array checker
					   //default to 0
		bool checker = true; //this is the checker to print the vector integers
							 //default the checker to true

		std::cout << q.first;

		for(vector<int>::iterator vit = q.second.begin(); vit != q.second.end(); vit++){
			for(int i = 0; i < 20; i++){ //if *vit has already been printed
										 //this will prevented of being printed again
				if(varray[i] == *vit)
					checker = false;
			}

			if(checker)
				std::cout << ": " << *vit << " ";
			varray[count] = *vit;
			count++;
			checker = true;
		}
		std::cout << "::: " << q.second.size() << '\n';
	}

	return 0;
}

void stringtolower(string& word)
{
	for(unsigned i = 0; i < word.length(); i++)
		word[i] = tolower(word[i]);
}

/* Note: The formatting for this program goes like this:
: # means the line(s) the word appears in the file.
::: # means the amount of times the word appears in the file.
[...] means there are skipped lines to save printing paper.

=====================================OUTPUT=====================================
Part 1:


a: 9
absolutely: 1
according: 1
aeons: 1
against: 2
ago: 1
[...]
we: 3
well: 1
which: 1
world: 1
would: 1
you: 3



Part 2:


a::: 9
absolutely::: 1
according::: 1
aeons::: 1
against::: 2
ago::: 1
[...]
we::: 3
well::: 1
which::: 1
world::: 1
would::: 1
you::: 3



Part 3.a:


a: 1 : 1 : 1 : 3 : 7 : 8 : 12 : 17 : 17
absolutely: 5
according: 7
aeons: 1
against: 6 : 6
ago: 1
[...]
we: 2 : 3 : 6
well: 15
which: 4
world: 1
would: 4
you: 15 : 16 : 17



Part 3.b:


a: 1 : 1 : 1 : 3 : 7 : 8 : 12 : 17 : 17
absolutely: 5
according: 7
aeons: 1
against: 6 : 6
ago: 1
[...]
we: 2 : 3 : 6
well: 15
which: 4
world: 1
would: 4
you: 15 : 16 : 17



Part 4:


a: 1 : 3 : 7 : 8 : 12 : 17
absolutely: 5
according: 7
aeons: 1
against: 6
ago: 1
[...]
we: 2 : 3 : 6
well: 15
which: 4
world: 1
would: 4
you: 15 : 16 : 17



Part 5:


a: 1 : 3 : 7 : 8 : 12 : 17 ::: 9
absolutely: 5 ::: 1
according: 7 ::: 1
aeons: 1 ::: 1
against: 6 ::: 2
ago: 1 ::: 1
[...]
we: 2 : 3 : 6 ::: 3
well: 15 ::: 1
which: 4 ::: 1
world: 1 ::: 1
would: 4 ::: 1
you: 15 : 16 : 17 ::: 3
*/
