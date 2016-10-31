/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
Date: 9/26/16 */

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

/* Output:
Cohen: 7
I: 16
If: 15
Knight: 17
Leonard: 7
Lone: 11
Meanwhile: 10
Once: 1
Tonto: 11
Verily: 7
We: 6
Well: 15
You: 17
a: 1
a: 1
a: 1
a: 3
a: 7
a: 8
a: 12
a: 17
a: 17
absolutely: 5
according: 7
aeons: 1
against: 6
against: 6
ago: 1
alone: 4
an: 2
[...] //this means there is output removed for printing purposes
that: 16
the: 4
the: 6
the: 6
the: 10
the: 10
the: 16
the: 16
this: 17
thought: 3
time: 1
time: 5
time: 15
time: 15
to: 3
to: 7
to: 15
trust: 11
understand: 4
unlike: 2
upon: 1
us: 6
very: 2
very: 8
we: 2
we: 3
which: 4
world: 1
would: 4
you: 15
you: 16
*/
