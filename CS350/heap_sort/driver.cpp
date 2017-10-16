#include <iostream>
#include "heap_tree.h"

using namespace std;

template <typename T>
void balance_tree(heap_tree<T> ht);

int main()
{
	heap_tree<int> bst;

	bst.add(5);
	bst.add(9);
	bst.add(4);
	bst.add(23);
	bst.add(14);
	bst.add(2);

	/*
	if (bst.is_heap())
		cout << "It is a heap!!!\n";
	else
		cout << "It is NOT a heap!!!\n";
	*/

	//bst = bst.balance_tree();

	//bst.heapify();

	balance_tree(bst);

	bst.print();

	return 0;
}

//assumes tree has not been heapified yet
template <typename T>
void balance_tree(heap_tree<T> ht)
{
	//T* array = new T[ht.get_size()];
	T* array = ht.get_array();
	int i = 0;

}
