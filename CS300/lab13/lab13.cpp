#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>

/* Lab13:
function object class - take string, return sum of absolute value of character codes
unordered string, int map with the class as a third parameter
the constructor needs 2 parameters, the first a suggested # of buckets (use 20)
the second a function object object of the function object class
do it all on an unordered_multimap as well
a) use built-in hash
b) use built-in hash but specify it when declaring the map.
c) write a function object which always returns 1 (a bad idea) and use it for the hash.

shortstory.txt
or each map find the bucket count and for each bucket find the bucket size.
*/

using std::size_t;
using std::string;

struct strhash{
	size_t operator()(const string& key) const{
		size_t r = 0;
		for(size_t i = 0; i < key.length(); i++)
			r += (size_t)key[i]; //cast to size_t

		return r;
	}
};

struct strhash2{
	size_t operator()(const string& key) const{
		return 1;
	}
};

struct strcomp{
	bool operator()(const string& k1, const string& k2) const{
		return (k1 == k2);
	}
};

int main(int argc, char const *argv[]){
	std::unordered_map<string, int, strhash, strcomp> m(20, strhash(), strcomp());
	string word;

	while(std::cin >> word){
		m.insert(std::make_pair(word, 1));
	}

	return 0;
}
