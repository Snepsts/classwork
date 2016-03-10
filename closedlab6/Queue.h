/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/8/16
	Data Type: Queue to store QueueType elements
	Functions:
		Empty: Returns true if Queue is empty, else returns false.
		Enqueue: Adds QueueType to back of Queue.
		Dequeue: Removes front item from Queue.
		Front: Returns QueueType from the front of Queue.
		Size: Returns the number of QueueType elements in the Queue.
		Back: Returns the QueueType element at the back of the Queue.
friend	ostream& operator<<: Outputs the items in the Queue from front to back.
*/

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

using namespace std;

typedef char QueueType;

const int CAPACITY = 50;

class Queue
{
public:
	/* Default Constructor
	Purpose: To initialize the Queue at m_front = 0 & m_back = 0;
	Receives: N/A
	Preconditions: N/A
	Postconditions: Queue is constructed as empty (m_front = 0 & m_back = 0) */
	Queue();

	/* Function empty
	Purpose: To check if the Queue is empty or not
	Receives: N/A
	Preconditions: N/A
	Postconditions: Returns true if Queue is empty, else returns false */
	bool empty();

	/* Function full
	Purpose: To check if the Queue is full or NOT
	Receives: N/A
	Preconditions: N/A
	Postconditions: Returns true if Queue is full, else returns false */
	bool full();

	/* Function enqueue
	Purpose: To add element to back of queue
	Receives: QueueType item, the element to be added to the back
	Preconditions: Cannot be full
	Postconditions: item is added to back of Queue */
	void enqueue(QueueType item);

	/* Function dequeue
	Purpose: To remove the top element from the Queue
	Receives: N/A
	Preconditions: Queue cannot be empty
	Postconditions: Removes the front element */
	void dequeue();

	/* Function front
	Purpose: To return the element in front of the queue
	Receives: N/A
	Preconditions: Queue cannot be empty
	Postconditions: Front element is returned */
	QueueType front();

	/* Function size
	Purpose: To return the size of the Queue
	Receives: N/A
	Preconditions: N/A
	Postconditions: Returns the size of the Queue */
	int size();

	/* Function back
	Purpose: To return the item in the back of the Queue
	Receives: N/A
	Preconditions: Cannot be empty
	Postconditions: back item is returned */
	QueueType back();

	/* Overloaded output operator
	Purpose: To simplify the output of the Queue in main. */
	friend ostream& operator<<(ostream& out, Queue Q);

private:
	int m_front, m_back;
	QueueType m_array[CAPACITY];
};

#endif
