/* albino
Copyright (C) 2017 Michael Ranciglio

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>. */

/* This ADT will hold the structure for the action object AND will have the
queue responsible for handling their behavior in a "battle" setting */

#ifndef __QUEUE_H__
#define __QUEUE_H__

const int SIZE = 4; //can also be considered "CAPACITY"
                    //we shouldn't need more than 4 slots (for now)

typedef action queue_type; //incase the name changes

class queue
{
public:
	//basic constructor, initializes it to empty
	queue() { m_front = 0; m_back = 0; }

	//checks if queue is empty
	bool empty() { return (m_front == m_back); }

	//checks if queue is full
	bool full() { return ((m_back + 1) % SIZE == m_front); }

	/* function enqueue
		Task: Adding an object to the back of the queue, or in this sense an
		action that is to be carried out later. It takes 1 (one) action at a time
		and currently only takes that parameter/argument/whatever it's called.
	*/
	void enqueue(queue_type act);

	/* function dequeue
		Task: Removing the front of the queue, or in this sense to get rid of
		the action in the queue after it has been used.
		This should ONLY be called if and when the action has been carried out.
	*/
	void dequeue();

	//returns the action in the front of the queue
	queue_type front() { return m_array[m_front]; }

	//returns the action in the back of the queue
	queue_type back() { return m_array[(m_back - 1 + SIZE) % SIZE]; }

	//returns the actual size of the queue
	int size() { return ((m_back - m_front + SIZE) % SIZE); }

private:
	int m_front, m_back;
	queue_type m_array[SIZE];
};

#endif //__QUEUE_H__
