/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/9/16
	Data Type: Queue to store QueueType elements
*/

#include <iostream>
#include <string>
#include "inventory.h"
#include "queue.h"

using namespace std;

queue::queue()
{ //Task: Constructor
	m_front = 0; m_back = 0;
}

bool queue::empty()
{ //Task: To check if Queue is empty
	return (m_front == m_back);
}

bool queue::full()
{ //Task: To check if Queue is full
	return ((m_back + 1) % CAPACITY == m_front);
}

void queue::enqueue(QueueType item)
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

void queue::dequeue()
{ //Task: To remove the front item of the Queue
	if (!empty())
		m_front = (m_front + 1) % CAPACITY;
	else
		cerr << "Error: Attempt to remove item from an empty Queue.";
}

QueueType queue::front()
{ //Task: To return the front element of Queue
	return m_array[m_front];
}

QueueType queue::back()
{ //Task: To return the back element of Queue
	return m_array[(m_back - 1 + CAPACITY) % CAPACITY];
}

int queue::size()
{ //Task: To return the size of Queue
	return ((m_back - m_front + CAPACITY) % CAPACITY);
}

ostream& operator<<(ostream& out, const queue& Q)
{ //Task: To simplify output of the Queue in main
	int counter = 1;

	for (int i = Q.m_front; i != Q.m_back; i = ((i + 1) % CAPACITY))
	{
		out << "Showing contents from " << QUEUE_TYPE << " object number " << counter << ": \n";
		out << Q.m_array[i] << endl;
		counter++;
	}
	return out;
}
