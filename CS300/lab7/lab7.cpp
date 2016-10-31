/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
Date: 9/26/16 */

#include <iostream>
#include "math_set.h"

using std::cout;

int main(){
	//Start of int set test
	const int MAX = 12;
	set<int> a, b, c, d, u, i, m, sd, uo, io, mo, sdo;

	for(int i = 1; i < MAX; i++)
		a.insert(i); //fill a with 1 thru 11
	for(int i = 0; i <= MAX; i+=2)
		b.insert(i); //fill b with 0 thru 12 excluding odd numbers
	for(int i = 1; i < MAX; i++)
		c.insert(i); //fill c with 1 thru 11 (for testing subset/true subset)
	for(int i = 1; i < MAX-1; i++)
		d.insert(i); //fill d with 1 thru 10 (for testing subset/true subset)

	u = Union(a, b);
	i = Intersection(a, b);
	m = Minus(a, b);
	sd = Symdif(a, b);

	uo = a + b;
	io = a * b;
	mo = a - b;
	sdo = a ^ b;

	cout << "Union output:\n";
	for (auto x : u)
		cout << x << " ";
	cout << '\n';

	cout << "Intersection output:\n";
	for (auto x : i)
		cout << x << " ";
	cout << '\n';

	cout << "Minus output:\n";
	for (auto x : m)
		cout << x << " ";
	cout << '\n';

	cout << "Symdif output:\n";
	for (auto x : sd)
		cout << x << " ";
	cout << '\n';

	cout << '\n';

	cout << "Union \"+ operator\" output:\n";
	for (auto x : uo)
		cout << x << " ";
	cout << '\n';

	cout << "Intersection \"* operator\" output:\n";
	for (auto x : io)
		cout << x << " ";
	cout << '\n';

	cout << "Minus \"- operator\" output:\n";
	for (auto x : mo)
		cout << x << " ";
	cout << '\n';

	cout << "Symdif \"^ operator\" output:\n";
	for (auto x : sdo)
		cout << x << " ";
	cout << "\n\n";

	if(Subset(a, c))
		cout << "c is a subset of a\n";
	else
		cout << "c is NOT a subset of a\n";

	if(Subset(a, d))
		cout << "d is a subset of a\n";
	else
		cout << "d is NOT a subset of a\n";

	if(ProperSubset(a, c))
		cout << "c is a proper subset of a\n";
	else
		cout << "c is NOT a proper subset of a\n";

	if(ProperSubset(a, d))
		cout << "d is a proper subset of a\n";
	else
		cout << "d is NOT a proper subset of a\n";

	cout << '\n';

	if(In(a, 1))
		cout << "1 is in a\n";
	else
		cout << "1 is NOT in a\n";

	if(a % 0)
		cout << "0 is in a\n";
	else
		cout << "0 is NOT in a\n";
	//end of int set test
	//start of string set test
	set<std::string> as{"stuff", "more stuff", "some more stuff", "moremore stuff", "most stuff"};
	set<std::string> bs{"stuff", "other stuff", "some stuff", "some other stuff", "more stuff"};
	set<std::string> cs{"stuff", "more stuff", "some more stuff", "moremore stuff", "most stuff"};
	set<std::string> ds{"stuff", "more stuff", "some more stuff", "moremore stuff"};
	set<std::string> us, is, ms, sds, uos, ios, mos, sdos;

	us = Union(as, bs);
	is = Intersection(as, bs);
	ms = Minus(as, bs);
	sds = Symdif(as, bs);

	uos = as + bs;
	ios = as * bs;
	mos = as - bs;
	sdos = as ^ bs;

	cout << "Union output:\n";
	for (auto x : us)
		cout << x << ", ";
	cout << '\n';

	cout << "Intersection output:\n";
	for (auto x : is)
		cout << x << ", ";
	cout << '\n';

	cout << "Minus output:\n";
	for (auto x : ms)
		cout << x << ", ";
	cout << '\n';

	cout << "Symdif output:\n";
	for (auto x : sds)
		cout << x << ", ";
	cout << '\n';

	cout << '\n';

	cout << "Union \"+ operator\" output:\n";
	for (auto x : uos)
		cout << x << ", ";
	cout << '\n';

	cout << "Intersection \"* operator\" output:\n";
	for (auto x : ios)
		cout << x << ", ";
	cout << '\n';

	cout << "Minus \"- operator\" output:\n";
	for (auto x : mos)
		cout << x << ", ";
	cout << '\n';

	cout << "Symdif \"^ operator\" output:\n";
	for (auto x : sdos)
		cout << x << ", ";
	cout << "\n\n";

	if(Subset(as, cs))
		cout << "cs is a subset of as\n";
	else
		cout << "cs is NOT a subset of as\n";

	if(Subset(as, ds))
		cout << "ds is a subset of as\n";
	else
		cout << "ds is NOT a subset of as\n";

	if(ProperSubset(as, cs))
		cout << "cs is a proper subset of as\n";
	else
		cout << "cs is NOT a proper subset of as\n";

	if(ProperSubset(as, ds))
		cout << "ds is a proper subset of as\n";
	else
		cout << "ds is NOT a proper subset of as\n";

	cout << '\n';

	std::string stuff = "stuff", other_stuff = "other stuff";

	if(In(as, stuff))
		cout << "\"stuff\" is in as\n";
	else
		cout << "\"stuff\" is NOT in as\n";

	if(as % other_stuff)
		cout << "\"other stuff\" is in as\n";
	else
		cout << "\"other stuff\" is NOT in as\n";
	//end of string set test

	return 0;
}

/* Output:
Union output:
0 1 2 3 4 5 6 7 8 9 10 11 12
Intersection output:
2 4 6 8 10
Minus output:
1 3 5 7 9 11
Symdif output:
0 1 3 5 7 9 11 12

Union "+ operator" output:
0 1 2 3 4 5 6 7 8 9 10 11 12
Intersection "* operator" output:
2 4 6 8 10
Minus "- operator" output:
1 3 5 7 9 11
Symdif "^ operator" output:
0 1 3 5 7 9 11 12

c is a subset of a
d is a subset of a
c is NOT a proper subset of a
d is a proper subset of a

1 is in a
0 is NOT in a
Union output:
more stuff, moremore stuff, most stuff, other stuff, some more stuff, some other stuff, some stuff, stuff,
Intersection output:
more stuff, stuff,
Minus output:
moremore stuff, most stuff, some more stuff,
Symdif output:
moremore stuff, most stuff, other stuff, some more stuff, some other stuff, some stuff,

Union "+ operator" output:
more stuff, moremore stuff, most stuff, other stuff, some more stuff, some other stuff, some stuff, stuff,
Intersection "* operator" output:
more stuff, stuff,
Minus "- operator" output:
moremore stuff, most stuff, some more stuff,
Symdif "^ operator" output:
moremore stuff, most stuff, other stuff, some more stuff, some other stuff, some stuff,

cs is a subset of as
ds is a subset of as
cs is NOT a proper subset of as
ds is a proper subset of as

"stuff" is in as
"other stuff" is NOT in as
*/
