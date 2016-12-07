#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include "split.h"
#include "Queue.h"
#include "Stack.h"

using std::string;
using std::vector;
using std::cout;

void stringtolower(string& word);

int main(int argc, char** argv){
	string line;
	vector<string> v, vt;
	std::ostream_iterator<string> ost(std::cout, "\n");

	//part 1 begins here
	while(getline(std::cin, line)){
		stringtolower(line);
		vt = csplit(line);

		for(auto word : vt){
			v.push_back(word);
		}
	} //end while

	std::sort(v.begin(), v.end(), [](string a, string b){
		if(a.length() == b.length()) //if they are of equal length, evaluate alphabetically
			return(a < b);
		else
			return (a.length() < b.length()); //else evaluate by length
		});

	std::copy(v.begin(), v.end(), ost); //output
	//part 1 ends here

	//part 2 begins here
	Queue<string> q;
	q.enqueue("If"); q.enqueue("you"); q.enqueue("see"); q.enqueue("this");
	q.enqueue("then"); q.enqueue("the"); q.enqueue("Queue"); q.enqueue("works");

	while (!q.empty()){
		cout << q.front() << " ";
		q.dequeue();
	}
	cout << '\n';
	//part 2 ends here

	//part 3 begins here
	Stack<string> s;
	s.push("works"); s.push("Stack"); s.push("the"); s.push("then");
	s.push("this"); s.push("see"); s.push("you"); s.push("If");

	while (!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << '\n';
	//part 3 ends here

	return 0;
}

void stringtolower(string& word){
	for(unsigned i = 0; i < word.length(); i++)
		word[i] = tolower(word[i]);
}
