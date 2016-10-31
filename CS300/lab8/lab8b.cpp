/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
Date: 10/5/16 */

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>

using std::string;
using std::vector;
using std::cout;

struct GetKey{
	template <class T>
	typename T::first_type operator()(T kv) const{
		return kv.first;
	}
};

int main(int argc, char** argv){
	vector<string> keys;
	std::map<string, int> m;
	m["Dolphins"]++;
	m["are"]++;
	m["cool"]++;
	std::transform(m.begin(), m.end(), std::back_inserter(keys), GetKey());

	for(auto q : m)
		cout << q.first << " ";
	cout << '\n';

	for(auto q : keys)
		cout << q << " ";
	cout << '\n';

	return 0;
}

/* Output:
Dolphins are cool
Dolphins are cool
*/
