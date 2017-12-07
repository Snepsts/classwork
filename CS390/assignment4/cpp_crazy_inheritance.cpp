/* Design and implement a C++ program that defines a base class A, which has a
subclass B, which itself has a subclass C. The A class must implement a method,
which is overridden in both B and C. You must also write a test class that
instantiates A, B, and C and includes three calls to the method. One of the
calls must be statically bound to A’s method. One call must be dynamically bound
to B’s method, and one must be dynamically bound to C’s method. All of the
method calls must be through a pointer to class A.
*/

#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"

int main()
{
	A* a = new A;
	B* b = new B;
	C* c = new C;

	std::cout << a->get_char() << '\n';
	std::cout << b->get_char() << '\n';
	std::cout << c->get_char() << '\n';

	delete a;

	return 0;
}
