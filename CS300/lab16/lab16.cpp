/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

/* personal reminder
   dot makes directed graphs (digraph)
   neato makes undirected graphs (graph)
   dot -Tps graph.gv -o graph.ps */

/* First two files you want picture internally build a representation of a graph
digraph for second file
outputs into a file that has the syntax to build a picture
Second has states, and all states that begin with the last letter of the one state is connected
Third one is one letter difference connections
probably try breadth-first, no repeats, try it in a tree, maybe write a class, etc
have the user choose starting word, specifiy how far to go, etc
*/

using std::cerr;
using std::cout;
using std::string;
using std::map;
using std::ifstream;

//MUST PASS TWO STRINGS OF SAME SIZE (in my implementation there's nothing to worry about)
bool isNotInMap(const string& s, const map<string, int>& m);

//part 3 specific functions
bool isOneLetterDiff(const string& s1, const string& s2);
bool isInSGB(const string& s);
string findNewWord(const string& s, const map<string, int>& m);

int main(int argc, char* argv[]){
	std::ofstream fout;

	//part 1 & 2
	ifstream fin;
	string first, second;

	//part 2 specific
	ifstream fin2;
	map<string, std::vector<string>> mv;

	//part 3 specific
	map<string, int> m;
	string newstring, origstring, currstring;
	int amount;

	//part 1
	fin.open("usa.txt");
	if(fin.fail()){
		cerr << "Error opening \"usa.txt\" in main. Ending.\n";
		fin.close();
		return 1;
	}

	fout.open("usagraph.gv");

	fout << "graph USA{\n";
	while(fin >> first >> second){
		fout << first << " -- " << second << '\n';
	}
	fout << "}\n";

	fin.close();
	fout.close();

	//part 2
	fin.open("states.txt");
	if(fin.fail()){
		cerr << "Error opening \"states.txt\" in main. Ending.\n";
		fin.close();
		return 1;
	}

	while(fin >> first){
		fin2.open("states.txt");
		if(fin.fail()){
			cerr << "Error opening \"states.txt\" in main while loop. Ending.\n";
			fin.close();
			return 1;
		}

		while(fin2 >> second){
			if(first[1] == second[0])
				mv[first].push_back(second);
		}
		fin2.close();
	}

	fin.close();
	fout.open("stategraph.gv");mv[first].push_back(second);mv[first].push_back(second);
	fout << "digraph states{\n";
	for(auto q : mv){
		for(auto t : q.second){
			fout << q.first << " -> " << t << '\n';
		}
	}
	fout << "}\n";

	fout.close();

	//part 3
	do{
		cout << "Please enter a 5 letter word you would like to start from: ";
		std::cin >> origstring;
	}while(!isInSGB(origstring));

	m[origstring] = 0; //set as the origin (zeroth level)
	currstring = origstring; //set current string to the origin string

	do {
		cout << "Please enter how many \"runs\" (between 1 & 15) you would like to do: ";
		std::cin >> amount;
	}while(amount < 1 || amount > 16); //cap it at 15

	for(int i = 0; i < amount; i++){
		for(auto q : m){
			if(q.second != i) //if it's not on the current level ignore
				continue;
			else
				currstring = q.first;
			do{
				newstring = findNewWord(currstring, m);
				if(newstring != "done")
					m[newstring] = i+1;
			}while(newstring != "done");
		} //end for each
	} //end for

	/*for(auto q : m)
		cout << q.first << " : " << q.second << '\n';*/

	/* Here we create the graph file with the "graphviz" syntax for compiling.
	The general idea is each level can connect to the next level, but not any
	after that. So we do a check through the entire levels at and above the
	current level (i & i+1). If the difference is 1 letter we connect them. */
	fout.open("sgbgraph.gv");

	fout << "graph SGBwords{\n";

	for(int i = 0; i < amount; i++){
		for(auto q : m){
			if(q.second != i)
				continue;
			else
				currstring = q.first;
			for (auto t : m){
				if(t.second != i+1)
					continue;
				else
					newstring = t.first;
				if(isOneLetterDiff(currstring, newstring))
					fout << '\t' << currstring << " -- " << newstring << '\n';
			}
		}
	}

	fout << "}\n";
	fout.close();

	return 0;
}

bool isInSGB(const string& s){
	string comps;
	bool retvar = false;
	ifstream fin;
	fin.open("sgbwords.txt");

	if(fin.fail()){
		cerr << "ERROR: Could not open sgbwords.txt from function \"isInSGB\".\n";
		fin.close();
		return retvar;
	}

	while(fin >> comps){
		if(s == comps){
			retvar = true;
			break;
		} //end if
	}

	fin.close();
	return retvar;
}

string findNewWord(const string& s, const map<string, int>& m){
	static unsigned fcount = 0; //debugging purposes, check if the file fails to open after so many tries
	string comps;
	bool retvar = false; //default to false because we check to make it true
	fcount++;

	ifstream fin;
	fin.open("sgbwords.txt");

	if(fin.fail()){
		cerr << "ERROR: Could not open sgbwords.txt on \"findNewWord\" run number " << fcount << ".\n";
		fin.close();
		return "done";
	}

	while(fin >> comps){
		/* even though we assume the length is 5 from the file,
		we check for differences anyways */
		if(s.length() != comps.length()) //in case they're not the same length
			continue; //skip the whole check, since they're of different sizes

		if(isOneLetterDiff(s, comps)){ //check for 1 letter difference
			if(isNotInMap(comps, m)) //check if it's in the map
				return comps;
		} //end if(isOneLetterDiff)
	} //end while

	fin.close(); //close the file before we leave the function
	return "done";
}

bool isOneLetterDiff(const string& s1, const string& s2){
	int count = 0;

	//Compare the two, for each letter difference, increment count by 1
	for(size_t i = 0; i < s1.length(); i++){
		if(s1[i] != s2[i])
			count++;
	}

	if(count == 1) //if the difference is only 1 it's true
		return true;
	else //else false
		return false;
}

bool isNotInMap(const string& s, const map<string, int>& m){
	bool retvar = true;

	//check if the string is in the map
	for(auto q : m){
		if(s == q.first) //if so, set it to false
			retvar = false;
	}

	return retvar;
}
