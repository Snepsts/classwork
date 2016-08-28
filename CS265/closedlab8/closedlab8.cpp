/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/29/16
*/

#include <iostream>
#include <sstream>
#include "containers.h"
#include "listqueue.h"

using namespace std;

int main()
{
	int array[6] = {1, 2, 3, 4, 5, 6};
	istringstream ss ("1 2 3 4 5 6 7 8 9 10");
	vector<int> v;
	v.push_back(5); v.push_back(10); v.push_back(15); v.push_back(20); v.push_back(25);
	listqueue<int> lq;

	containers<int> c1;
	containers<char> c2;

	//VECTOR_TEST: do searchbyindex and searchbyiterator, once with int and once with char
	cout << "If you see 1, 4, 0, and 2... then both searchbyindex and searchbyiterator are successful.\n";
	cout << "[program]: Calling c1: searchbyindex(10)\n";
	cout << c1.vecsearchindex(10) << endl;
	cout << "[program]: Calling c1: searchbyiterator(25)\n";
	cout << c1.vecsearchiterator(25) << endl;
	cout << "[program]: Calling c2: searchbyindex(\'a\')\n";
	cout << c2.vecsearchindex('a') << endl;
	cout << "[program]: Calling c2: searchbyiterator(\'c\')\n";
	cout << c2.vecsearchiterator('c') << endl;

	//DEQUE_TEST: do addfirstsixints, displaydeque, and changebackvalue
	cout << "[program]: Calling c1: addfirstsixints(array)\n";
	c1.addfirstsixints(array);
	cout << "If you see 1-6 displayed, then displaydeque & addfirstsixints are successful.\n";
	cout << "[program]: Calling c1: displaydeque()\n";
	c1.displaydeque();
	cout << "[program]: Calling c1: changebackvalue(9)\n";
	c1.changebackvalue(9);
	cout << "If you see 1-5 and 9 displayed, then changebackvalue is successful.\n";
	cout << "[program]: Calling c1: displaydeque()\n";
	c1.displaydeque();

	//LIST_TEST: do inputstreamfunction, vectolist, and changelstto
	cout << "[program]: Calling c1: inputstreamfunction(ss)\n";
	c1.inputstreamfunction(ss);
	cout << "If you see the numbers 1-10, then inputstreamfunction is successful.\n";
	cout << "[program]: Calling c1: displaylst()\n";
	c1.displaylst();
	cout << "[program]: Calling c1: clearlst()\n";
	c1.clearlst();
	cout << "[program]: Calling c1: vectolist(v)\n";
	c1.vectolist(v);
	cout << "[program]: Calling c1: changelstto(10, 50)\n";
	c1.changelstto(10, 50);
	cout << "If you see 5, 50, 15, 20, 25 then vectolist & changelstto are successful.\n";
	cout << "[program]: Calling c1: displaylst()\n";
	c1.displaylst();

	//LISTQUEUE_TEST: do all the functions of listqueue
	cout << "[program]: Calling lq: empty()\n";
	if (lq.empty())
		cout << "The listqueue is empty!\n";
	else
		cout << "The listqueue is NOT empty!\n";
	cout << "[program]: Calling lq: enqueue(24)\n";
	lq.enqueue(24);
	cout << "[program]: Calling lq: enqueue(1)\n";
	lq.enqueue(1);
	cout << "[program]: Calling lq: enqueue(2)\n";
	lq.enqueue(2);
	cout << "[program]: Calling lq: enqueue(3)\n";
	lq.enqueue(3);
	cout << "If you see 24, then enqueue & front are successful.\n";
	cout << "[program]: Calling lq: front()\n";
	cout << lq.front() << endl;
	cout << "If you see 3, then back is successful.\n";
	cout << "[program]: Calling lq: back()\n";
	cout << lq.back() << endl;
	cout << "[program]: Calling lq: dequeue()\n";
	lq.dequeue();
	cout << "If you see 1-3, then dequeue & display are successful.\n";
	cout << "[program]: Calling lq: display()\n";
	lq.display();
	cout << "If you see 3, then size is successful.\n";
	cout << "[program]: Calling lq: size()\n";
	cout << lq.size() << endl;

	return 0;
}
