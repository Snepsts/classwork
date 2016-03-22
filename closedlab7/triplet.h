/*
	Author: Michael Ranciglio
	Location: Southeast Missouri State University
	Class: Computer Science II (CS 265-01) (21141)
	Date: 3/22/16
	Data Type: Triplet, an object that contains 3 of the same variable of type <T>
	Operations:
		Default Constructor:
*/

#ifndef __TRIPLET_H__
#define __TRIPLET_H__

#include <iostream>
#include <string>

using namespace std;

const int SIZE = 3;

template <typename T>
class triplet
{
public:
	triplet();

	triplet(T first, T second, T third)
	{
		m_array[0] = first; m_array[1] = second; m_array[2] = third;
	}

	T getFirst()
	{
		return m_array[0];
	}

	T getSecond()
	{
		return m_array[1];
	}

	T getThird()
	{
		return m_array[2];
	}

	void setTriplet(T first, T second, T third)
	{
		m_array[0] = first; m_array[1] = second; m_array[2] = third;
	}

	T find_max();
	T find_min();
	void sort_ascending();
	void sort_descending();
	bool operator==(triplet<T> other);

	friend ostream& operator<<(ostream& out, triplet<T> t)
	{
		for (int i = 0; i < SIZE; i++)
			out << t.m_array[i] << endl;

		return out;
	}

private:
	T m_array[SIZE];
};

/* default constructor for int */
template<>
triplet<int>::triplet()
{
	m_array[0] = 0; m_array[1] = 0; m_array[2] = 0;
}

/* default constructor for string */
template<>
triplet<string>::triplet()
{
	m_array[0] = ""; m_array[1] = ""; m_array[2] = "";
}

/* function find_max
	Purpose: To find the max value in the array
	Receives: N/A
	Preconditions: Array should have different values/sizes
	Postconditions: Returns the max value/sized string */
template <typename T>
T triplet<T>::find_max()
{
	int r = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (m_array[i] >= m_array[((i + 1) % SIZE)] && m_array[i] >= m_array[((i + 2) % SIZE)])
			r = i;
	}

	return m_array[r];
}

/* function find_min
	Purpose: To find the min value in the array
	Receives: N/A
	Preconditions: Array should have different values/sizes, but not necessary
	Postconditions: Returns the min value/sized string */
template <typename T>
T triplet<T>::find_min()
{
	int r = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (m_array[i] <= m_array[((i + 1) % SIZE)] && m_array[i] <= m_array[((i + 2) % SIZE)])
			r = i;
	}

	return m_array[r];
}

/* function sort_ascending
	Purpose: To sort the array from largest in [0] to smallest in [SIZE - 1]
	Receives: N/A
	Preconditions: N/A
	Postconditions: Sorts the array from largest in [0] to smallest in [SIZE - 1] */
template <typename T>
void triplet<T>::sort_ascending()
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

/* function sort_descending
	Purpose: To sort the array from smallest in [0] to largest in [SIZE - 1]
	Receives: N/A
	Preconditions: N/A
	Postconditions: Sorts the array from smallest in [0] to largest in [SIZE - 1] */
template <typename T>
void triplet<T>::sort_descending()
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

/* overloaded == operator
	Purpose: Checks if the triplets are equal to eachother
	Receives: Another triplet object other
	Preconditions: N/A
	Postconditions: returns true if they're equal, else returns false */
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


#endif
