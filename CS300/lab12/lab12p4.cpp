/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
Date: 10/31/16 */

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "split.h"

//object for getting the key from the map
struct GetKey{
	template <class T>
	typename T::first_type operator()(T kv) const{
		return kv.first;
	}
};

using std::cin;
using std::cout;
using std::copy;
using std::string;
using std::vector;

int main(int argc, char **argv){
	std::map<string, vector<int>> m; //part 5 map
	std::unordered_map<string, vector<int>> um; //part 6 unordered_map
	string line; //string for grabbing lines out of stdin (cin)
	vector<string> v; //vector for multiple uses
	int count = 0;

	while(getline(cin, line)){
		count++;
		v = csplit(line);
		//part 5
		for(auto q : v){
			if(m.find(q) == m.end())
				m[q].push_back(count);
			else{
				if(m[q].back() != count)
					m[q].push_back(count);
			}
		}

		//part 6
		for(auto q : v){
			if(um.find(q) == um.end())
				um[q].push_back(count);
			else{
				if(um[q].back() != count)
					um[q].push_back(count);
			}
		}
		v.clear(); //clear v for the next run/for the transformation
	}

	//part 5 transform/print begin

	//turn map keys into vector
	std::transform(m.begin(), m.end(), std::back_inserter(v), GetKey());

	cout << "\nPart 5:\n\n";

	//since the instruction is to reverse the order of the elements, we just use a reverse_iterator
	for(std::vector<string>::reverse_iterator vit = v.rbegin(); vit != v.rend(); vit++){
		cout << *vit << " : ";
		for(auto i : m[*vit])
			cout << i << " ";
		cout << '\n';
	}

	v.clear(); //clear v for the next transformation

	//part 5 transform/print end, part 6 begin

	std::transform(um.begin(), um.end(), std::back_inserter(v), GetKey());

	std::sort(v.begin(), v.end()); //sort the keys

	cout << "\nPart 6:\n\n";

	for(auto q : v){
		cout << q << " : ";
		for(auto i : um[q])
			cout << i << " ";
		cout << '\n';
	}

	cout << '\n';

	return 0;
}

/* Output:
snepsts@michael-laptop:~/classwork/CS300/lab12$ ./lab12p4.out < shortstory.txt

Part 5:

you : 15 16
would : 4
world : 1
which : 4
we : 2 3
very : 2 8
[...]
Lone : 11
Leonard : 7
Knight : 17
If : 15
I : 16
Cohen : 7

Part 6:

Cohen : 7
I : 16
If : 15
Knight : 17
Leonard : 7
Lone : 11
[...]
very : 2 8
we : 2 3
which : 4
world : 1
would : 4
you : 15 16
*/
