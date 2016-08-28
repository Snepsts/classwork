/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/22/16
	Data Type: Triplet, an object that contains 3 of the same variable of type <T>
*/

#include <iostream>
#include <string>
#include "triplet.h"

using namespace std;

/* function
	Purpose:
	Receives:
	Preconditions:
	Postconditions: */
template <typename T>
triplet<T>::triplet()
{
	m_array[0] = 0; m_array[1] = 0; m_array[2] = 0;
}

/* function
	Purpose:
	Receives:
	Preconditions:
	Postconditions: */
template <typename T>
triplet<T>::triplet(T first, T second, T third)
{
	m_array[0] = first; m_array[1] = second; m_array[2] = third;
}

/* function
	Purpose:
	Receives:
	Preconditions:
	Postconditions: */
template <typename T>
T triplet<T>::getFirst()
{
	return m_array[0];
}

/* function
	Purpose:
	Receives:
	Preconditions:
	Postconditions: */
template <typename T>
T triplet<T>::getSecond()
{
	return m_array[1];
}

/* function
	Purpose:
	Receives:
	Preconditions:
	Postconditions: */
template <typename T>
T triplet<T>::getThird()
{
	return m_array[2];
}

/* function
	Purpose:
	Receives:
	Preconditions:
	Postconditions: */
template <typename T>
void triplet<T>::setTriplet(T first, T second, T third)
{
	m_array[0] = first; m_array[1] = second; m_array[2] = third;
}

/* function
	Purpose:
	Receives:
	Preconditions:
	Postconditions: */
template <typename T>
T triplet<T>::find_max()
{
	int r = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (m_array[i] >= m_array[((i + 1) % SIZE)] && m_array[i] >= m_array[((i + 2) % SIZE)])
			r = i;
	}

	return m_array[i];
}

/* function
	Purpose:
	Receives:
	Preconditions:
	Postconditions: */
template <typename T>
T triplet<T>::find_min()
{
	int r = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (m_array[i] <= m_array[((i + 1) % SIZE)] && m_array[i] <= m_array[((i + 2) % SIZE)])
			r = i;
	}

	return m_array[i];
}

/* function
	Purpose:
	Receives:
	Preconditions:
	Postconditions: */
template <typename T>
void triplet<T>::sort_ascending()
{
	T temp;

	for (int i = 0; i < SIZE; i++)
	{
		for (int a = 0; a < SIZE; a++)
		{
			if (m_array[i] < m_array[a])
			{
				temp = m_array[a];
				m_array[a] = m_array[i];
				m_array[i] = temp;
			}
		}
	}
}

/* function
	Purpose:
	Receives:
	Preconditions:
	Postconditions: */
template <typename T>
void triplet<T>::sort_descending()
{
	T temp;

	for (int i = 0; i < SIZE; i++)
	{
		for (int a = 0; a < SIZE; a++)
		{
			if (m_array[i] > m_array[a])
			{
				temp = m_array[a];
				m_array[a] = m_array[i];
				m_array[i] = temp;
			}
		}
	}
}

/* function
	Purpose:
	Receives:
	Preconditions:
	Postconditions: */
template <typename T>
bool triplet<T>::operator==(triplet<T> other)
{
	bool r = true;
	for (int i = 0; i < SIZE; i++)
	{
		if (m_array[i] != other.m_array[i])
		{
			r = false;
		}
	}

	return r;
}
