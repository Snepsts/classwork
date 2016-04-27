/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 4/6/16
*/

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

bool isvowel(char c);
void writeline(char c, int n);
void writeblock(char c, int n, int x);
void writebackward(string str, int n);
template <typename T>
void displayvector(const vector<T>& A, int first, int last);
int vowels(string s, int size);
bool palindrome(string s);
void reversestring(string s);

int main()
{
	char c = '*';
	int n = 5;
	int x = 3;
	vector<int> v;
	v.push_back(5); v.push_back(10); v.push_back(15); v.push_back(20); v.push_back(25);
	string pal = "allalla";
	string s = "string";
	int ssize = 6;

	writeline(c, n);
	cout << "=====\n";
	writeblock(c, n, x);
	writebackward(s, ssize);
	displayvector(v, 0, 4);
	cout << vowels(s, 0) << " " << vowels(pal, 0) << endl;
	if (palindrome(pal))
		cout << "pal is a palindrome\n";
	else
		cout << "Somehow pal is NOT a palindrome.\n";
	reversestring(s);

	return 0;
}

bool isvowel(char c)
{
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}

void writeline(char c, int n)
{
	if (n <= 0)
	{
		cout << endl; //ensure that there is a newline when the function ends
		return;
	}
	else
	{
		cout << c;
		writeline(c, n-1);
	}
}

void writeblock(char c, int n, int x)
{
	if (x <= 0)
	{
		cout << endl; //ensure that there is a newline when the function ends
		return;
	}
	else
	{
		writeline(c, n);
		writeblock(c, n, x-1);
	}
}

void writebackward(string str, int n)
{
	if (n <= 0)
	{
		cout << endl; //ensure that there is a newline when the function ends
		return;
	}
	else
	{
		cout << str[n-1];
		writebackward(str, n-1);
	}
}

template <typename T>
void displayvector(const vector<T>& A, int first, int last)
{
	if(first > last)
	{
		cout << endl; //ensure that there is a newline when the function ends
		return;
	}

	else
	{
		cout << A[first] << " ";
		displayvector(A, first+1, last);
	}
}

int vowels(string s, int size)
{
	if(s.size() <= 0)
	{
		return size;
	}

	string::iterator str = s.begin();

	if(isvowel(*str))
	{
		s.erase(str);
		return vowels(s, size+1);
	}
	else
	{
		s.erase(str);
		return vowels(s,size);
	}
}

bool palindrome(string s)
{
	if(s.size() > 1)
	{
		if(*s.begin() == *(s.end()-1))
		{
			s.erase(s.begin());
			s.erase(s.end()-1);
			return palindrome(s);
		}
		else
			return false;
	}
	else
		return true;
}

void reversestring(string s)
{
	if(s.size() <= 0)
	{
		cout << endl; //ensure that there is a newline when the function ends
		return;
	}
	cout << *(s.end()-1);
	s.erase(s.end()-1);
	return reversestring(s);
}
