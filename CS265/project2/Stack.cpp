/* Stack.cpp -- implementation file for Stack.h */

#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

//--- Definition of push()
void Stack::push(const StackElement & value)
{
  if (myTop < STACK_CAPACITY - 1)  // Preserve stack invariant
  {
    ++myTop;
    myArray[myTop] = value;
  }                      // or simply, myArray[++myTop] = value;
  else
    cerr << "*** Stack is full -- can't add new value ***\n"
         << "Must increase value of STACK_CAPACITY in Stack.h\n";
}

//--- Definition of display()
void Stack::display(ostream & out) const
{
  for (int i = myTop; i >= 0; i--)
    out << myArray[i];
}

//--- Definition of top()

StackElement Stack::top() const
{
  if (myTop >= 0)
    return myArray[myTop];
  cerr << "*** Stack is empty ***\n";
}

//--- Definition of pop()
void Stack::pop()
{
  if (myTop >= 0)    // Preserve stack invariant
    myTop--;
  else
    cerr << "*** Stack is empty -- can't remove a value ***\n";
}

ostream & operator<<(ostream & out, const Stack & s)
{
	s.display(out);
	return out;
}
