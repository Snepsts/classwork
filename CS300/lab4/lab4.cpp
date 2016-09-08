#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <functional>
#include <fstream>
#include <string>
#include "split.h"

using std::stack;
using std::priority_queue;
using std::queue;
using std::greater;
using std::less;
using std::string;
using std::vector;
using std::cout;

int main()
{
	vector<string> vst;
	stack<string> sstack;
	queue<string> squeue;
	priority_queue<string, vector<string>, greater<string>> sgpq;
	priority_queue<string, vector<string>, less<string>> slpq;
	string line;

	std::ifstream fin;
	fin.open("shortstory.txt");
	if (fin.fail())
	{
		std::cerr << "ERROR: \"shortstory.txt\" failed to open.\n";
		//exit(1);
	}

	while (getline(fin, line))
	{
		vst = csplit(line);
		for (vector<string>::iterator it = vst.begin(); it != vst.end(); it++)
		{
			sstack.push(*it);
			squeue.push(*it);
			sgpq.push(*it);
			slpq.push(*it);
		}
	}

	fin.close();

	cout << "\n\nUsing Stack:\n\n";
	while (!sstack.empty())
	{
		cout << sstack.top() << "  ";
		sstack.pop();
	}

	cout << "\n\nUsing Queue:\n\n";
	while (!squeue.empty())
	{
		cout << squeue.front() << "  ";
		squeue.pop();
	}

	cout << "\n\nUsing Greater Priority Queue:\n\n";
	while (!sgpq.empty())
	{
		cout << sgpq.top() << "  ";
		sgpq.pop();
	}

	cout << "\n\nUsing Less Priority Queue:\n\n";
	while (!slpq.empty())
	{
		cout << slpq.top() << "  ";
		slpq.pop();
	}

	cout << '\n';

	return 0;
}
