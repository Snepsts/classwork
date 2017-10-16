#include <iostream>
#include <fstream>

using namespace std;

void max_heapify(int a[], int i, int n)
{
	int l, r, largest, loc;
	l = 2 * i;
	r = (2 * i + 1);
	if ((l <= n) && a[l] > a[i])
		largest = l;
	else
		largest = i;
	if ((r <= n) && (a[r] > a[largest]))
		largest = r;
	if (largest != i)
		{
			loc = a[i];
			a[i] = a[largest];
			a[largest] = loc;
			max_heapify(a, largest, n);
		}
}

void build_max_heap(int a[], int n)
{
	for (int k = n/2; k >= 1; k--) {
			max_heapify(a, k, n);
	}
}

void heapsort(int a[], int n)
{
	build_max_heap(a, n);
	int i, temp;
	for (i = n; i >= 2; i--) {
			temp = a[i];
			a[i] = a[1];
			a[1] = temp;
			max_heapify(a, 1, i - 1);
	}
}

/*
45    32    87    2     6   99   39    76    54    19   36   12

1.     Create a balanced binary tree to the given Example.

2.     Heapify the tree

3.     Write a C++ program to perform the sort

4.     In your program, you need to add the following functions:

1.      Insert - insert an item into a heap of n elements to produce a heap with n + 1 elements.  Hint - first put the element in position n + 1.

2.      Delete - delete an element from a heap of n elements.  The element is deleted from location loc to produce a heap of n - 1 elements

3.      Search -  returns the location of an element in the heap and returns a false if the element is not in the heap.
*/

int main()
{
	ifstream fin;
	fin.open("input.txt");

	int array_size;

	fin >> array_size;

	int* array = new int[array_size];

	for (int i = 0; i < array_size; i++) {
			fin >> array[i];
	}

	heapsort(array, array_size);
	cout << "********SORTED FORM********" << endl;
	for (int i = 0; i < array_size; i++) {
			cout << array[i] << endl;
	}

	return 0;
}
