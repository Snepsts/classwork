/* Stack.h provides a Stack class.
 *
 * Basic operations:
 *   Constructor:  Constructs an empty stack
 *   empty:   Checks if a stack is empty
 *   push:    Modifies a stack by adding a value at the top
 *   top:     Accesses the top stack value; leaves stack unchanged
 *   pop:     Modifies a stack by removing the value at the top
 *   display: Displays all the stack elements
 * Class Invariant:
 *   1. The stack elements (if any) are stored in positions
 *      0, 1, . . ., myTop of myArray.
 *   2. -1 <= myTop < STACK_CAPACITY
 ------------------------------------------------------------------*/

#include <iostream>

using namespace std;

#ifndef STACK
#define STACK

const int STACK_CAPACITY = 128;
typedef char StackElement;

class Stack
{

/***** Function Members *****/
public:
/* --- Constructor ---
 *
 * Precondition:  A stack has been declared.
 * Postcondition: The stack has been constructed as an
 *                 empty stack.
 ************************************************************/

Stack();

/* --- Is the Stack empty? ---
 * Receive: Stack containing this function (implicitly)
 * Returns: True iff the Stack containing this function is empty
 *****************************************************************/

bool empty() const;

/* --- Add a value to the stack ---
 *
 * Receive: The Stack containing this function (implicitly)
 *          A value to be added to a Stack
 * Return:  The Stack (implicitly), with value added at its
 *          top, provided there's space
 * Output:  "Stack full" message if no space for value
 *************************************************************/

void push(const StackElement & value);

/* --- Display values stored in the stack ---
 *
 * Receive: The Stack containing this function (implicitly)
 *          The ostream out
 * Output:  The Stack's contents, from top down, to out
 *************************************************************/

void display(ostream & out) const;

/* --- Return value at top of the stack ---
 *
 * Receive: The Stack containing this function (implicitly)
 * Return:  The value at the top of the Stack, if nonempty;
 *          else a "garbage value"
 * Output:  "Stack empty" message if stack is empty
 *************************************************************/

StackElement top() const;

/* --- Remove value at top of the stack ---
 *
 * Receive: The Stack containing this function (implicitly)
 * Return:  The Stack containing this function (implicitly)
 *           with its top value (if any) removed
 * Output:  "Stack-empty" message if stack is empty.
 *************************************************************/

void pop();

friend ostream & operator<<(ostream &out, const Stack & s);


/***** Data Members *****/
private:
  StackElement myArray[STACK_CAPACITY];
  int myTop;

}; // end of class declaration

//--- Definition of Class Constructor
inline Stack::Stack()
{ myTop = -1; }


//--- Definition of empty
inline bool Stack::empty() const
{ return (myTop == -1); }

#endif
