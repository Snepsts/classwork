#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include "split.h"

using std::string;
using std::cout;
using std::vector;
using std::pair;

int main(int argc, char** argv){
	std::priority_queue<pair<string, unsigned>, vector<pair<string, unsigned> >, std::greater<pair<string, unsigned> > > pq;
	string line;
	vector<string> v;
	int count = 0;
	while(getline(std::cin, line)){
		count++;
		v = csplit(line);
		for(auto word : v)
			pq.push(std::make_pair(word, count));
	}

	while(!pq.empty()){
		cout << pq.top().first << ": " << pq.top().second << '\n';
		pq.pop();
	}

	cout << '\n';

	return 0;
}
