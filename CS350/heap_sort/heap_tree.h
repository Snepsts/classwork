#ifndef __HEAP_TREE_H__
#define __HEAP_TREE_H__

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
struct node
{
	node() { right = NULL; left = NULL; }
	node(T val) { data = val; right = NULL; left = NULL; }
	node(T val, node<T>* left, node<T>* right) { data = val; left = left; right = right; }
	bool is_heap()
	{
		bool retvar = true;

		if (right && right->data > data)
			retvar = false;

		if (left && left->data > data)
			retvar = false;

		return retvar;
	}

	void swap_right()
	{
		T temp; //for swapping data
		temp = right->data;
		right->data = data;
		data = temp;
	}

	void swap_left()
	{
		T temp; //for swapping data
		temp = left->data;
		left->data = data;
		data = temp;
	}

	void sift()
	{
		if (!left) {//if there is no left, upsift right
			swap_right();
		} else if (!right) { //if there is no right, upsift left
			swap_left();
		} else if (right->data > data && left->data > data) {
			if (right->data > left->data) { //swap right
				swap_right();
			} else { //swap left
				swap_left();
			}
		} else if (right->data > data) {
			swap_right();
		} else if (left->data > data) {
			swap_left();
		} else {
			//do nothing
		}
	}

	T data;
	node<T>* right;
	node<T>* left;
};

template <typename T>
class heap_tree
{
public:
	heap_tree() { root = NULL; members = 0; }
	heap_tree(node<T>* n_root) { root = n_root; members = 1; }
	~heap_tree();
	int get_size() { return members; }
	T* get_array();
	bool add(node<T>* next_node);
	bool add(T next_item);
	void balance();
	void print();
	void print_iterative();
	void heapify();
	bool is_heap();
	heap_tree<T> balance_tree();
private:
	void split(int array[], heap_tree<T> balanced, int start, int mid, int end);
	bool add_private(node<T>* comp, T item);
	void print_private(node<T>* item);
	void private_heapify(node<T>* heap_node);
	void remove(node<T>* nodeptr);

	node<T>* root;
	int members;
};

template <typename T>
heap_tree<T>::~heap_tree()
{
	remove(root);
}

template <typename T>
void heap_tree<T>::remove(node<T>* nodeptr)
{
	if (!nodeptr) {

	} else {
		remove(nodeptr->left);
		delete nodeptr;
		remove(nodeptr->right);
	}
}

//for adding with a node pointer
template <typename T>
bool heap_tree<T>::add(node<T>* item)
{
	if (add_private(item)) {
		members++;
		return true;
	} else {
		return false;
	}
}

//for adding a plain item
template <typename T>
bool heap_tree<T>::add(T next_item)
{
	if (!root) {
		root = new node<T>(next_item);
		members++;
		return true;
	} else if (add_private(root, next_item)) {
		members++;
		return true;
	} else {
		return false;
	}
}

//assumes tree has not been heapified yet
template <typename T>
heap_tree<T> heap_tree<T>::balance_tree()
{
	int* array = new int[members];
	int i = 0;
	bool is_done = false;
	stack<node<T>*> s;
	node<T>* curr = root;

	while (!is_done) {
		if (curr) {//if it exists
			array[i] = curr->data;
			i++;
			s.push(curr);
			curr = curr->left;
		} else if (!s.empty()) {
			node<T>* temp = s.top();
			s.pop();
			curr = temp->right;
		} else if (s.empty()) {
			is_done = true;
		}
	} //now we have our array from least to most

	/*
	[1] [3] [6] [8] [9] [12] [19]
	             8
	         3       12
	      1     6  9    19
	*/

	int start = 0;
	int end = i;
	int mid = (end + 1) / 2;
	heap_tree balanced;
	split(array, balanced, start, mid, end);

	delete[] array;

	return balanced;
}

template <typename T>
T* heap_tree<T>::get_array()
{
	T* array = new T[members];
	int i = 0;
	bool is_done = false;
	stack<node<T>*> s;
	node<T>* curr = root;

	while (!is_done) {
		cout << "i = " << i << '\n';
		if (curr) {//if it exists
			array[i] = curr->data;
			i++;
			s.push(curr);
			curr = curr->left;
		} else if (!s.empty()) {
			node<T>* temp = s.top();
			s.pop();
			curr = temp->right;
		} else if (s.empty()) {
			is_done = true;
		}
	} //now we have our array from least to most

	return array;
}

template <typename T>
void heap_tree<T>::split(int array[], heap_tree<T> bst, int start, int mid, int end)
{
	if (start == mid && end == mid)
		bst.add(array[mid]);
	else {
		bst.add(array[mid]);
		split(array, bst, start, (start+mid/2), mid);
		split(array, bst, mid, (mid+end)/2, end);
	}
}

template <typename T>
void heap_tree<T>::print()
{
	print_private(root);
}

template <typename T>
bool heap_tree<T>::add_private(node<T>* comp, T item)
{
	if (comp->data > item) {
		if (!comp->left) {
			comp->left = new node<T>(item);
			return true;
		} else {
			return add_private(comp->left, item);
		}
	} else if (comp->data < item) {
		if (!comp->right) {
			comp->right = new node<T>(item);
			return true;
		} else {
			return add_private(comp->right, item);
		}
	} else {
		return false;
	}
}

template <typename T>
void heap_tree<T>::print_private(node<T>* item) {
	if (!item) {
		//nothing
	} else {
		print_private(item->left);
		cout << item->data << ' ';
		print_private(item->right);
	}
}

/*
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.
*/

template <typename T>
bool heap_tree<T>::is_heap()
{
	bool is_done = false;
	stack<node<T>*> s;
	node<T>* curr = root;

	while (!is_done) {
		if (curr) {//if it exists
			if (!curr->is_heap()) //if it's not a heap
				return false;
			s.push(curr);
			curr = curr->left;
		} else if (!s.empty()) {
			node<T>* temp = s.top();
			s.pop();
			curr = temp->right;
		} else if (s.empty()) {
			is_done = true;
		}
	}

	return true;
}

template <typename T>
void heap_tree<T>::heapify()
{
	while (!is_heap()) {
		private_heapify(root);
	}
}

template <typename T>
void heap_tree<T>::private_heapify(node<T>* heap_node)
{
	cout << "private_heapify\n";
	if (!heap_node) {
		//do nothing
	} else {
		private_heapify(heap_node->left);
		if (!heap_node->is_heap())
			heap_node->sift();
		private_heapify(heap_node->right);
	}
}

template <typename T>
void heap_tree<T>::print_iterative()
{
	bool is_done = false;
	stack<node<T>*> s;
	node<T>* curr = root;

	while (!is_done) {
		if (curr) {//if it exists
			cout << curr->data << ' ';
			s.push(curr);
			curr = curr->left;
		} else if (!s.empty()) {
			node<T>* temp = s.top();
			s.pop();
			curr = temp->right;
		} else if (s.empty()) {
			is_done = true;
		}
	}
}

#endif //__HEAP_TREE_H__
