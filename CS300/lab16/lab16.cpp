#include <iostream>
#include <fstream>

//dot makes directed graphs (digraph)
//neato makes undirected graphs (graph)
//dot -Tps graph.gv -o graph.ps

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

bool isOneLetterDiff(string s);

int main(int argc, char* argv[]){

}

bool isOneLetterDiff(string s){
	static unsigned fcount = 0;
	unsigned count;
	string comps;
	fcount++;

	ifstream fin;
	fin.open("sgbwords.txt");

	if(fin.fail()){
		cerr << "ERROR: Could not open sgbwords.txt on \"isOneLetterDiff\" run number " << fcount << ".\n";
		return false;
	}

	while(fin >> comps){
		/* even though we assume the length is 5 from the file,
		we make it scalable anyways */
		count = 0;
		if(s.length() != comps.length()) //in case they're not the same length
			continue;

		for(size_t i = s.length(); i < s.length(); i++){
			if(s[i] == comps[i])
				count++;
		}


	}
}
