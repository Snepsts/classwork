/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
*/

#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
#include <vector>
#include "split.h"

using std::size_t;
using std::string;
using std::cout;

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

int main(int argc, char const *argv[]){
	std::unordered_map<string, int, strhash> m(20, strhash());
	std::unordered_map<string, int, strhash2> m2(20, strhash2());
	std::unordered_map<string, int, std::hash<string>> m3(20, std::hash<string>());

	string word, line;
	std::vector<string> v;
	int count = 0;

	while(getline(std::cin, line)){
		count++;
		v = csplit(line);
		for(auto q : v){
			m.insert(std::make_pair(q, count));
			m2.insert(std::make_pair(q, count));
			m3.insert(std::make_pair(q, count));
		}
	}

	cout << "The first unordered_map has " << m.bucket_count() << " buckets!\n";
	for(size_t i = 0; i < m.bucket_count(); i++){
		cout << "Bucket #" << i << " has " << m.bucket_size(i) << " elements.\n";
	}

	cout << "The second unordered_map has " << m2.bucket_count() << " buckets!\n";
	for(size_t i = 0; i < m2.bucket_count(); i++){
		cout << "Bucket #" << i << " has " << m2.bucket_size(i) << " elements.\n";
	}

	cout << "The third unordered_map has " << m3.bucket_count() << " buckets!\n";
	for(size_t i = 0; i < m3.bucket_count(); i++){
		cout << "Bucket #" << i << " has " << m3.bucket_size(i) << " elements.\n";
	}

	return 0;
}

/* Output:
snepsts@michael-laptop:~/classwork/CS300/lab13$ ./lab13.out < shortstory.txt
The first unordered_map has 199 buckets!
Bucket #0 has 1 elements.
Bucket #1 has 0 elements.
Bucket #2 has 0 elements.
Bucket #3 has 1 elements.
Bucket #4 has 0 elements.
Bucket #5 has 0 elements.
Bucket #6 has 1 elements.
Bucket #7 has 0 elements.
Bucket #8 has 1 elements.
[...]
Bucket #190 has 1 elements.
Bucket #191 has 0 elements.
Bucket #192 has 0 elements.
Bucket #193 has 0 elements.
Bucket #194 has 0 elements.
Bucket #195 has 0 elements.
Bucket #196 has 0 elements.
Bucket #197 has 0 elements.
Bucket #198 has 0 elements.
The second unordered_map has 199 buckets!
Bucket #0 has 0 elements.
Bucket #1 has 103 elements.
Bucket #2 has 0 elements.
Bucket #3 has 0 elements.
Bucket #4 has 0 elements.
Bucket #5 has 0 elements.
Bucket #6 has 0 elements.
Bucket #7 has 0 elements.
Bucket #8 has 0 elements.
[...]
Bucket #190 has 0 elements.
Bucket #191 has 0 elements.
Bucket #192 has 0 elements.
Bucket #193 has 0 elements.
Bucket #194 has 0 elements.
Bucket #195 has 0 elements.
Bucket #196 has 0 elements.
Bucket #197 has 0 elements.
Bucket #198 has 0 elements.
The third unordered_map has 199 buckets!
Bucket #0 has 1 elements.
Bucket #1 has 2 elements.
Bucket #2 has 0 elements.
Bucket #3 has 0 elements.
Bucket #4 has 0 elements.
Bucket #5 has 1 elements.
Bucket #6 has 0 elements.
Bucket #7 has 0 elements.
Bucket #8 has 0 elements.
[...]
Bucket #190 has 3 elements.
Bucket #191 has 1 elements.
Bucket #192 has 0 elements.
Bucket #193 has 1 elements.
Bucket #194 has 0 elements.
Bucket #195 has 0 elements.
Bucket #196 has 1 elements.
Bucket #197 has 1 elements.
Bucket #198 has 1 elements.
*/
