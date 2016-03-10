/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/8/16
	Data Type: Queue to store QueueType elements
*/

#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
{ //Task: Constructor
	m_front = 0; m_back = 0;
}

bool Queue::empty()
{ //Task: To check if Queue is empty
	return (m_front == m_back);
}

bool Queue::full()
{ //Task: To check if Queue is full
	return ((m_back + 1) % CAPACITY == m_front);
}

void Queue::enqueue(QueueType item)
{ //Task: To add an item to the back of the Queue
	int newBack = (m_back + 1) % CAPACITY;
	if (newBack != m_front) //queue isn't full
	{
		m_array[m_back] = item;
		m_back = newBack;
	}
	else
		cerr << "Error: Attempt to add item to the back of a full Queue.";
}

void Queue::dequeue()
{ //Task: To remove the front item of the Queue
	if (!empty())
		m_front = (m_front + 1) % CAPACITY;
	else
		cerr << "Error: Attempt to remove item from an empty Queue.";
}

QueueType Queue::front()
{ //Task: To return the front element of Queue
	return m_array[m_front];
}

QueueType Queue::back()
{ //Task: To return the back element of Queue
	return m_array[(m_back - 1 + CAPACITY) % CAPACITY];
}

int Queue::size()
{ //Task: To return the size of Queue
	return ((m_back - m_front + CAPACITY) % CAPACITY);
}

ostream& operator<<(ostream& out, Queue Q)
{ //Task: To simplify output of the Queue in main
	for (int i = Q.front(); i != Q.back(); i = ((i + 1) % CAPACITY))
		out << Q.front() << endl;

	return out;
}
