/*
    tester.cpp
  Program to test class Queue.

  Input (keyboard): Commands entered by the user.
  Output (screen):  List of commands and messages describing
                    the effects of each command.
  ----------------------------------------------------------------*/
#include "Queue.h"
#include <iostream>
#include <cctype>

using namespace std;

/*--------------------------------------------------------------
  Function to list the available commands.
  Output (screen): List of commands.
----------------------------------------------------------------*/
void ShowCommands()
{
  cout << "Use the following commands to test the Queue class:\n"
       << "a --- add an element to the queue\n"
       << "d --- display contents of queue\n"
       << "e --- test whether a queue is empty\n"
       << "f --- retrieve the item at the front of the queue\n"
       << "h --- help -- print this list of commands\n"
       << "r --- remove item from front of the queue\n"
       << "s --- display the size of queue\n"
       << "b --- retrieve the item at the back of the queue\n"
       << "q --- quit testing\n";
}

int main()
{
  QueueType item;		  // item to add to the queue
  char command;           // user command (selected from menu)
  Queue q;                // The QUEUE

  ShowCommands();
  do
  {
    cout << "Command? ";
    cin >> command;
    if (isupper(command)) command = tolower(command);

    switch(command)
    {
    case 'a':
             cout << "Enter item to add to queue: ";
             cin >> item;
             q.enqueue(item);
             cout << "--> " << item << " added\n";
             break;
    case 'd':
             cout << "--> Queue contents:\n" << q << endl;
             break;

    case 'e':
             cout << "--> Queue " << (q.empty() ? "is" : "is not")
                  << " empty\n";
             break;
    case 'f':
             cout << "--> " << q.front() << " is at the front\n";
    case 'h':
             ShowCommands();
             break;
    case 'r':
             q.dequeue();
             cout << "--> Front element removed\n";
             break;
    case 's':
             cout << "--> the size of the queue is: " << q.size() << endl;
             break;
    case 'b':
             cout << "--> " << q.back() << " is at the back\n";
             break;
    case 'q':
             cout << "--> End of test\n";
             break;
    default:
             cout << "*** Illegal command: " << command << endl;
    }
  }
  while (command != 'q');

  return 0;
}
