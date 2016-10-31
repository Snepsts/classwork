/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
Date: 9/19/16 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>

using std::cout;
using std::sort;
using std::vector;
using std::string;
using std::set;
using std::less;
using std::greater;
using std::priority_queue;

int main()
{
	vector<string> v = {"Six", "sick", "slick", "sycamore", "saplings"};
	vector<string> v2 = v, v3 = v;

	//part 1
	sort(v.begin(), v.end()); //default
	sort(v2.begin(), v2.end(), less<string>()); //default with third parameter
	sort(v3.begin(), v3.end(), greater<string>()); //third parameter

	cout << "Default: \n";
	for(auto q : v)
		cout << q << " ";
	cout << "\n\nDefault with third parameter: \n";
	for(auto q : v2)
		cout << q << " ";
	cout << "\n\nDifferent third parameter: \n";
	for(auto q : v3)
		cout << q << " ";
	cout << '\n';

	//part 2
	set<string> s = {"Six", "sick", "slick", "sycamore", "saplings"};
	set<string, less<string>> s2 = {"Six", "sick", "slick", "sycamore", "saplings"};
	set<string, greater<string>> s3 = {"Six", "sick", "slick", "sycamore", "saplings"};

	cout << "\nDefault set: \n";
	for(auto q : s)
		cout << q << " ";
	cout << "\n\nSet with less: \n";
	for(auto q : s2)
		cout << q << " ";
	cout << "\n\nSet with greater: \n";
	for(auto q : s3)
		cout << q << " ";
	cout << '\n';

	//part 3
	priority_queue<string, vector<string>> pq;
	priority_queue<string, vector<string>, less<string>> pq2;
	priority_queue<string, vector<string>, greater<string>> pq3;

	for(auto q : v){
		pq.push(q);
		pq2.push(q);
		pq3.push(q);
	}

	cout << "\nDefault priority_queue: \n";
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << "\n\nPriority_queue with less: \n";
	while(!pq2.empty()){
		cout << pq2.top() << " ";
		pq2.pop();
	}
	cout << "\n\nPriority_queue with greater: \n";
	while(!pq3.empty()){
		cout << pq3.top() << " ";
		pq3.pop();
	}
	cout << '\n';

	return 0;
}

/* Output:
Default:
Six saplings sick slick sycamore

Default with third parameter:
Six saplings sick slick sycamore

Different third parameter:
sycamore slick sick saplings Six

Default set:
Six saplings sick slick sycamore

Set with less:
Six saplings sick slick sycamore

Set with greater:
sycamore slick sick saplings Six

Default priority_queue:
sycamore slick sick saplings Six

Priority_queue with less:
sycamore slick sick saplings Six

Priority_queue with greater:
Six saplings sick slick sycamore
*/
