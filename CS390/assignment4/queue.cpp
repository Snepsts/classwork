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

#include "queue.h"

void queue::enqueue(queue_type act)
{
	int new_back = (m_back + 1) % SIZE;

	if (new_back != m_front) { //doesn't fill the queue
		m_array[m_back] = act;
		m_back = new_back;
	}
}

void queue::dequeue()
{
	if (!empty())
		m_front = (m_front + 1) % SIZE;
	//else
		//std::cerr << "Error: Attemp to dequeue from queue when it's already empty.\n";
}

bool queue::empty()
{
	return m_front == m_back;
}
