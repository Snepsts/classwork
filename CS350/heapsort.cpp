#include <iostream>
#include <fstream>
#include <map>
#include "bst.h"

using namespace std;

int main()
{
	BST t;

	ifstream fin;
	fin.open("set_of_numbers.txt");

	int array_size;
	fin >> array_size;
	int* array = new int[array_size];

	for (int i = 0; i < array_size; i++) {
		fin >> array[i];
		t.insert(array[i]);
		cout << "INSERTING " << array[i] << '\n';
	}

	t.display();
	t.heapify();

	map<int, int> m = t.get_heap();

	int i, j;
	for (i = array_size; i > 1; i--) {
		cout << "Running\n";
		map<int, int> m = t.get_heap();
		cout << "Running 2.0\n";
		for (j = 0; j < i; j++) {
			array[j] = m[j];
		}
		cout << "Running 3.0\n";

		cout << "Swapping " << array[0] << " with " << array[i-1] << '\n';
		int temp = array[0];
		array[0] = array[i-1];
		array[i-1] = temp;
		cout << "Running 4.0\n";
		cout << "Deleting " << temp << " from ";
		//cout << "i: " << i << " j: " << j << '\n';
		t.display();
		t.remove_heap();
		cout << "Running 5.0\n";
		cout << "i: " << i << " j: " << j << '\n';
		t.heapify();
		cout << "Running 6.0\n";
		t.display();
		t.display();
		t.display();

		for (int index = 0; index < array_size; index++) {
			cout << array[index] << ' ';
		}
		cout << '\n';
		t.setHeight();
	}
	cout << "Complete\n";

	for (int i = 0; i < array_size; i++) {
		cout << array[i] << " ";
	}
	cout << '\n';

	return 0;
}
